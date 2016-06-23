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

#include <sstream>

namespace sudoku_systemc
{
  //----------------------------------------------------------------------------
  synoptic_bus::synoptic_bus(synoptic::zone_owner_if & p_owner,
			     const std::string & p_name):
    zone_container(p_name, synoptic_bus::get_computed_width(), synoptic_bus::get_computed_height()),
    m_right_arrow(p_owner, p_name + ".R_arrow"),
    m_left_arrow(p_owner, p_name + ".L_arrow", false),
    m_right_line(p_owner, p_name + ".R_line", synoptic_bus::get_computed_width() - m_right_arrow.get_width(), 1, 255, 255, 255),
    m_left_line(p_owner, p_name + ".R_line", synoptic_bus::get_computed_width() - m_right_arrow.get_width(), 1, 255, 255, 255)
  {
    add_zone(synoptic_bus::get_computed_width() - m_right_arrow.get_width(), synoptic_char::get_height() + 1, m_right_arrow);
    add_zone(0, synoptic_char::get_height() + 1 + m_right_arrow.get_height() + 1, m_left_arrow);
    add_zone(0, synoptic_char::get_height() + 1 + ((m_right_arrow.get_height() - 1) / 2), m_right_line);
    add_zone(m_left_arrow.get_width(), synoptic_char::get_height() + 1 + m_right_arrow.get_height() + 1 + ((m_left_arrow.get_height() - 1) / 2), m_left_line);
    for(unsigned int l_index = 0 ; l_index < 3 ; ++l_index)
      {
	std::stringstream l_stream_index;
	l_stream_index << l_index;
	m_cmd[l_index] = new synoptic_char(p_owner, p_name + ".cmd[" + l_stream_index.str() + "]");
	add_zone(4 + l_index * (synoptic_char::get_width() + 1), 0, *m_cmd[l_index]);
      }
    if(!m_color_codes[0])
      {
	m_color_codes[0] = p_owner.get_color_code(255,255,255);
	m_color_codes[1] = p_owner.get_color_code(255,0,0);
	m_color_codes[2] = p_owner.get_color_code(0,255,0);
      }
    m_left_arrow.set_color_code(m_color_codes[0]);
    m_right_arrow.set_color_code(m_color_codes[0]);
  }

  //----------------------------------------------------------------------------
  synoptic_bus::~synoptic_bus(void)
  {
    for(unsigned int l_index = 0 ; l_index < 3 ; ++l_index)
      {
	delete m_cmd[l_index];
      }
  }

  //----------------------------------------------------------------------------
  const unsigned int & synoptic_bus::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //----------------------------------------------------------------------------
  const unsigned int & synoptic_bus::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  void synoptic_bus::compute_dimensions(void)
  {
    m_computed_width = 3 * synoptic_char::get_width() + 10;
    m_computed_height = synoptic_char::get_height() + 2 * ( synoptic_arrow::get_computed_height() + 1);
  }

  //----------------------------------------------------------------------------
  void synoptic_bus::set_acq(bool p_acq)
  {
    m_left_arrow.set_color_code(m_color_codes[1 + p_acq]);
    m_left_arrow.paint();
    m_left_line.set_color_code(m_color_codes[1 + p_acq]);
    m_left_line.paint();
  }

  //----------------------------------------------------------------------------
  void synoptic_bus::set_req(bool p_req)
  {
    m_right_arrow.set_color_code(m_color_codes[1 + p_req]);
    m_right_arrow.paint();
    m_right_line.set_color_code(m_color_codes[1 + p_req]);
    m_right_line.paint();
  }

  //----------------------------------------------------------------------------
  void synoptic_bus::set_message(const std::string & p_msg)
  {
    assert(p_msg.size() < 4);
    for(unsigned int l_index = 0 ; l_index < p_msg.size() ; ++l_index)
      {
	m_cmd[l_index]->set_content(p_msg[l_index]);
	m_cmd[l_index]->paint();
      }
  }

  //----------------------------------------------------------------------------
  void synoptic_bus::no_message(void) 
  {
    for(unsigned int l_index = 0 ; l_index < 3 ; ++l_index)
      {
	m_cmd[l_index]->set_content(' ');
	m_cmd[l_index]->paint();
      }
  }

}
// EOF
