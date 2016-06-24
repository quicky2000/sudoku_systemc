/*    This file is part of sudoku_systemc
      The aim of this software is to solve sudoku game
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
  synoptic_internal_cell<SIZE>::synoptic_internal_cell(synoptic::zone_owner_if & p_owner,
						   const std::string & p_name):
    zone_container(p_name, synoptic_internal_cell<SIZE>::get_computed_width(), synoptic_internal_cell<SIZE>::get_computed_height()),
    m_up_border(p_owner, p_name + "_up_border", get_width(), 1, 255, 255, 255),
    m_right_border(p_owner, p_name + "_right_border", 1, get_height() - 2, 255, 255, 255),
    m_down_border(p_owner, p_name + "_down_border", get_width(), 1, 255, 255, 255),
    m_left_border(p_owner, p_name + "_left_border", 1, get_height() - 2, 255, 255, 255),
    m_array(p_owner, p_name + ".array")
  {
    // Adding borders
    add_zone(0,0,m_up_border);
    add_zone(get_width() - 1,1,m_right_border);
    add_zone(0,get_height() - 1,m_down_border);
    add_zone(0,1,m_left_border);

    add_zone(1, 1, m_array);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_horizontal_candidate(const unsigned int & p_index,
							      const unsigned int & p_value)
  {
    m_array.set_horizontal_candidate(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_vertical_candidate(const unsigned int & p_index,
							      const unsigned int & p_value)
  {
    m_array.set_vertical_candidate(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_square_candidate(const unsigned int & p_index,
							      const unsigned int & p_value)
  {
    m_array.set_square_candidate(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_available_value(const unsigned int & p_index,
							 bool p_value)
  {
    m_array.set_available_value(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_release_value(const unsigned int & p_index,
							 bool p_value)
  {
    m_array.set_release_value(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_internal_state(const cell_listener_if::t_FSM_state & p_index,
							bool p_value)
  {
    m_array.set_internal_state(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::set_hypothesis_level(const unsigned int & p_level)
  {
    m_array.set_hypothesis_level(p_level);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_cell<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_cell<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_cell<SIZE>::compute_dimensions(void)
  {
    m_computed_width = synoptic_internal_array<SIZE>::get_computed_width() + 2;
    m_computed_height = synoptic_internal_array<SIZE>::get_computed_height() + 2;
  }

  template<unsigned int SIZE>
  unsigned int synoptic_internal_cell<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_internal_cell<SIZE>::m_computed_height = 0;
}
// EOF
