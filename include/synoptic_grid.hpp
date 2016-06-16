/*    This file is part of sudoku_systemc
      The aim of this software is to solvde dicoplus game
      Copyright (C) 2016  Julien Thevenon ( julien_thevenon at yahoo.fr )

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

#include <sstream>

namespace sudoku_systemc
{
  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_grid<SIZE>::synoptic_grid(synoptic::synoptic &p_owner,
				     const std::string & p_name):
    zone_container(p_name, synoptic_grid<SIZE>::get_computed_width(), synoptic_grid<SIZE>::get_computed_height())
  {
    synoptic_char::init();
   for(unsigned int l_x = 0 ; l_x < SIZE ; ++l_x)
      {
	for(unsigned int l_y = 0 ; l_y < SIZE ; ++l_y)
	  {
	    std::stringstream l_x_stream;
	    l_x_stream << l_x;
	    std::stringstream l_y_stream;
	    l_y_stream << l_y;
	    m_squares[l_x][l_y] = new synoptic_square<SIZE>(p_owner,"square[" + l_x_stream.str() + "][" + l_y_stream.str() + "]");
	    add_zone(l_x * synoptic_square<SIZE>::get_computed_width(), l_y * synoptic_square<SIZE>::get_computed_height(), *m_squares[l_x][l_y]);
	  }
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_grid<SIZE>::~synoptic_grid(void)
  {
    for(unsigned int l_x = 0 ; l_x < SIZE ; ++l_x)
      {
	for(unsigned int l_y = 0 ; l_y < SIZE ; ++l_y)
	  {
	    delete m_squares[l_x][l_y];
	  }
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_grid<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_grid<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_grid<SIZE>::compute_dimensions(void)
  {
    m_computed_width = SIZE * synoptic_square<SIZE>::get_computed_width();
    m_computed_height = SIZE * synoptic_square<SIZE>::get_computed_height();
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  cell_listener_if & synoptic_grid<SIZE>::get_cell_listener(const unsigned int & p_x, const unsigned int & p_y)
  {
    assert(p_x < SIZE * SIZE);
    assert(p_y < SIZE * SIZE);
    return m_squares[p_x / 3][p_y / 3]->get_cell_listener(p_x % SIZE, p_y % SIZE);
  }

  template<unsigned int SIZE>
  unsigned int synoptic_grid<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_grid<SIZE>::m_computed_height = 0;
}
// EOF
