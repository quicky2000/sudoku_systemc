#ifndef S_BUS_HPP
#define S_BUS_HPP

#include "systemc.h"
#include "S_types.hpp"
#include <string>

template<unsigned int SIZE>
class S_bus
{
public:
  sc_signal<bool> m_req;
  sc_signal<bool> m_acq;
  sc_signal<typename S_types<SIZE>::t_group_type> m_vertical_group;
  sc_signal<typename S_types<SIZE>::t_group_type> m_vertical_sub_group;
  sc_signal<typename S_types<SIZE>::t_group_type> m_horizontal_group;
  sc_signal<typename S_types<SIZE>::t_group_type> m_horizontal_sub_group;
  sc_signal<typename S_types<SIZE>::t_cmd_type> m_cmd;
  sc_signal<typename S_types<SIZE>::t_data_type> m_data;

  S_bus(const std::string & p_name):
    m_req((p_name+"_req").c_str()),
    m_acq((p_name+"_acq").c_str()),
    m_vertical_group((p_name+"_vertical_group").c_str()),
    m_vertical_sub_group((p_name+"_vertical_sub_group").c_str()),
    m_horizontal_group((p_name+"_horizontal_group").c_str()),
    m_horizontal_sub_group((p_name+"_horizontal_sub_group").c_str()),
    m_cmd((p_name+"_cmd").c_str()),
    m_data((p_name+"_data").c_str())
  {
  }
private:
};
#endif // S_BUS_HPP
//EOF
