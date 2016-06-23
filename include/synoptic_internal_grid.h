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

#ifndef SYNOPTIC_INTERNAL_GRID_H
#define SYNOPTIC_INTERNAL_GRID_H

#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_internal_cell.h"
#include "synoptic_bus.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
  class synoptic_internal_grid: public synoptic::zone_container
  {
  public:
    synoptic_internal_grid(synoptic::zone_owner_if &,
			    const std::string & p_name);
    ~synoptic_internal_grid(void);

    synoptic_bus_listener_if & get_bus_listener(const unsigned int & p_x, const unsigned int & p_y);
    synoptic_internal_cell<SIZE> & get_cell(const unsigned int & p_x, const unsigned int & p_y);

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);

  private:
    inline static void compute_dimensions(void);

    synoptic_internal_cell<SIZE> * m_cells[SIZE * SIZE][SIZE * SIZE];
    synoptic_bus * m_buses[SIZE * SIZE][SIZE * SIZE];
    static unsigned int m_computed_width;
    static unsigned int m_computed_height;
    static const unsigned int m_space;
  };
}

#include "synoptic_internal_grid.hpp"

#endif // SYNOPTIC_INTERNAL_GRID_H
// EOF
