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
#ifndef SYNOPTIC_BUS_H
#define SYNOPTIC_BUS_H

#include "zone_container.h"
#include "color_zone.h"
#include "synoptic_arrow.h"
#include "synoptic_char.h"
#include "synoptic_bus_listener_if.h"

namespace sudoku_systemc
{
  class synoptic_bus: public synoptic::zone_container, public sudoku_systemc::synoptic_bus_listener_if
  {
  public:
    inline synoptic_bus(synoptic::zone_owner_if &,
			const std::string & p_name);
    inline ~synoptic_bus(void);

    // Methods inherited from synoptic_bus_listener_if
    inline void set_acq(bool p_acq) override;
    inline void set_req(bool p_req) override;
    inline void set_message(const std::string & p_msg) override;
    inline void no_message(void) override;
    // End of methods inherited from synoptic_bus_listener_if

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);

  private:
    inline static void compute_dimensions(void);

    synoptic_arrow m_right_arrow;
    synoptic_arrow m_left_arrow;
    synoptic::color_zone m_right_line;
    synoptic::color_zone m_left_line;
    synoptic_char * m_cmd[3];

    static unsigned int m_computed_width;
    static unsigned int m_computed_height;
    static uint32_t m_color_codes[3];
  };

}

#include "synoptic_bus.hpp"

#endif // SYNOPTIC_BUS_H
// EOF
