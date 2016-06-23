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
#ifndef _SYNOPTIC_COMPLETE_H_
#define _SYNOPTIC_COMPLETE_H_

#include "zone_container.h"
#include "listener_provider_if.h"
#include "synoptic_grid.h"
#include "synoptic_internal_grid.h"
#include "synoptic_cell_listener.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class synoptic_complete: public synoptic::zone_container, public listener_provider_if
    {
    public:
      synoptic_complete(synoptic::synoptic &p_owner);
      ~synoptic_complete(void);

      inline static const unsigned int & get_computed_width(void);
      inline static const unsigned int & get_computed_height(void);

      inline cell_listener_if & get_cell_listener(const unsigned int & p_x, const unsigned int & p_y) override;
      inline synoptic_bus_listener_if & get_bus_listener(const unsigned int & p_x, const unsigned int & p_y) override;

    private:  
      inline static void compute_dimensions(void);

      synoptic_grid<SIZE> m_grid;
      synoptic_internal_grid<SIZE> m_internal_grid;
      synoptic_cell_listener<SIZE> *m_cell_listeners[SIZE * SIZE][SIZE * SIZE];

      static unsigned int m_computed_width;
      static unsigned int m_computed_height;
    };
}

#include "synoptic_complete.hpp"

#endif // _SYNOPTIC_COMPLETE_H_
// EOF
