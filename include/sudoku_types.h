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
#ifndef SUDOKU_TYPES_H
#define SUDOKU_TYPES_H

#include "sudoku_configuration.h"
#include "systemc.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_types
    {
    public:
      typedef sc_bv<sudoku_configuration<SIZE>::m_cmd_nb_bits > t_cmd_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_group_nb_bits > t_group_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_coded_value_nb_bits> t_data_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_nb_value> t_available_values;
      typedef sc_bv<sudoku_configuration<SIZE>::m_internal_value_nb_bits> t_nb_available_values;
      typedef sc_bv<sudoku_configuration<SIZE>::m_coded_value_nb_bits> t_group_candidate;
    }
  ;
}
#endif // SUDOKU_TYPES_H
//EOF
