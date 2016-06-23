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
  //--------------------------------------------------------------------------
  synoptic_cell::synoptic_cell(synoptic::zone_owner_if & p_owner,
			       const std::string & p_name):
    synoptic::zone_container(p_name,synoptic_cell::get_computed_width(),synoptic_cell::get_computed_height()),
    m_char_field(p_owner,p_name + "_char")
  {
    add_zone(0,0,m_char_field);
    m_char_field.set_content(' ');
  }

  //--------------------------------------------------------------------------
  void synoptic_cell::set_value(const unsigned int & p_value)
  {
    m_char_field.set_content('0' + p_value);
    m_char_field.paint();
  }

  //--------------------------------------------------------------------------
  void synoptic_cell::clear_value(void)
  {
    m_char_field.set_content(' ');
    m_char_field.paint();
  }

  //----------------------------------------------------------------------------
  const uint32_t & synoptic_cell::get_computed_width(void)
  {
    return synoptic_char::get_width();
  }

  //----------------------------------------------------------------------------
  const uint32_t & synoptic_cell::get_computed_height(void)
  {
    return synoptic_char::get_height();
  }

  //----------------------------------------------------------------------------
  void synoptic_cell::mark_as_initial_value(void)
  {
    m_char_field.set_char_color(0,255,0);
  }
}

// EOF
