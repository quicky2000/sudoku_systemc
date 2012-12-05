#ifndef S_CELL_HPP
#define S_CELL_HPP

#include "systemc.h"
#include <iostream>
#include <sstream>
#include <inttypes.h>
#include "S_input_port.h"
#include "S_output_port.h"
#include "S_message_box.h"
#include "S_message_factory.h"
#include "S_internal_state.h"
#include "S_message_analyzer_if.h"

template<unsigned int SIZE> class S_cell:public sc_module,
  public S_message_analyser_if<SIZE>
{
private:

  typedef enum {INIT,UNDEFINED,SET} t_internal_FSM_state;

public:
  SC_HAS_PROCESS(S_cell);
  S_cell(sc_module_name name,const uint32_t & p_x,const uint32_t & p_y,const uint32_t p_init_value=0):
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
    m_internal_state(m_vertical_sub_group,m_horizontal_sub_group,p_init_value)
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

  sc_in<bool> m_clk;
  S_input_port<SIZE> m_input_port;
  S_output_port<SIZE> m_output_port;
private:
  void print_name(void)
  {
    std::cout << "Cell[" 
              << m_vertical_group << "," 
              << m_vertical_sub_group << "][" 
              << m_horizontal_group << "," 
              << m_horizontal_sub_group << "] \""
              << name() << "\" Id=" << m_id << " @ " << sc_time_stamp() << ": ";
  }
  
  void treat_common(const S_message_base<SIZE>* p_message)
  {
    //TO DELETE   if(p_message->get_vertical_group() == m_vertical_group)
    //TO DELETE      {
    //TO DELETE        m_internal_state.remove_group_vertical_candidate(p_message->get_data(),p_message->get_vertical_sub_group());
    //TO DELETE      }

    //TO DELETE    if(p_message->get_horizontal_group() == m_horizontal_group)
    //TO DELETE      {
    //TO DELETE        m_internal_state.remove_group_horizontal_candidate(p_message->get_data(),p_message->get_horizontal_sub_group());
    //TO DELETE      }

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

  void treat(const S_message_set_value<SIZE>* p_message)
  {
    if((p_message->get_vertical_group() == m_vertical_group && p_message->get_vertical_sub_group() == m_vertical_sub_group) ||
       (p_message->get_horizontal_group() == m_horizontal_group && p_message->get_horizontal_sub_group() == m_horizontal_sub_group) || 
       (p_message->get_vertical_group() == m_vertical_group && p_message->get_horizontal_group() == m_horizontal_group))
      {
        m_internal_state.remove_available_value(p_message->get_data());
      }
    treat_common(p_message);
  }

  void treat(const S_message_release_value<SIZE>* p_message)
  {
    treat_common(p_message);
  }

  void treat(const S_message_req_hypothesis<SIZE>* p_message)
  {
    // DO NOTHING
  }

  void run(void)
  {
    while(1)
      {
        S_message_base<SIZE> const * l_message_to_forward = NULL;
        if(!m_input_box.is_empty())
          {
            print_name();
            std::cout << "Input message available" << std::endl ;
            S_message_base<SIZE> const * l_message = m_input_box.get_message();
            l_message->display();
            bool l_same_column = l_message->get_vertical_group() == m_vertical_group && l_message->get_vertical_sub_group() == m_vertical_sub_group;
            bool l_same_line = l_message->get_horizontal_group() == m_horizontal_group && l_message->get_horizontal_sub_group() == m_horizontal_sub_group;
            // Check if I was the emitter of this message
            if(l_same_column  && l_same_line)
              {
                print_name();
                if(l_message->get_cmd() != S_message_base<SIZE>::REQ_HYP)
                  {
                    std::cout << "Delete my own message" << std::endl ;
                    delete l_message;
                  }
                else
                  {
                    std::cout << "Hypothesis accepted !" << std::endl ;
                    sc_stop();
                  }
              }
            else
              {
                if(!m_internal_state.is_value_set())
                  {
                    l_message->be_treated(this);
                  }
                if(l_message->get_cmd() != S_message_base<SIZE>::REQ_HYP)
                  {
                    l_message_to_forward = l_message;
                  }
                else if(m_internal_state.is_hypothesis_sent())
                  {
                    if(m_internal_state.get_nb_available_values().to_uint() >= l_message->get_data().to_uint()+1)
                      {
                        if(m_internal_state.get_nb_available_values().to_uint() > l_message->get_data().to_uint()+1)
                          {
                            print_name();
                            std::cout << "Forward stronger hypothesis request : " << m_internal_state.get_nb_available_values().to_uint() << " > " << l_message->get_data().to_uint()+1 << std::endl ;
                            l_message_to_forward = l_message;
                          }
                        else if(less_than_position(l_message->get_vertical_group(),l_message->get_vertical_sub_group(),l_message->get_horizontal_group(),l_message->get_horizontal_sub_group(),
                                        m_vertical_group,m_vertical_sub_group,m_horizontal_group,m_horizontal_sub_group) < 0)
                          {
                            print_name();
                            std::cout << "Forward higher position priority request" << std::endl ;
                            l_message_to_forward = l_message;
                          }
                        else
                          {
                            print_name();
                            std::cout << "Discard hypothesis due to lower position priority" << std::endl ;
                          }
                      }
                    else
                      {
                        print_name();
                        std::cout << "Discard weak hypothesis request : " << m_internal_state.get_nb_available_values().to_uint() << " < " << l_message->get_data().to_uint()+1 << std::endl ;
                      }
                  }
                else
                  {
                    print_name();
                    std::cout << "Discard prematured hypothesis request" << std::endl ;
                  }
              }
          }
        if(m_output_box.is_empty())
          {
            if(l_message_to_forward)
              {
                m_output_box.set_message(l_message_to_forward);
              }
            else if(m_internal_state.is_value_set() && !m_internal_state.is_value_sent())
              {
                S_message_base<SIZE> * l_message = new S_message_set_value<SIZE>(m_vertical_group,
                                                                                 m_vertical_sub_group,
                                                                                 m_horizontal_group,
                                                                                 m_horizontal_sub_group,
                                                                                 m_internal_state.get_value());
                m_output_box.set_message(l_message);
                m_internal_state.value_sent(true);
              }
            else if(m_internal_state.get_values_to_release().to_uint() > 0)
              {
                S_message_base<SIZE> * l_message = new S_message_release_value<SIZE>(m_vertical_group,
                                                                                     m_vertical_sub_group,
                                                                                     m_horizontal_group,
                                                                                     m_horizontal_sub_group,
                                                                                     m_internal_state.get_remaining_value());
                m_output_box.set_message(l_message);
              }
            else if(!m_internal_state.is_value_set() && !m_internal_state.is_hypothesis_sent())
              {
                // Request for hypothesis
                S_message_base<SIZE> * l_message = new S_message_req_hypothesis<SIZE>(m_vertical_group,
                                                                                      m_vertical_sub_group,
                                                                                      m_horizontal_group,
                                                                                      m_horizontal_sub_group,
                                                                                      m_internal_state.get_nb_available_values().to_uint()-1);
                m_output_box.set_message(l_message);
                m_internal_state.hypothesis_sent();
                print_name();
                std::cout << "Send Hypothesis with value " << m_internal_state.get_nb_available_values().to_uint() << std::endl ;
              }

          }
        wait();
      }
  }

  void listen_input_port(void)
  {
    print_name();
    std::cout << "listen input port" << std::endl ;
    if(m_input_box.is_empty())
      {
        m_input_port.m_acq.write(true);
        if(m_input_port.m_req.read()==true)
          {
            print_name();
            std::cout << "Receive message" << std::endl ;
            std::cout << "Data : " << m_input_port.m_data.read() << std::endl;
            S_message_base<SIZE> const * l_message = S_message_factory<SIZE>::decode_message(m_input_port.m_vertical_group.read(),
                                                                                             m_input_port.m_vertical_sub_group.read(),
                                                                                             m_input_port.m_horizontal_group.read(),
                                                                                             m_input_port.m_horizontal_sub_group.read(),
                                                                                             m_input_port.m_cmd.read(),
                                                                                             m_input_port.m_data.read());
            m_input_box.set_message(l_message);
          }
      }
    else
      {
        m_input_port.m_acq.write(false);
      }
  }


  void manage_output_port(void)
  {
    while(1)
      {
        print_name();
        std::cout << "Manage output port" << std::endl ;
        if(m_output_box.is_empty())
          {
            m_output_port.m_req.write(false);
            wait();
          }
        else
          {
            print_name();
            std::cout << "Send message" << std::endl ;            
            S_message_base<SIZE> const * l_message = m_output_box.get_message();
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

  bool less_than_position(const typename S_types<SIZE>::t_group_type & p_vertical_group1,
                       const typename S_types<SIZE>::t_group_type & p_vertical_sub_group1,
                       const typename S_types<SIZE>::t_group_type & p_horizontal_group1,
                       const typename S_types<SIZE>::t_group_type & p_horizontal_sub_group1,
                       const typename S_types<SIZE>::t_group_type & p_vertical_group2,
                       const typename S_types<SIZE>::t_group_type & p_vertical_sub_group2,
                       const typename S_types<SIZE>::t_group_type & p_horizontal_group2,
                          const typename S_types<SIZE>::t_group_type & p_horizontal_sub_group2)
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
    //  l_pos1 = SIZE * p_horizontal_group1 + p_horizontal_sub_group1 + (SIZE * p_vertical_group1 + p_vertical_sub_group1) * SIZE * SIZE;
    //  l_pos2 = SIZE * p_horizontal_group2 + p_horizontal_sub_group2 + (SIZE * p_vertical_group2 + p_vertical_sub_group2) * SIZE * SIZE;
    //  return l_pos1 < l_pos2;

  }
  const uint32_t m_id;
  const uint32_t m_vertical_group;
  const uint32_t m_vertical_sub_group;
  const uint32_t m_horizontal_group;
  const uint32_t m_horizontal_sub_group;
  t_internal_FSM_state m_internal_FSM_state;
  S_internal_state<SIZE> m_internal_state;
  S_message_box<SIZE> m_input_box;
  S_message_box<SIZE> m_output_box;
};
#endif
