#ifndef S_TOP_HPP
#define S_TOP_HPP

#include "systemc.h"
#include "S.h"

class top:public sc_module
{
public:
  top(sc_module_name name,
    const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
    sc_module(name),
    m_clk("clk",10,SC_NS,05),
    m_S("S",p_init_values)
  {
    m_S.m_clk(m_clk);
  }
private:
  sc_clock m_clk;
  S<3> m_S;
};
#endif
