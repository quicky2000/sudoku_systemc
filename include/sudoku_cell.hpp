/*
  This file is part of sudoku_systemc
  Copyright (C) 2012  Julien Thevenon ( julien_thevenon at yahoo.fr )

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::delete_message(const sudoku_message_base<SIZE>* p_message)
{
  delete p_message;
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
sudoku_cell<SIZE,MAX_NB_STATE>::sudoku_cell(sc_module_name name, 
					    const to_string_if & p_whole,
					    const uint32_t & p_x,
					    const uint32_t & p_y,
					    const uint32_t p_init_value):
  sc_module(name),
  m_clk("clk"),
  m_input_port("input_port"),
  m_output_port("output_port"),
  m_whole(p_whole),
  m_x(p_x),
  m_y(p_y),
  m_id(p_x + p_y *SIZE *SIZE),
  m_vertical_group((p_x /SIZE) % SIZE),
  m_vertical_sub_group(p_x % SIZE),
  m_horizontal_group((p_y /SIZE) % SIZE),
  m_horizontal_sub_group(p_y % SIZE),
  m_activity_counter(1 + SIZE * SIZE * SIZE * SIZE),
  m_message_to_forward(nullptr),
  m_general_hypothesis_level(0),
  m_nb_state(0)
{
  print_name();
  std::cout << "Creation" << std::endl ;

  SC_METHOD(listen_input_port);
  sensitive << m_clk.pos();
  dont_initialize();
    
  SC_THREAD(manage_output_port);
  sensitive << m_clk.pos();
  dont_initialize();
        
  SC_THREAD(run);
  sensitive << m_clk.pos();

  m_internal_states[0] = new sudoku_internal_state<SIZE>(m_vertical_sub_group,m_horizontal_sub_group,p_init_value);
  for(unsigned int l_index = 1; l_index < SIZE ; ++l_index)
    {
      m_internal_states[l_index] = nullptr;
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
const typename sudoku_types<SIZE>::t_data_type & sudoku_cell<SIZE,MAX_NB_STATE>::get_value(void)const
{
  return m_internal_states[m_nb_state]->get_value();
}
//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
bool sudoku_cell<SIZE,MAX_NB_STATE>::is_value_set(void)const
{
  return m_internal_states[m_nb_state]->is_value_set();
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::print_name(void)
{
  std::cout << "Cell[" 
	    << m_vertical_group << "," 
	    << m_vertical_sub_group << "][" 
	    << m_horizontal_group << "," 
	    << m_horizontal_sub_group << "] \""
	    << name() << "\" Id=" << m_id << " @ " << sc_time_stamp() << ": ";
}
  
//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
bool sudoku_cell<SIZE,MAX_NB_STATE>::is_mine(const sudoku_message_base<SIZE> * const p_message)const
{
  bool l_same_column = p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group;
  if(!l_same_column) return false;
  return p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group;
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
bool sudoku_cell<SIZE,MAX_NB_STATE>::less_than_position(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group1,
							const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group1,
							const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group1,
							const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group1,
							const typename sudoku_types<SIZE>::t_group_type & p_vertical_group2,
							const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group2,
							const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group2,
							const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group2)
{
  if(p_vertical_group1.to_uint() < p_vertical_group2.to_uint())
    {
      return true;
    }
  else if(p_vertical_group1.to_uint() > p_vertical_group2.to_uint())
    {
      return false;
    }
  else if(p_vertical_sub_group1.to_uint() < p_vertical_sub_group2.to_uint())
    {
      return true;
    }
  else if(p_vertical_sub_group1.to_uint() > p_vertical_sub_group2.to_uint())
    {
      return false;
    }
  if(p_horizontal_group1.to_uint() < p_horizontal_group2.to_uint())
    {
      return true;
    }
  else if(p_horizontal_group1.to_uint() > p_horizontal_group2.to_uint())
    {
      return false;
    }
  else if(p_horizontal_sub_group1.to_uint() < p_horizontal_sub_group2.to_uint())
    {
      return true;
    }
  else if(p_horizontal_sub_group1.to_uint() > p_horizontal_sub_group2.to_uint())
    {
      return false;
    }
  else
    {
      return false;
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat_common(const sudoku_message_base<SIZE>* p_message)
{
  if(p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group)
    {
      m_internal_states[m_nb_state]->remove_vertical_candidate(p_message->get_data());
    }
  if(p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group)
    {
      m_internal_states[m_nb_state]->remove_horizontal_candidate(p_message->get_data());
    }
  if(p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group)
    {
      m_internal_states[m_nb_state]->remove_square_candidate(p_message->get_data());
    }
  if(m_FSM_state.is_check_sent())
    {
      print_name();
      std::cout << "Discard CHECK I have sent" << std::endl ;
      m_FSM_state.invalid_check();
    }
}
//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_set_value<SIZE>* p_message)
{
  if(!m_FSM_state.is_invalid_state())
    {
      if(!is_mine(p_message))
	{
	  if(!m_internal_states[m_nb_state]->is_value_set())
	    {
	      if((p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group) ||
		 (p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group) || 
		 (p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group))
		{
		  m_internal_states[m_nb_state]->remove_available_value(p_message->get_data());
		}
	      treat_common(p_message);
	      m_message_to_forward = p_message;
	      m_FSM_state.hypothesis_sent(false);
	    }
	  else if((p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group) ||
		  (p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group) || 
		  (p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group))
	    {
	      if(p_message->get_data() != m_internal_states[m_nb_state]->get_value())
		{
		  m_message_to_forward = p_message;
		  m_FSM_state.hypothesis_sent(false);
		}
	      else
		{
		  m_FSM_state.set_invalid_state(true);
		  print_name();
		  std::cout << "Detect incoherency : I already have value " << m_internal_states[m_nb_state]->get_real_value(m_internal_states[m_nb_state]->get_value()) << std::endl ;
		  std::cout << m_whole.to_string();
		  std::cout << "Delete invalid message" << std::endl ;
		  delete_message(p_message);
		  //			assert(false);
		  //			sc_stop();
		}
	    }
	  else
	    {
	      m_message_to_forward = p_message;
	      m_FSM_state.hypothesis_sent(false);
	    }

	  m_FSM_state.hypothesis_sent(false);
	}
      else
	{
	  std::cout << "Delete my own SET_VALUE message" << std::endl ;
	  delete_message(p_message);
	}
    }
  else
    {
      print_name();
      std::cout << "Delete message due to INVALID_STATE" << std::endl ;
      delete_message(p_message);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_check<SIZE>* p_message)
{
  if(!m_FSM_state.is_invalid_state())
    {
      if(!is_mine(p_message))
	{
	  // Forwarding of check message is mandatory but I must invalidate it if I`m not in hypothesis mode
	  if((!m_internal_states[m_nb_state]->is_value_set() || !m_FSM_state.is_value_sent() ) && 
	     m_internal_states[m_nb_state]->get_values_to_release().to_uint() > 0)
	    {
	      print_name();
	      std::cout << "Invalidate received check message" << std::endl ;
	      m_message_to_forward = new sudoku_message_check<SIZE>(p_message->get_vertical_group(),
								    p_message->get_vertical_sub_group(),
								    p_message->get_horizontal_group(),
								    p_message->get_horizontal_sub_group(),
								    p_message->get_data() & 0x0
								    );
	      delete p_message;
	    }
	  else
	    {
	      m_message_to_forward = p_message;
	    }
	}
      else // This is my check message. Test if its content is still valid and if it has not been invalidated by myself
	{
	  if(p_message->is_valid() && m_FSM_state.is_check_valid())
	    {
	      print_name();
	      std::cout << "Check granted !!" << std::endl ;
	      m_FSM_state.set_check_granted();
	    }
	  else
	    {
	      print_name();
	      std::cout << "Hypothesis discarded by CHECK process" << std::endl ;
	      m_FSM_state.set_hypothesis_accepted(false);
	      m_FSM_state.set_hypothesis_returned(false);
	    }
	  m_FSM_state.hypothesis_sent(false);
	  m_FSM_state.set_check_sent(false);
	  std::cout << "Delete my own CHECK message" << std::endl ;
	  delete_message(p_message);
	}
    }
  else
    {
      print_name();
      std::cout << "Delete message due to INVALID_STATE" << std::endl ;
      delete_message(p_message);
    }
	
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_release_value<SIZE>* p_message)
{
  if(!m_FSM_state.is_invalid_state())
    {
      if(!is_mine(p_message))
	{
	  if(!m_internal_states[m_nb_state]->is_value_set())
	    {
	      treat_common(p_message);
	      m_FSM_state.hypothesis_sent(false);
	    }
	  m_message_to_forward = p_message;
	}
      else
	{
	  std::cout << "Delete my own RELEASE_VALUE message" << std::endl ;
	  delete_message(p_message);
	}
    }
  else
    {
      print_name();
      std::cout << "Delete message due to INVALID_STATE" << std::endl ;
      delete_message(p_message);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_req_hypothesis<SIZE>* p_message)
{
  if(!m_FSM_state.is_invalid_state())
    {
      if(is_mine(p_message))
	{
	  if(!m_internal_states[m_nb_state]->is_value_set() && 
	     !m_FSM_state.is_hypothesis_accepted())
	    {
	      if(m_FSM_state.is_check_granted())
		{
		  print_name();
		  std::cout << "Hypothesis accepted !" << std::endl ;
		  m_FSM_state.set_hypothesis_accepted(true);
		}
	      else
		{
		  print_name();
		  std::cout << "Hypothsis returned" << std::endl ;
		  m_FSM_state.set_hypothesis_returned(true);
		}
	    }
	}
      else if(m_internal_states[m_nb_state]->is_value_set())
	{
	  m_message_to_forward = p_message;
	}
      else if(m_FSM_state.is_hypothesis_sent())
	{
	  if(m_internal_states[m_nb_state]->get_nb_available_values().to_uint() >= p_message->get_data().to_uint()+1)
	    {
	      if(m_internal_states[m_nb_state]->get_nb_available_values().to_uint() > p_message->get_data().to_uint()+1)
		{
		  print_name();
		  std::cout << "Forward stronger hypothesis request : " << m_internal_states[m_nb_state]->get_nb_available_values().to_uint() << " > " << p_message->get_data().to_uint()+1 << std::endl ;
		  m_message_to_forward = p_message;
		}
	      else if(less_than_position(p_message->get_vertical_group(),p_message->get_vertical_sub_group(),p_message->get_horizontal_group(),p_message->get_horizontal_sub_group(),
					 m_vertical_group,m_vertical_sub_group,m_horizontal_group,m_horizontal_sub_group))
		{
		  print_name();
		  std::cout << "Forward higher position priority request" << std::endl ;
		  m_message_to_forward = p_message;
		}
	      else
		{
		  print_name();
		  std::cout << "Discard hypothesis due to lower position priority" << std::endl ;
		  m_FSM_state.hypothesis_sent(false);
		}
	    }
	  else
	    {
	      print_name();
	      std::cout << "Discard weak hypothesis request : " << m_internal_states[m_nb_state]->get_nb_available_values().to_uint() << " < " << p_message->get_data().to_uint()+1 << std::endl ;
	      m_FSM_state.hypothesis_sent(false);
	    }
	}
      else
	{
	  print_name();
	  std::cout << "Discard prematured hypothesis request" << std::endl ;
	}
      if(m_message_to_forward != p_message)
	{
	  print_name();
	  std::cout << "Delete REQ_HYPOTHESIS message" << std::endl ;
	  general_monitor::get_unique_instance()->pop_hypothesis(SIZE * p_message->get_vertical_group().to_uint() + p_message->get_vertical_sub_group().to_uint(),
								 SIZE * p_message->get_horizontal_group().to_uint() + p_message->get_horizontal_sub_group().to_uint(),
								 p_message->get_data().to_uint()+1);
	  delete_message(p_message);
	}
    }
  else
    {
      print_name();
      std::cout << "Delete message due to INVALID_STATE" << std::endl ;
      delete_message(p_message);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_set_hyp_level<SIZE> * p_message)
{
  if(!m_FSM_state.is_invalid_state())
    {
      ++m_general_hypothesis_level;
      if(!m_internal_states[m_nb_state]->is_value_set())
	{
	  if(!is_mine(p_message))
	    {
	      m_message_to_forward = p_message;
	      //TO RESTABLISH		    if(m_internal_states[m_nb_state]->is_modified())
	      //TO RESTABLISH		      {
	      ++m_nb_state;
	      assert(m_nb_state < MAX_NB_STATE);
	      m_internal_states[m_nb_state] = new sudoku_internal_state<SIZE>(*(m_internal_states[m_nb_state - 1]),m_general_hypothesis_level);
	      //TO RESTABLISH		      }
	    }
	  else
	    {
	      typename sudoku_types<SIZE>::t_data_type l_hypothesis = m_internal_states[m_nb_state]->make_hypothesis();
	      m_FSM_state.reset();
	      print_name();
	      std::cout << "New Hypothesis level has been set" << std::endl ;
	      std::cout << "Make hypothesis with value " <<  m_internal_states[m_nb_state]->get_real_value(l_hypothesis) << std::endl ;
	      ++m_nb_state;
	      assert(m_nb_state < MAX_NB_STATE);
	      m_internal_states[m_nb_state] = new sudoku_internal_state<SIZE>(*(m_internal_states[m_nb_state - 1]),m_general_hypothesis_level);
	      m_internal_states[m_nb_state]->set_value(l_hypothesis);
	      m_internal_states[m_nb_state - 1]->remove_available_value(l_hypothesis);
	      std::cout << m_whole.to_string();
	      //		exit(-1);
	    }
	  print_name();
	  std::cout << "Switching to new hypothesis level " << m_general_hypothesis_level << std::endl ;
	}
      else
	{
	  m_message_to_forward = p_message;
	}
      if(m_message_to_forward != p_message)
	{
	  print_name();
	  std::cout << "Delete SET_HYP_LEVEL message" << std::endl ;
	  delete_message(p_message);
	}
    }
  else
    {
      print_name();
      std::cout << "Delete message due to INVALID_STATE" << std::endl ;
      delete_message(p_message);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::treat(const sudoku_message_invalid_state<SIZE>* p_message)
{
  if(!is_mine(p_message))
    {
      m_message_to_forward = p_message;
    }
  else
    {
      print_name();
      std::cout << "Receive my own invalid_state message" << std::endl ;
      m_FSM_state.set_invalid_state(false);
      m_FSM_state.invalid_sent(false);
    }
  if(m_internal_states[m_nb_state]->get_hypothesis_level() == m_general_hypothesis_level)
    {
      print_name();
      std::cout << "Restore previous internal state" << std::endl ;
      assert(m_nb_state);
      delete m_internal_states[m_nb_state];
      --m_nb_state;
      m_FSM_state.reset();
      std::cout << m_whole.to_string();
    }
  --m_general_hypothesis_level;
  if(m_message_to_forward != p_message)
    {
      print_name();
      std::cout << "Delete INVALID_STATE message" << std::endl ;
      delete_message(p_message);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
const sudoku_message_base<SIZE> * const sudoku_cell<SIZE,MAX_NB_STATE>::generate_message_to_send(void)
{
  const sudoku_message_base<SIZE> * l_message = nullptr;

  if(m_message_to_forward != nullptr)
    {
      print_name();
      std::cout << "Forward message" << std::endl ;
      l_message = m_message_to_forward;
      m_message_to_forward = nullptr;
    }
  else if(m_FSM_state.is_invalid_state())
    {
      if(!m_FSM_state.is_invalid_sent())
	{	      
	  print_name();
	  std::cout << "Send Invalid state" << std::endl ;
	  l_message = new sudoku_message_invalid_state<SIZE>(m_vertical_group,
							     m_vertical_sub_group,
							     m_horizontal_group,
							     m_horizontal_sub_group,
							     0
							     );
	  m_FSM_state.invalid_sent(true);
	}
    }
  else if(m_internal_states[m_nb_state]->is_value_set() && 
	  !m_FSM_state.is_value_sent())
    {
      print_name();
      std::cout << "Send set value" << std::endl ;
      l_message = new sudoku_message_set_value<SIZE>(m_vertical_group,
						     m_vertical_sub_group,
						     m_horizontal_group,
						     m_horizontal_sub_group,
						     m_internal_states[m_nb_state]->get_value()
						     );
      m_FSM_state.value_sent(true);
    }
  else if(m_internal_states[m_nb_state]->get_values_to_release().to_uint() > 0)
    {
      print_name();
      std::cout << "Send Release value" << std::endl ;
      l_message = new sudoku_message_release_value<SIZE>(m_vertical_group,
							 m_vertical_sub_group,
							 m_horizontal_group,
							 m_horizontal_sub_group,
							 m_internal_states[m_nb_state]->get_remaining_value()
							 );
    }
  else if(!m_internal_states[m_nb_state]->is_value_set() && 
	  !m_FSM_state.is_hypothesis_sent() && 
	  m_internal_states[m_nb_state]->get_nb_available_values() != sudoku_configuration<SIZE>::m_nb_value && 
	  !m_FSM_state.is_check_sent())
    {
      // Request for hypothesis
      l_message = new sudoku_message_req_hypothesis<SIZE>(m_vertical_group,
							  m_vertical_sub_group,
							  m_horizontal_group,
							  m_horizontal_sub_group,
							  m_internal_states[m_nb_state]->get_nb_available_values().to_uint()-1
							  );
      general_monitor::get_unique_instance()->push_hypothesis(m_x,m_y,m_internal_states[m_nb_state]->get_nb_available_values().to_uint());
      print_name();
      std::cout << "Send Hypothesis with value " << m_internal_states[m_nb_state]->get_nb_available_values().to_uint() << std::endl ;
      m_FSM_state.hypothesis_sent(true);
    }
  else if(m_FSM_state.is_hypothesis_returned() && 
	  !m_FSM_state.is_check_sent() && 
	  !m_FSM_state.is_check_granted())
    {
      print_name();
      std::cout << "Send Check" << std::endl ;
      l_message = new sudoku_message_check<SIZE>(m_vertical_group,
						 m_vertical_sub_group,
						 m_horizontal_group,
						 m_horizontal_sub_group,
						 0x1
						 );
      m_FSM_state.set_check_sent(true);
    }
  else if(m_FSM_state.is_hypothesis_accepted() && 
	  !m_FSM_state.is_new_level_sent())
    {
      print_name();
      std::cout << "Send New Hyp Level" << std::endl ;
      m_FSM_state.set_new_level_sent(true);
      l_message = new sudoku_message_set_hyp_level<SIZE>(m_vertical_group,
							 m_vertical_sub_group,
							 m_horizontal_group,
							 m_horizontal_sub_group,
							 0 // TO BE REFINED
							 );
    }
  return l_message;
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::run(void)
{
  while(1)
    {
      if(m_message_to_forward == nullptr && !m_input_box.is_empty())
	{
	  print_name();
	  std::cout << "Input message available" << std::endl ;
	  sudoku_message_base<SIZE> const * l_message = m_input_box.get_message();
	  l_message->display();

	  l_message->be_treated(this);
	}

      // Send a message if output box is not empty
      if(m_output_box.is_empty())
	{
	  const sudoku_message_base<SIZE> * const l_message = generate_message_to_send();
	  if(l_message != nullptr)
	    {
	      m_output_box.set_message(l_message);
	    }
	}
      wait();
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::listen_input_port(void)
{
  //print_name();
  //	std::cout << "listen input port" << std::endl ;
  if(m_input_box.is_empty())
    {
      m_input_port.m_acq.write(true);
      if(m_input_port.m_req.read()==true)
	{
	  print_name();
	  std::cout << "Receive message" << std::endl ;
	  std::cout << "Data : " << m_input_port.m_data.read() << std::endl;
	  sudoku_message_base<SIZE> const * l_message = sudoku_message_factory<SIZE>::decode_message(m_input_port.m_vertical_group.read(),
												     m_input_port.m_vertical_sub_group.read(),
												     m_input_port.m_horizontal_group.read(),
												     m_input_port.m_horizontal_sub_group.read(),
												     m_input_port.m_cmd.read(),
												     m_input_port.m_data.read());
	  m_input_box.set_message(l_message);
	  //          if(l_message->get_cmd() == sudoku_message_base<SIZE>::SET_VALUE || l_message->get_cmd() == sudoku_message_base<SIZE>::RELEASE_VALUE)
	  //                  {
	  m_activity_counter = 1 + SIZE * SIZE * SIZE * SIZE;
	  //                  }
	}
      else
	{
	  --m_activity_counter;
	  if(!m_activity_counter && !m_sc_stop_called)
	    {
	      m_sc_stop_called = true;
	      general_monitor::get_unique_instance()->display();
	      sc_stop();
	    }
	}
    }
  else
    {
      m_input_port.m_acq.write(false);
    }
}

//----------------------------------------------------------------------------
template<unsigned int SIZE,unsigned int MAX_NB_STATE>
void sudoku_cell<SIZE,MAX_NB_STATE>::manage_output_port(void)
{
  while(1)
    {
      //print_name();
      //   std::cout << "Manage output port" << std::endl ;
      if(m_output_box.is_empty())
	{
	  m_output_port.m_req.write(false);
	  wait();
	}
      else
	{
	  print_name();
	  std::cout << "Send message" << std::endl ;            
	  sudoku_message_base<SIZE> const * l_message = m_output_box.get_message();
	  // Write message content on port
	  m_output_port.m_vertical_group.write(l_message->get_vertical_group());
	  m_output_port.m_vertical_sub_group.write(l_message->get_vertical_sub_group());
	  m_output_port.m_horizontal_group.write(l_message->get_horizontal_group());
	  m_output_port.m_horizontal_sub_group.write(l_message->get_horizontal_sub_group());
	  m_output_port.m_cmd.write(l_message->get_cmd());
	  m_output_port.m_data.write(l_message->get_data());
	  delete_message(l_message);

	  // Indicate that message is ready to be sent
	  m_output_port.m_req.write(true);

	  // waiting for acknowledge
	  do
	    {
	      wait();
	    }
	  while(m_output_port.m_acq.read()==false);
	  print_name();
	  std::cout << "Acknowledge received" << std::endl ;            
	}
    }
}

template<unsigned int SIZE,unsigned int MAX_NB_STATE>
bool sudoku_cell<SIZE,MAX_NB_STATE>::m_sc_stop_called = false;
//EOF
