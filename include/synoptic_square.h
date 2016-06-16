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
#ifndef _SYNOPTIC_SQUARE_H_
#define _SYNOPTIC_SQUARE_H_

#include "synoptic.h"
#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_char.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class synoptic_square: public synoptic::zone_container
    {
    public:
      /**
	 Representation of sudoku internal square
	 @p_owner synoptic zone that will contain synoptic square instance
	 @p_name name of the instance that will be printed in messages
	 @p_size number of cells per square side
      */
      synoptic_square(synoptic::synoptic & p_owner,
		      const std::string & p_name);
      ~synoptic_square(void);

      inline static const unsigned int & get_computed_width(void);
      inline static const unsigned int & get_computed_height(void);

      inline cell_listener_if & get_cell_listener(const unsigned int & p_x, const unsigned int & p_y);

    private:
      inline static void compute_dimensions(void);

      synoptic::color_zone m_up_border;
      synoptic::color_zone m_right_border;
      synoptic::color_zone m_down_border;
      synoptic::color_zone m_left_border;
      synoptic_char *m_cells[SIZE][SIZE];
    
      static unsigned int m_computed_width;
      static unsigned int m_computed_height;
    };
}

#include "synoptic_square.hpp"

#endif // _SYNOPTIC_SQUARE_H_
// EOF
