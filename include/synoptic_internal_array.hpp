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
  synoptic_internal_array<SIZE>::synoptic_internal_array(synoptic::zone_owner_if & p_owner,
						   const std::string & p_name):
    zone_container(p_name, synoptic_internal_array<SIZE>::get_computed_width(), synoptic_internal_array<SIZE>::get_computed_height()),
    m_value_row(p_owner, p_name + ".value_row", '0', true),
    m_separator(p_owner,"separator", synoptic_array_row<SIZE>::get_computed_width(), 1, 255, 255, 255),
    m_h_value_row(p_owner, p_name + ".H_value_row", 'H'),
    m_v_value_row(p_owner, p_name + ".V_value_row", 'V'),
    m_s_value_row(p_owner, p_name + ".S_value_row", 'S'),
    m_a_value_row(p_owner, p_name + ".A_value_row", 'A'),
    m_r_value_row(p_owner, p_name + ".R_value_row", 'R'),
    m_true_color(p_owner.get_color_code(0, 255, 0)),
    m_false_color(p_owner.get_color_code(255, 0, 0)),
    m_black_color(p_owner.get_color_code(0, 0, 0)),
    m_release_color(p_owner.get_color_code(255, 128, 0))
  {
    add_zone(0, 0, m_value_row);
    add_zone(0, synoptic_array_row<SIZE>::get_computed_height(), m_separator);
    add_zone(0, synoptic_array_row<SIZE>::get_computed_height() + 1, m_h_value_row);
    add_zone(0, 2 * synoptic_array_row<SIZE>::get_computed_height() + 1, m_v_value_row);
    add_zone(0, 3 * synoptic_array_row<SIZE>::get_computed_height() + 1, m_s_value_row);
    add_zone(0, 4 * synoptic_array_row<SIZE>::get_computed_height() + 1, m_a_value_row);
    add_zone(0, 5 * synoptic_array_row<SIZE>::get_computed_height() + 1, m_r_value_row);
    m_FSM_state[0] = new synoptic_char(p_owner, p_name + ".value_sent");
    m_FSM_state[1] = new synoptic_char(p_owner, p_name + ".check_sent");
    m_FSM_state[2] = new synoptic_char(p_owner, p_name + ".valid_check");
    m_FSM_state[3] = new synoptic_char(p_owner, p_name + ".check_granted");
    m_FSM_state[4] = new synoptic_char(p_owner, p_name + ".hypothesis_sent");
    m_FSM_state[5] = new synoptic_char(p_owner, p_name + ".hypothesis_accepted");
    m_FSM_state[6] = new synoptic_char(p_owner, p_name + ".hypothesis_returned");
    m_FSM_state[7] = new synoptic_char(p_owner, p_name + ".invalid_state");
    m_FSM_state[8] = new synoptic_char(p_owner, p_name + ".invalid_sent");
    m_FSM_state[9] = new synoptic_char(p_owner, p_name + ".set_new_level_sent");

    for(unsigned int l_index = 0; l_index < 10; ++l_index)
      {
	add_zone(2 + l_index * (synoptic_char::get_width() + 1), 6 * synoptic_array_row<SIZE>::get_computed_height() + 1, *m_FSM_state[l_index]);
      }
  }
  
  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_horizontal_candidate(const unsigned int & p_index,
							       const unsigned int & p_value
							       )
  {
    m_h_value_row.set_value(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_vertical_candidate(const unsigned int & p_index,
							     const unsigned int & p_value
							     )
  {
    m_v_value_row.set_value(p_index, p_value);
  }

   //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_square_candidate(const unsigned int & p_index,
							   const unsigned int & p_value
							   )
  {
    m_s_value_row.set_value(p_index, p_value);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_available_value(const unsigned int & p_index,
							  bool p_value)
  {
    m_a_value_row.set_value(p_index,'#' - '0');
    m_a_value_row.set_char_color_code(p_index, p_value ? m_true_color : m_false_color);    
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_release_value(const unsigned int & p_index,
							  bool p_value)
  {
    m_r_value_row.set_value(p_index,'#' - '0');
    m_r_value_row.set_char_color_code(p_index, p_value ? m_release_color : m_black_color);    
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_internal_state(const cell_listener_if::t_FSM_state & p_index,
							 bool p_value)
  {
    assert((unsigned int)p_index < 10);
    m_FSM_state[(unsigned int)p_index]->set_content('#');
    m_FSM_state[(unsigned int)p_index]->set_char_color(p_value ? m_true_color : m_false_color);
    m_FSM_state[(unsigned int)p_index]->paint();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::set_hypothesis_level(const unsigned int & p_level)
  {
    m_value_row.set_label('0' + p_level);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_array<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_internal_array<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_internal_array<SIZE>::compute_dimensions(void)
  {
    m_computed_width = synoptic_array_row<SIZE>::get_computed_width();
    m_computed_height = 7 * synoptic_array_row<SIZE>::get_computed_height() + 1;
  }

  template<unsigned int SIZE>
  unsigned int synoptic_internal_array<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_internal_array<SIZE>::m_computed_height = 0;
}

// EOF
