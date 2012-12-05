#ifndef S_TOP_HPP
#define S_TOP_HPP

#include "systemc.h"
#include "sudoku.h"

class top:public sc_module
{
public:
  top(sc_module_name name,
    const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
    sc_module(name),
    m_clk("clk",10,SC_NS,05),
    m_sudoku("sudoku",p_init_values)
  {
    m_sudoku.m_clk(m_clk);
  }
private:
  sc_clock m_clk;
  sudoku_systemc::sudoku<3> m_sudoku;
};
#endif
