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

#ifndef SYNOPTIC_CELL_H
#define SYNOPTIC_CELL_H

#include "zone_owner_if.h"
#include "zone_container.h"
#include "synoptic_char.h"
#include "cell_listener_if.h"

namespace sudoku_systemc
{
  class synoptic_cell: public synoptic::zone_container, public cell_listener_if
  {
  public:
    inline synoptic_cell(synoptic::zone_owner_if &,
			 const std::string & p_name);
    inline static const uint32_t & get_computed_width(void);
    inline static const uint32_t & get_computed_height(void);

  private:
    // Methods inherited from cell_listener_if
    inline void set_value(const unsigned int & p_value, const unsigned int & p_hypothesis_level) override;
    inline void clear_value(void) override;
    inline void set_hypothesis_level(const unsigned int & p_level) override;
    inline void mark_as_initial_value(void) override;
    // End of methods inherited from cell_listener_if

    synoptic_char m_char_field;
    unsigned int m_hypothesis_level;
  };
}

#include "synoptic_cell.hpp"
#endif // SYNOPTIC_CELL_H

// EOF
