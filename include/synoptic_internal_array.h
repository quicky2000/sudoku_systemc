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

#ifndef SYNOPTIC_INTERNAL_ARRAY_H
#define SYNOPTIC_INTERNAL_ARRAY_H

#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_array_row.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
  class synoptic_internal_array: public synoptic::zone_container
  {
  public:
    synoptic_internal_array(synoptic::zone_owner_if &,
			    const std::string & p_name);

    void set_horizontal_candidate(const unsigned int & p_index,
				  const unsigned int & p_value
				  );
    void set_vertical_candidate(const unsigned int & p_index,
				const unsigned int & p_value
				);
    void set_square_candidate(const unsigned int & p_index,
			      const unsigned int & p_value
			      );
    void set_available_value(const unsigned int & p_index,
			     bool p_value);
    void set_release_value(const unsigned int & p_index,
			   bool p_value);
    void set_internal_state(const cell_listener_if::t_FSM_state & p_index,
			    bool p_value);
    void set_hypothesis_level(const unsigned int & p_level);

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);

  private:
    inline static void compute_dimensions(void);

    synoptic_array_row<SIZE> m_value_row;
    synoptic::color_zone m_separator;
    synoptic_array_row<SIZE> m_h_value_row;
    synoptic_array_row<SIZE> m_v_value_row;
    synoptic_array_row<SIZE> m_s_value_row;
    synoptic_array_row<SIZE> m_a_value_row;
    synoptic_array_row<SIZE> m_r_value_row;
    synoptic_char * m_FSM_state[10];

    uint32_t m_true_color;
    uint32_t m_false_color;
    uint32_t m_black_color;
    uint32_t m_release_color;
    
    static unsigned int m_computed_width;
    static unsigned int m_computed_height;
  };
}

#include "synoptic_internal_array.hpp"

#endif // SYNOPTIC_INTERNAL_ARRAY_H
// EOF
