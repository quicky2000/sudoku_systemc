/*
  This file is part of sudoku_systemc
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

namespace sudoku_systemc
{
  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_complete<SIZE>::synoptic_complete(synoptic::synoptic &p_owner):
    zone_container("synoptic_complete", synoptic_complete<SIZE>::get_computed_width(), synoptic_complete<SIZE>::get_computed_height()),
    m_grid(p_owner, "grid"),
    m_internal_grid(p_owner,"internal_grid")
  {
    add_zone(0,0,m_grid);
    add_zone(m_grid.get_width(),0,m_internal_grid);
    for(unsigned int l_y = 0; l_y < SIZE * SIZE; ++l_y)
      {
	for(unsigned int l_x = 0; l_x < SIZE * SIZE; ++l_x)
	  {
	    m_cell_listeners[l_x][l_y] = new synoptic_cell_listener<SIZE>(m_grid.get_cell(l_x, l_y),
									  m_internal_grid.get_cell(l_x,l_y)
									  );
	  }
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_complete<SIZE>::~synoptic_complete(void)
  {
    for(unsigned int l_y = 0; l_y < SIZE * SIZE; ++l_y)
      {
	for(unsigned int l_x = 0; l_x < SIZE * SIZE; ++l_x)
	  {
	    delete m_cell_listeners[l_x][l_y];
	  }
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_complete<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_complete<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_complete<SIZE>::compute_dimensions(void)
  {
    m_computed_width = synoptic_grid<SIZE>::get_computed_width() + synoptic_internal_grid<SIZE>::get_computed_width();
    m_computed_height = synoptic_internal_grid<SIZE>::get_computed_height();
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  cell_listener_if & synoptic_complete<SIZE>::get_cell_listener(const unsigned int & p_x, const unsigned int & p_y)
  {
    assert(p_x < SIZE * SIZE);
    assert(p_y < SIZE * SIZE);
    return *m_cell_listeners[p_x][p_y];
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_bus_listener_if & synoptic_complete<SIZE>::get_bus_listener(const unsigned int & p_x, const unsigned int & p_y)
  {
    assert(p_x < SIZE * SIZE);
    assert(p_y < SIZE * SIZE);
    return m_internal_grid.get_bus_listener(p_x, p_y);
  }

  template<unsigned int SIZE>
  unsigned int synoptic_complete<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_complete<SIZE>::m_computed_height = 0;
}
// EOF
