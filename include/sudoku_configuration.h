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
#ifndef SUDOKU_CONFIGURATION_H
#define SUDOKU_CONFIGURATION_H

#include "sudoku_utils.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_configuration
    {
    public:
      static const unsigned int m_nb_value;
      static const unsigned int m_nb_cmd;
      static const unsigned int m_group_nb_bits;
      static const unsigned int m_cmd_nb_bits;
      static const unsigned int m_coded_value_nb_bits;
      static const unsigned int m_internal_value_nb_bits;
    }
  ;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_nb_value = SIZE * SIZE;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_nb_cmd = 5;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_group_nb_bits = sudoku_utils<SIZE>::m_nb_bits_for_value;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_cmd_nb_bits = sudoku_utils<m_nb_cmd>::m_nb_bits_for_nb_values;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_coded_value_nb_bits = sudoku_utils<SIZE*SIZE>::m_nb_bits_for_nb_values;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_internal_value_nb_bits = sudoku_utils<SIZE*SIZE>::m_nb_bits_for_value;
}
#endif // SUDOKU_CONFIGURATION_H
//EOF
