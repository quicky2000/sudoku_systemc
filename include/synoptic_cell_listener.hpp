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
  synoptic_cell_listener<SIZE>::synoptic_cell_listener(synoptic_cell & p_cell,
						 synoptic_internal_cell<SIZE> & p_internal_cell
					     ):
    m_cell(p_cell),
    m_internal_cell(p_internal_cell),
    m_hypothesis_level(0),
    m_initial_value(false)
  {
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_value(const unsigned int & p_value, const unsigned int & p_hypothesis_level)
  {
    if(p_hypothesis_level == m_hypothesis_level)
      {
	m_cell.set_value(p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::clear_value(void)
  {
    m_cell.clear_value();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_hypothesis_level(const unsigned int & p_level)
  {
    m_hypothesis_level = p_level;
    m_internal_cell.set_hypothesis_level(p_level);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::mark_as_initial_value(void)
  {
    m_cell.mark_as_initial_value();
    m_initial_value = true;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_horizontal_candidate(const unsigned int & p_index,
							      const unsigned int & p_value,
							      const unsigned int & p_hypothesis_level
							      )
  {
    if(!m_initial_value && p_hypothesis_level == m_hypothesis_level)
      {
	m_internal_cell.set_horizontal_candidate(p_index, p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_vertical_candidate(const unsigned int & p_index,
							    const unsigned int & p_value,
							    const unsigned int & p_hypothesis_level
							    )
  {
    if(!m_initial_value && p_hypothesis_level == m_hypothesis_level)
      {
	m_internal_cell.set_vertical_candidate(p_index, p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_square_candidate(const unsigned int & p_index,
							  const unsigned int & p_value,
							  const unsigned int & p_hypothesis_level
							  )
  {
    if(!m_initial_value && p_hypothesis_level == m_hypothesis_level)
      {
	m_internal_cell.set_square_candidate(p_index, p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_available_value(const unsigned int & p_index,
							 bool p_value,
							 const unsigned int & p_hypothesis_level)
  {
    if(!m_initial_value && p_hypothesis_level == m_hypothesis_level)
      {
	m_internal_cell.set_available_value(p_index, p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_release_value(const unsigned int & p_index,
						       bool p_value,
						       const unsigned int & p_hypothesis_level)
  {
    if(!m_initial_value && p_hypothesis_level == m_hypothesis_level)
      {
	m_internal_cell.set_release_value(p_index, p_value);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_cell_listener<SIZE>::set_internal_state(const cell_listener_if::t_FSM_state & p_index,
							bool p_value)
  {
    if(!m_initial_value)
      {
	m_internal_cell.set_internal_state(p_index, p_value);
      }
  }

}
// EOF
