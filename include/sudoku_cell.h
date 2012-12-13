#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

#include "systemc.h"
#include <iostream>
#include <sstream>
#include <inttypes.h>
#include "sudoku_input_port.h"
#include "sudoku_output_port.h"
#include "sudoku_message_box.h"
#include "sudoku_message_factory.h"
#include "sudoku_internal_state.h"
#include "sudoku_message_analyzer_if.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_cell:public sc_module,
    public sudoku_message_analyser_if<SIZE>
    {
    private:

      typedef enum {INIT,UNDEFINED,SET} t_internal_FSM_state;

    public:
      SC_HAS_PROCESS(sudoku_cell);
      sudoku_cell(sc_module_name name,const uint32_t & p_x,const uint32_t & p_y,const uint32_t p_init_value=0);

      bool is_value_set(void)const;
      const typename sudoku_types<SIZE>::t_data_type & get_value(void)const;

      sc_in<bool> m_clk;
      sudoku_input_port<SIZE> m_input_port;
      sudoku_output_port<SIZE> m_output_port;
    private:
      void print_name(void);

      void treat_common(const sudoku_message_base<SIZE>* p_message);
      void treat(const sudoku_message_set_value<SIZE>* p_message);
      void treat(const sudoku_message_release_value<SIZE>* p_message);
      void treat(const sudoku_message_req_hypothesis<SIZE>* p_message);
 
      inline bool is_mine(const sudoku_message_base<SIZE> * const p_message)const;
      inline const sudoku_message_base<SIZE> * const generate_message_to_send(void);

      void run(void);
      void listen_input_port(void);
      void manage_output_port(void);

      bool less_than_position(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group2);

      const uint32_t m_id;
      const uint32_t m_vertical_group;
      const uint32_t m_vertical_sub_group;
      const uint32_t m_horizontal_group;
      const uint32_t m_horizontal_sub_group;
      t_internal_FSM_state m_internal_FSM_state;
      sudoku_internal_state<SIZE> m_internal_state;
      sudoku_message_box<SIZE> m_input_box;
      sudoku_message_box<SIZE> m_output_box;
      uint32_t m_activity_counter;
      const sudoku_message_base<SIZE> * m_message_to_forward;

      static bool m_sc_stop_called;
    };

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
    sudoku_cell<SIZE>::sudoku_cell(sc_module_name name,const uint32_t & p_x,const uint32_t & p_y,const uint32_t p_init_value):
    sc_module(name),
    m_clk("clk"),
    m_input_port("input_port"),
    m_output_port("output_port"),
    m_id(p_x + p_y *SIZE *SIZE),
    m_vertical_group((p_x /SIZE) % SIZE),
    m_vertical_sub_group(p_x % SIZE),
    m_horizontal_group((p_y /SIZE) % SIZE),
    m_horizontal_sub_group(p_y % SIZE),
    m_internal_FSM_state(INIT),
    m_internal_state(m_vertical_sub_group,m_horizontal_sub_group,p_init_value),
    m_activity_counter(1 + SIZE * SIZE * SIZE * SIZE),
    m_message_to_forward(NULL)
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
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      const typename sudoku_types<SIZE>::t_data_type & sudoku_cell<SIZE>::get_value(void)const
      {
	return m_internal_state.get_value();
      }
    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      bool sudoku_cell<SIZE>::is_value_set(void)const
      {
	return m_internal_state.is_value_set();
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::print_name(void)
      {
	std::cout << "Cell[" 
		  << m_vertical_group << "," 
		  << m_vertical_sub_group << "][" 
		  << m_horizontal_group << "," 
		  << m_horizontal_sub_group << "] \""
		  << name() << "\" Id=" << m_id << " @ " << sc_time_stamp() << ": ";
      }
  
    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      bool sudoku_cell<SIZE>::is_mine(const sudoku_message_base<SIZE> * const p_message)const
      {
	bool l_same_column = p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group;
	if(!l_same_column) return false;
	return p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      bool sudoku_cell<SIZE>::less_than_position(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group1,
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
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::treat_common(const sudoku_message_base<SIZE>* p_message)
      {
	if(p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group)
	  {
	    m_internal_state.remove_vertical_candidate(p_message->get_data());
	  }
	if(p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group)
	  {
	    m_internal_state.remove_horizontal_candidate(p_message->get_data());
	  }
	if(p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group)
	  {
	    m_internal_state.remove_square_candidate(p_message->get_data());
	  }
      }
    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::treat(const sudoku_message_set_value<SIZE>* p_message)
      {
	if(!is_mine(p_message))
	  {
            if(!m_internal_state.is_value_set())
              {
                if((p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group) ||
                   (p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group) || 
                   (p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group))
                  {
                    m_internal_state.remove_available_value(p_message->get_data());
                  }
                treat_common(p_message);
              }
            m_message_to_forward = p_message;
            m_internal_state.hypothesis_sent(false);
	  }
	else
	  {
	    std::cout << "Delete my own SET_VALUE message" << std::endl ;
	    delete p_message;
	  }
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::treat(const sudoku_message_release_value<SIZE>* p_message)
      {
        if(!is_mine(p_message))
          {
            if(!m_internal_state.is_value_set())
              {
                treat_common(p_message);
              }
            m_message_to_forward = p_message;
          }
        else
	  {
	    std::cout << "Delete my own RELEASE_VALUE message" << std::endl ;
	    delete p_message;
	  }
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::treat(const sudoku_message_req_hypothesis<SIZE>* p_message)
      {
	if(is_mine(p_message))
	  {
	    if(!m_internal_state.is_value_set())
	      {
		print_name();
		std::cout << "Hypothesis accepted !" << std::endl ;
		//		exit(-1);
	      }
	  }
        else if(m_internal_state.is_value_set())
          {
            m_message_to_forward = p_message;
          }
	else if(m_internal_state.is_hypothesis_sent())
          {
            if(m_internal_state.get_nb_available_values().to_uint() >= p_message->get_data().to_uint()+1)
              {
                if(m_internal_state.get_nb_available_values().to_uint() > p_message->get_data().to_uint()+1)
                  {
                    print_name();
                    std::cout << "Forward stronger hypothesis request : " << m_internal_state.get_nb_available_values().to_uint() << " > " << p_message->get_data().to_uint()+1 << std::endl ;
                    m_message_to_forward = p_message;
                  }
                else if(less_than_position(p_message->get_vertical_group(),p_message->get_vertical_sub_group(),p_message->get_horizontal_group(),p_message->get_horizontal_sub_group(),
                                           m_vertical_group,m_vertical_sub_group,m_horizontal_group,m_horizontal_sub_group) < 0)
                  {
                    print_name();
                    std::cout << "Forward higher position priority request" << std::endl ;
                    m_message_to_forward = p_message;
                  }
                else
                  {
                    print_name();
                    std::cout << "Discard hypothesis due to lower position priority" << std::endl ;
                    m_internal_state.hypothesis_sent(false);
                  }
              }
            else
              {
                print_name();
                std::cout << "Discard weak hypothesis request : " << m_internal_state.get_nb_available_values().to_uint() << " < " << p_message->get_data().to_uint()+1 << std::endl ;
                m_internal_state.hypothesis_sent(false);
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
            delete p_message;
          }
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      const sudoku_message_base<SIZE> * const sudoku_cell<SIZE>::generate_message_to_send(void)
        {
          const sudoku_message_base<SIZE> * l_message = NULL;

          if(m_message_to_forward != NULL)
            {
              l_message = m_message_to_forward;
              m_message_to_forward = NULL;
            }
          else if(m_internal_state.is_value_set() && !m_internal_state.is_value_sent())
            {
              l_message = new sudoku_message_set_value<SIZE>(m_vertical_group,
                                                             m_vertical_sub_group,
                                                             m_horizontal_group,
                                                             m_horizontal_sub_group,
                                                             m_internal_state.get_value()
                                                             );
              m_internal_state.value_sent(true);
            }
          else if(m_internal_state.get_values_to_release().to_uint() > 0)
            {
              l_message = new sudoku_message_release_value<SIZE>(m_vertical_group,
                                                                 m_vertical_sub_group,
                                                                 m_horizontal_group,
                                                                 m_horizontal_sub_group,
                                                                 m_internal_state.get_remaining_value()
                                                                 );
            }
          else if(!m_internal_state.is_value_set() && !m_internal_state.is_hypothesis_sent() && m_internal_state.get_nb_available_values() != sudoku_configuration<SIZE>::m_nb_value)
            {
              // Request for hypothesis
	      l_message = new sudoku_message_req_hypothesis<SIZE>(m_vertical_group,
								  m_vertical_sub_group,
								  m_horizontal_group,
								  m_horizontal_sub_group,
								  m_internal_state.get_nb_available_values().to_uint()-1
								  );
              print_name();
              std::cout << "Send Hypothesis with value " << m_internal_state.get_nb_available_values().to_uint() << std::endl ;
              m_internal_state.hypothesis_sent(true);
            }
          return l_message;
        }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::run(void)
      {
	while(1)
	  {
	    if(m_message_to_forward == NULL && !m_input_box.is_empty())
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
                if(l_message != NULL)
                  {
                    m_output_box.set_message(l_message);
                  }
	      }
	    wait();
	  }
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::listen_input_port(void)
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
                if(l_message->get_cmd() == sudoku_message_base<SIZE>::SET_VALUE || l_message->get_cmd() == sudoku_message_base<SIZE>::RELEASE_VALUE)
                  {
                    m_activity_counter = 1 + SIZE * SIZE * SIZE * SIZE;
                  }
	      }
	    else
	      {
		--m_activity_counter;
		if(!m_activity_counter && !m_sc_stop_called)
		  {
		    m_sc_stop_called = true;
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
    template<unsigned int SIZE>
      void sudoku_cell<SIZE>::manage_output_port(void)
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
		delete l_message;

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

    template<unsigned int SIZE>
      bool sudoku_cell<SIZE>::m_sc_stop_called = false;

}
#endif // SUDOKU_CELL_H
//EOF
