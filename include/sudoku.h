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
#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "systemc.h"
#include "sudoku_cell.h"
#include "sudoku_bus.h"
#include "to_string_if.h"
#include <iostream>
#include <map>

namespace sudoku_systemc
{

  class listener_provider_if;

  template<unsigned int SIZE>
    class sudoku:
  public sc_module,
    public to_string_if
  {
  public:
    SC_HAS_PROCESS(sudoku);
    sudoku(sc_module_name name,
	   const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values,
	   listener_provider_if & p_provider);

    ~sudoku(void);

    bool is_cell_value_set(unsigned int p_x,unsigned int p_y)const;
    const typename sudoku_types<SIZE>::t_data_type & get_cell_value(unsigned int p_x,unsigned int p_y)const;

    sc_in<bool> m_clk;
  private:
    std::string to_string(void)const override;

    void clk_management(void);

    sc_signal<bool> m_clk_sig;
    sudoku_cell<SIZE> *m_cells2[SIZE * SIZE][SIZE * SIZE];
    sudoku_bus<SIZE> *m_buses[SIZE * SIZE * SIZE * SIZE];
  };
}

#include "sudoku.hpp"

#endif
//EOF
