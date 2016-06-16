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

#include "top.h"
#include "synoptic_grid.h"
#include <sstream>

//------------------------------------------------------------------------------
top::top(sc_module_name name,
	 const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
  sc_module(name),
  m_clk("clk",10,SC_NS,05),
  m_synoptic(decltype(m_grid)::get_computed_width(),decltype(m_grid)::get_computed_height()),
  m_grid(m_synoptic,"grid")
{
  m_synoptic.add_zone(0,0,m_grid);
  m_synoptic.pack();
  m_synoptic.paint();
  m_synoptic.refresh();

  m_sudoku = new sudoku_systemc::sudoku<3>("sudoku",p_init_values,m_grid);
  m_sudoku->m_clk(m_clk);

  SC_METHOD(refresh_GUI);
  sensitive << m_clk.negedge_event();
}

//------------------------------------------------------------------------------
top::~top(void)
{
  delete m_sudoku;
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
      if(m_sudoku->is_cell_value_set(l_x,l_y))
	{
	  unsigned int l_computed_value = m_sudoku->get_cell_value(l_x,l_y).to_uint()+1;
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
	  if(m_sudoku->is_cell_value_set(l_index_x,l_index_y) && p_reference_values.find(std::pair<unsigned int,unsigned int>(l_index_x,l_index_y))==p_reference_values.end())
	    {
	      std::cout << "ERROR : Value " << m_sudoku->get_cell_value(l_index_x,l_index_y).to_uint()+1 << " in cell[" << l_index_x << "," << l_index_y << "] whereas no reference value" << std::endl ;
	      l_error = true;
	    }
	}
    }
  std::cout << "Check " << (l_error ? "FAILED" : "OK" ) << std::endl ;
  
}

//------------------------------------------------------------------------------
std::string top::to_string(void)const
{
  std::stringstream l_result;
  unsigned int l_big_side_size = 9;
  const std::string l_horizontal_separator = std::string(l_big_side_size*4+1,'-');
  const std::string l_horizontal_separator_2 = std::string(l_big_side_size*4+1,'+');
  for(unsigned int l_y = 0; l_y < l_big_side_size ; l_y++)
    {
      if( l_y % 3)
	{
	  l_result << l_horizontal_separator << endl ;
	}
      else
	{
	  l_result << l_horizontal_separator_2 << endl ;
	}

      for(unsigned int l_x = 0; l_x < l_big_side_size ; l_x++)
	{
      if( l_x % 3)
	{
	  l_result << "  "  ;
	}
      else
	{
	  l_result << "| "  ;
	}
	  if(m_sudoku->is_cell_value_set(l_x,l_y))
	    {
	      l_result << m_sudoku->get_cell_value(l_x,l_y).to_uint()+1 ;
	    }
	  else
	    {
	      l_result << " " ;
	    }
	  l_result << " ";
	}
      l_result << "|" << endl ;
    }
  l_result << l_horizontal_separator << endl ;

  return l_result.str();
}

//------------------------------------------------------------------------------
void top::refresh_GUI(void)
{
  m_synoptic.refresh();
}
//EOF
