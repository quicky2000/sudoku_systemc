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
#ifndef SUDOKU_BUS_H
#define SUDOKU_BUS_H

#include "systemc.h"
#include "sudoku_types.h"
#include <string>

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_bus
    {
    public:
      sc_signal<bool> m_req;
      sc_signal<bool> m_acq;
      sc_signal<typename sudoku_types<SIZE>::t_group_type> m_vertical_group;
      sc_signal<typename sudoku_types<SIZE>::t_group_type> m_vertical_sub_group;
      sc_signal<typename sudoku_types<SIZE>::t_group_type> m_horizontal_group;
      sc_signal<typename sudoku_types<SIZE>::t_group_type> m_horizontal_sub_group;
      sc_signal<typename sudoku_types<SIZE>::t_cmd_type> m_cmd;
      sc_signal<typename sudoku_types<SIZE>::t_data_type> m_data;

      sudoku_bus(const std::string & p_name);
    private:
    };

  #include "sudoku_bus.hpp"
}
#endif // SUDOKU_BUS_H
//EOF
