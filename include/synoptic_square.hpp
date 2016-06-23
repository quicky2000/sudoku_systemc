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
#include <cassert>

namespace sudoku_systemc
{
  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_square<SIZE>::synoptic_square(synoptic::synoptic & p_owner,
					 const std::string & p_name,
					 unsigned int p_x,
					 unsigned int p_y):
    synoptic::zone_container(p_name, synoptic_square<SIZE>::get_computed_width(), synoptic_square<SIZE>::get_computed_height()),
    m_up_border(p_owner, p_name + "_up_border", get_width(), 1, 255, 255, 255),
    m_right_border(p_owner, p_name + "_right_border", 1, get_height() - 2, 255, 255, 255),
    m_down_border(p_owner, p_name + "_down_border", get_width(), 1, 255, 255, 255),
    m_left_border(p_owner, p_name + "_left_border", 1, get_height() - 2, 255, 255, 255)
  {
    for(unsigned int l_x = 0 ; l_x < SIZE ; ++l_x)
      {
	for(unsigned int l_y = 0 ; l_y < SIZE ; ++l_y)
	  {
	    std::stringstream l_x_stream;
	    l_x_stream << (l_x + SIZE * p_x);
	    std::stringstream l_y_stream;
	    l_y_stream << (l_y + SIZE * p_y);
	    m_cells[l_x][l_y] = new synoptic_cell(p_owner,"cell[" + l_x_stream.str() + "][" + l_y_stream.str() + "]");
	    add_zone(2 + l_x + l_x * synoptic_cell::get_computed_width(),2 + l_y + l_y * synoptic_cell::get_computed_height(), *m_cells[l_x][l_y]);
	  }
      }

    // Adding borders
    add_zone(0,0,m_up_border);
    add_zone(get_width() - 1,1,m_right_border);
    add_zone(0,get_height() - 1,m_down_border);
    add_zone(0,1,m_left_border);
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_square<SIZE>::~synoptic_square(void)
  {
    for(unsigned int l_x = 0 ; l_x < SIZE ; ++l_x)
      {
	for(unsigned int l_y = 0 ; l_y < SIZE ; ++l_y)
	  {
	    delete m_cells[l_x][l_y];
	  }
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_square<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_square<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_square<SIZE>::compute_dimensions(void)
  {
    m_computed_width = synoptic_cell::get_computed_width() * SIZE + 4 + (SIZE - 1);
    m_computed_height = synoptic_cell::get_computed_height() * SIZE + 4 + (SIZE - 1);
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_cell & synoptic_square<SIZE>::get_cell(const unsigned int & p_x, const unsigned int & p_y)
  {
    assert(p_x < SIZE);
    assert(p_y < SIZE);
    return *m_cells[p_x][p_y];
  }

  template<unsigned int SIZE>
  unsigned int synoptic_square<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_square<SIZE>::m_computed_height = 0;
}
// EOF
