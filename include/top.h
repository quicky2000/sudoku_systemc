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
