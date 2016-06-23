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
#ifndef SYNOPTIC_ARROW_H
#define SYNOPTIC_ARROW_H

#include "display_zone.h"
#include <set>
#include <cinttypes>

namespace sudoku_systemc
{
  class synoptic_arrow: public synoptic::display_zone
  {
  public:
    inline synoptic_arrow(synoptic::zone_owner_if &,
			  const std::string & p_name,
			  bool p_right = true);
    inline void set_color_code(const uint32_t & p_code);

    inline static const unsigned int & get_computed_width(void);
    inline static const unsigned int & get_computed_height(void);
  private:
    // virtual method inherited from zone
    inline void internal_paint(void) override;
    //end of virtual method inherited from zone

    inline void init(void);

    uint32_t m_current_code;
    const std::set<std::pair<unsigned int, unsigned int> > & m_pixels;

    static const unsigned int m_ref_dim;
    static std::set<std::pair<unsigned int, unsigned int> > m_left_arrow_pixels;
    static std::set<std::pair<unsigned int, unsigned int> > m_right_arrow_pixels;
    static unsigned int m_computed_height;
  };

}

#include "synoptic_arrow.hpp"

#endif // SYNOPTIC_ARROW_H
// EOF
