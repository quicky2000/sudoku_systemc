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

#include <cassert>

namespace sudoku_systemc
{
  //----------------------------------------------------------------------------
  synoptic_arrow::synoptic_arrow(synoptic::zone_owner_if & p_owner,
				 const std::string & p_name,
				 bool p_right):
    synoptic::display_zone(p_owner, p_name, m_ref_dim, m_computed_height),
    m_current_code(0),
    m_pixels(p_right ? m_right_arrow_pixels : m_left_arrow_pixels)
  {
    if(!m_pixels.size())
      {
	init();
      }
  }

  //----------------------------------------------------------------------------
  void synoptic_arrow::set_color_code(const uint32_t & p_code)
  {
    m_current_code = p_code;
  }

  //----------------------------------------------------------------------------
  void synoptic_arrow::init(void)
  {
    for(unsigned int l_index = 0; l_index < m_ref_dim - 1; ++l_index)
      {
	m_right_arrow_pixels.insert(std::pair<unsigned int, unsigned int>(l_index, l_index));
	m_right_arrow_pixels.insert(std::pair<unsigned int, unsigned int>(l_index, 2 * (m_ref_dim - 1) - l_index));		  
      }
    for(unsigned int l_index = 0; l_index < m_ref_dim; ++l_index)
      {
	m_right_arrow_pixels.insert(std::pair<unsigned int, unsigned int>(l_index, m_ref_dim - 1));		  
      }
    for(auto l_iter: m_right_arrow_pixels)
      {
	m_left_arrow_pixels.insert(std::pair<unsigned int, unsigned int>(m_ref_dim - l_iter.first - 1, l_iter.second));
      }
    
  }

  //----------------------------------------------------------------------------
  const unsigned int & synoptic_arrow::get_computed_width(void)
  {
    return m_ref_dim;
  }

  //----------------------------------------------------------------------------
  const unsigned int & synoptic_arrow::get_computed_height(void)
  {
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  void synoptic_arrow::internal_paint(void)
  {
    for(auto l_iter: m_pixels)
      {
	set_pixel(l_iter.first, l_iter.second, m_current_code);
      }
  }


}
// EOF
