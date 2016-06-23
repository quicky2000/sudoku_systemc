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
#ifndef _SYNOPTIC_GRID_H_
#define _SYNOPTIC_GRID_H_

#include "zone_container.h"
#include "synoptic_square.h"
#include <cassert>

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class synoptic_grid: public synoptic::zone_container
    {
    public:
      synoptic_grid(synoptic::synoptic &p_owner,
		    const std::string & p_name);
      ~synoptic_grid(void);
      inline static const unsigned int & get_computed_width(void);
      inline static const unsigned int & get_computed_height(void);

      inline synoptic_cell & get_cell(const unsigned int & p_x, const unsigned int & p_y);

    private:  
      inline static void compute_dimensions(void);
      synoptic_square<SIZE> *m_squares[SIZE][SIZE];
    
      static unsigned int m_computed_width;
      static unsigned int m_computed_height;
    };
}

#include "synoptic_grid.hpp"

#endif // _SYNOPTIC_GRID_H_
// EOF
