#ifndef S_TOP_HPP
#define S_TOP_HPP

#include "systemc.h"
#include "sudoku.h"

class top:public sc_module
{
public:
  top(sc_module_name name,
      const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values);
  void check(const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_reference_values)const;
  std::string to_string(void)const;
private:
  sc_clock m_clk;
  sudoku_systemc::sudoku<3> m_sudoku;
};
#endif
