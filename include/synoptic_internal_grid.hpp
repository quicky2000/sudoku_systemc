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
namespace sudoku_systemc
{
  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_internal_grid<SIZE>::synoptic_internal_grid(synoptic::zone_owner_if & p_owner,
						   const std::string & p_name):
    zone_container(p_name, synoptic_internal_grid<SIZE>::get_computed_width(), synoptic_internal_grid<SIZE>::get_computed_height())
  {
    for(unsigned int l_y = 0; l_y < SIZE * SIZE; ++l_y)
      {
	std::stringstream l_stream_y;
	l_stream_y << l_y;
	unsigned int l_row_y = m_space + l_y * (m_space + synoptic_internal_cell<SIZE>::get_computed_height());
	for(unsigned int l_x = 0; l_x < SIZE * SIZE; ++l_x)
	  {
	    std::stringstream l_stream_x;
	    l_stream_x << l_x;
	    m_cells[l_x][l_y] = new synoptic_internal_cell<SIZE>(p_owner, p_name + ".cell[" + l_stream_x.str() + "][" + l_stream_y.str() + "]");
	    add_zone(m_space + l_x * (synoptic_internal_cell<SIZE>::get_computed_width() + synoptic_bus::get_computed_width()), l_row_y, *m_cells[l_x][l_y]);
	    m_buses[l_x][l_y] = new synoptic_bus(p_owner, p_name + ".bus[" + l_stream_x.str() + "][" + l_stream_y.str() + "]");
	    add_zone(m_space + (l_x + 1) * synoptic_internal_cell<SIZE>::get_computed_width() + l_x * synoptic_bus::get_computed_width(), l_row_y + (synoptic_internal_cell<SIZE>::get_computed_height() - synoptic_bus::get_computed_height()) / 2, *m_buses[l_x][l_y]);
	  }
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_internal_grid<SIZE>::~synoptic_internal_grid(void)
  {
    for(unsigned int l_y = 0; l_y < SIZE * SIZE; ++l_y)
      {
	for(unsigned int l_x = 0; l_x < SIZE * SIZE; ++l_x)
	  {
	    delete m_cells[l_x][l_y];
	    delete m_buses[l_x][l_y];
	  }
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_grid<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_grid<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_grid<SIZE>::compute_dimensions(void)
  {
    m_computed_width = 2 * m_space + SIZE * SIZE * (synoptic_internal_cell<SIZE>::get_computed_width() + synoptic_bus::get_computed_width());
    m_computed_height = SIZE * SIZE * (synoptic_internal_cell<SIZE>::get_computed_height() + m_space) + m_space;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_bus_listener_if & synoptic_internal_grid<SIZE>::get_bus_listener(const unsigned int & p_x, const unsigned int & p_y)
  {
    return *m_buses[p_x][p_y];
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_internal_cell<SIZE> & synoptic_internal_grid<SIZE>::get_cell(const unsigned int & p_x, const unsigned int & p_y)
  {
    return *m_cells[p_x][p_y];
  }

  template<unsigned int SIZE>
  unsigned int synoptic_internal_grid<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_internal_grid<SIZE>::m_computed_height = 0;

  template<unsigned int SIZE>
  const unsigned int synoptic_internal_grid<SIZE>::m_space = 4;
}
// EOF
