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
  synoptic_array_row<SIZE>::synoptic_array_row(synoptic::zone_owner_if & p_owner,
					       const std::string & p_name,
					       char p_label,
					       bool p_init):
    zone_container(p_name, synoptic_array_row<SIZE>::get_computed_width(), synoptic_array_row<SIZE>::get_computed_height()),
    m_separator(p_owner, p_name + ".separator", 1, synoptic_array_row<SIZE>::get_computed_height(), 255, 255, 255),
    m_label(p_owner, p_name + ".label")
  {
    m_label.set_content(p_label);
    add_zone(1,1,m_label);
    add_zone(1 + synoptic_char::get_width() + 1, 0, m_separator);

    for(unsigned int l_value = 0 ; l_value < SIZE * SIZE ; ++l_value)
      {
	std::stringstream l_stream;
	l_stream << l_value;
	m_values[l_value] = new synoptic_char(p_owner, p_name + ".c[" + + "]");
	m_values[l_value]->set_content(p_init ? '1' + l_value : ' ');
	add_zone(4 + synoptic_char::get_width() + l_value * (synoptic_char::get_width() + 1), 1, *m_values[l_value]);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  synoptic_array_row<SIZE>::~synoptic_array_row(void)
  {
    for(unsigned int l_value = 0 ; l_value < SIZE * SIZE ; ++l_value)
      {
	delete m_values[l_value];
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_array_row<SIZE>::set_label(const unsigned int & p_code)
  {
    m_label.set_content(p_code);
    m_label.paint();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_array_row<SIZE>::set_value(const unsigned int & p_index, const unsigned int & p_value)
  {
    assert(p_index < SIZE * SIZE);
    m_values[p_index]->set_content('0' + p_value);
    m_values[p_index]->paint();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_array_row<SIZE>::set_char_color_code(const unsigned int & p_index, const uint32_t & p_color_code)
  {
    assert(p_index < SIZE * SIZE);
    m_values[p_index]->set_char_color(p_color_code);
    m_values[p_index]->paint();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_array_row<SIZE>::get_computed_width(void)
  {
    if(!m_computed_width)
      {
	compute_dimensions();
      }
    return m_computed_width;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const unsigned int & synoptic_array_row<SIZE>::get_computed_height(void)
  {
    if(!m_computed_height)
      {
	compute_dimensions();
      }
    return m_computed_height;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void synoptic_array_row<SIZE>::compute_dimensions(void)
  {
    m_computed_width = (1 + synoptic_char::get_width()) * ( 1 + SIZE * SIZE) + 3;
    m_computed_height = synoptic_char::get_height() + 2;
  }

  template<unsigned int SIZE>
  unsigned int synoptic_array_row<SIZE>::m_computed_width = 0;

  template<unsigned int SIZE>
  unsigned int synoptic_array_row<SIZE>::m_computed_height = 0;
}

// EOF
