#ifndef S_OUTPUT_PORT_HPP
#define S_OUTPUT_PORT_HPP

#include "S_bus.hpp"

template<unsigned int SIZE> class S_output_port
{
public:
  sc_out<bool> m_req;
  sc_in<bool> m_acq;
  sc_out<typename S_types<SIZE>::t_group_type> m_vertical_group;
  sc_out<typename S_types<SIZE>::t_group_type> m_vertical_sub_group;
  sc_out<typename S_types<SIZE>::t_group_type> m_horizontal_group;
  sc_out<typename S_types<SIZE>::t_group_type> m_horizontal_sub_group;
  sc_out<typename S_types<SIZE>::t_cmd_type> m_cmd;
  sc_out<typename S_types<SIZE>::t_data_type> m_data;

  void operator () (S_bus<SIZE> & p_bus)
  {
    m_req(p_bus.m_req);
    m_acq(p_bus.m_acq);
    m_vertical_group(p_bus.m_vertical_group);
    m_vertical_sub_group(p_bus.m_vertical_sub_group);
    m_horizontal_group(p_bus.m_horizontal_group);
    m_horizontal_sub_group(p_bus.m_horizontal_sub_group);
    m_cmd(p_bus.m_cmd);
    m_data(p_bus.m_data);
  }

  S_output_port(const std::string & p_name):
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
#endif // S_OUTPUT_PORT_HPP
//EOF
