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
#ifndef SUDOKU_UTILS_H
#define SUDOKU_UTILS_H

namespace sudoku_systemc
{
  template<unsigned int VALUE>
    class sudoku_utils
    {
    private:
      static inline unsigned int get_nb_bits_for_value(void);
    public:
      static const unsigned int m_nb_bits_for_value;
      static const unsigned int m_nb_bits_for_nb_values;
    };

  #include "sudoku_utils.hpp"
}
#endif // SUDOKU_UTILS_H
//EOF
