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
#ifndef _SYNOPTIC_CHAR_H_
#define _SYNOPTIC_CHAR_H_

#include "custom_field_zone.h"
#include "cell_listener_if.h"
#include <map>
#include <cinttypes>
#include <string>

namespace sudoku_systemc
{
  class synoptic_char: public synoptic::custom_field_zone, public cell_listener_if
  {
  public:
    inline synoptic_char(synoptic::zone_owner_if &,
				  const std::string & p_name);
    inline static const uint32_t & get_width(void);
    inline static const uint32_t & get_height(void);
    inline static void init(void);

  private:
    // Methods inherited from custom_field_zone
    inline const uint64_t & get_content_representation(const uint32_t & p_content) override;
    // End of methods inherited from custom_field_zone

    // Methods inherited from cell_listener_if
    inline void set_value(const unsigned int & p_value) override;
    inline void clear_value(void) override;
    // End of methods inherited from cell_listener_if

    typedef std::map<uint32_t,uint64_t> table_t;
    static table_t m_content_representation;
    static const uint64_t m_default_representation;
    static const uint32_t m_width;
    static const uint32_t m_height;
  };

  #include "synoptic_char.hpp"
}

#endif // _SYNOPTIC_CHAR_H_
// EOF
