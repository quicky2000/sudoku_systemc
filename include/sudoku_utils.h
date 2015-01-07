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
#ifndef SUDOKU_UTILS_HPP
#define SUDOKU_UTILS_HPP

namespace sudoku_systemc
{
  template<unsigned int VALUE>
    class sudoku_utils
    {
    private:
      static inline unsigned int get_nb_bits_for_value(void)
	{
	  return (VALUE == 0) ? 0 : (1+sudoku_utils<(VALUE >> 1)>::get_nb_bits());
	}
    public:
      static const unsigned int m_nb_bits_for_value;
      static const unsigned int m_nb_bits_for_nb_values;
    };

  template<unsigned int VALUE> const unsigned int sudoku_utils<VALUE>::m_nb_bits_for_value = (VALUE == 0) ? 0 : (1+sudoku_utils<(VALUE >> 1)>::m_nb_bits_for_value);
  template<unsigned int VALUE> const unsigned int sudoku_utils<VALUE>::m_nb_bits_for_nb_values = sudoku_utils<VALUE-1>::m_nb_bits_for_value;
}
#endif // SUDOKU_UTILS_HPP
//EOF
