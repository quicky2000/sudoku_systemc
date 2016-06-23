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

#ifndef SYNOPTIC_ARRAY_ROW_H
#define SYNOPTIC_ARRAY_ROW_H

#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_char.h"

namespace sudoku_systemc
{
  /**
     Representation of sudoku cell internal count of candidates per value and per group of cell
  */
  template<unsigned int SIZE>
  class synoptic_array_row: public synoptic::zone_container
  {
  public:
    synoptic_array_row(synoptic::zone_owner_if &,
		       const std::string & p_name,
		       char p_label,
		       bool p_init = false);
    ~synoptic_array_row(void);

    inline void set_value(const unsigned int & p_index, const unsigned int & p_value);
    inline void set_char_color_code(const unsigned int & p_index, const uint32_t & p_color_code);
    inline void set_label(const unsigned int & p_code);

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);

  private:
    inline static void compute_dimensions(void);

    synoptic::color_zone m_separator;
    synoptic_char m_label;
    synoptic_char * m_values[SIZE * SIZE];
    
    static unsigned int m_computed_width;
    static unsigned int m_computed_height;
  };
}

#include "synoptic_array_row.hpp"

#endif // SYNOPTIC_ARRAY_ROW_H
// EOF
