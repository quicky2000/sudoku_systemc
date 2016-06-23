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
#ifndef SYNOPTIC_INTERNAL_CELL_H
#define SYNOPTIC_INTERNAL_CELL_H

#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_internal_array.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
  class synoptic_internal_cell: public synoptic::zone_container
  {
  public:
    synoptic_internal_cell(synoptic::zone_owner_if &,
			    const std::string & p_name);

    inline void set_horizontal_candidate(const unsigned int & p_index,
					 const unsigned int & p_value);
    inline void set_vertical_candidate(const unsigned int & p_index,
				       const unsigned int & p_value);
    inline void set_square_candidate(const unsigned int & p_index,
				     const unsigned int & p_value);

    inline void set_available_value(const unsigned int & p_index,
				    bool p_value);

    inline void set_release_value(const unsigned int & p_index,
				  bool p_value);

    inline void set_internal_state(const cell_listener_if::t_FSM_state & p_index,
				   bool p_value);

    inline void set_hypothesis_level(const unsigned int & p_level);

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);
  private:
    inline static void compute_dimensions(void);

    synoptic::color_zone m_up_border;
    synoptic::color_zone m_right_border;
    synoptic::color_zone m_down_border;
    synoptic::color_zone m_left_border;
    synoptic_internal_array<SIZE> m_array;
    static unsigned int m_computed_width;
    static unsigned int m_computed_height;
  };
}

#include "synoptic_internal_cell.hpp"

#endif // SYNOPTIC_INTERNAL_CELL_H
// EOF
