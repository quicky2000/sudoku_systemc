#include "top.h"

//------------------------------------------------------------------------------
top::top(sc_module_name name,
	 const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
  sc_module(name),
  m_clk("clk",10,SC_NS,05),
  m_sudoku("sudoku",p_init_values)
{
  m_sudoku.m_clk(m_clk);
}
//------------------------------------------------------------------------------
void top::check(const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_reference_values)const
{
  assert(p_reference_values.size());
  bool l_error = false;
  for(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::const_iterator l_iter = p_reference_values.begin();
      l_iter != p_reference_values.end();
      ++l_iter)
    {
      unsigned int l_x = l_iter->first.first;
      unsigned int l_y = l_iter->first.second;
      unsigned int l_value = l_iter->second;
      if(m_sudoku.is_cell_value_set(l_x,l_y))
	{
	  unsigned int l_computed_value = m_sudoku.get_cell_value(l_x,l_y).to_uint()+1;
	  if(l_value != l_computed_value)
	    {
	      std::cout << "ERROR : difference between computed value : " << l_computed_value << " and expected value " << l_value << " in cell[" << l_x << "," << l_y << "]" << std::endl ;
	      l_error = true;
	    }
	}
      else
	{
	  std::cout << "ERROR : No value in cell[" << l_x << "," << l_y << "] whereas expecting value " << l_value << std::endl ;
	  l_error = true;
	}
    }
  for(unsigned int l_index_x = 0;l_index_x < 9 ; ++l_index_x)
    {
      for(unsigned int l_index_y = 0;l_index_y < 9 ; ++l_index_y)
	{
	  if(m_sudoku.is_cell_value_set(l_index_x,l_index_y) && p_reference_values.find(std::pair<unsigned int,unsigned int>(l_index_x,l_index_y))==p_reference_values.end())
	    {
	      std::cout << "ERROR : Value " << m_sudoku.get_cell_value(l_index_x,l_index_y).to_uint()+1 << " in cell[" << l_index_x << "," << l_index_y << "] whereas no reference value" << std::endl ;
	      l_error = true;
	    }
	}
    }
  std::cout << "Check " << (l_error ? "FAILED" : "OK" ) << std::endl ;
  
}
//EOF
