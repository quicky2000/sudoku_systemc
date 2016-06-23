/*    This file is part of sudoku_systemc
      The aim of this software is to solve sudoku game
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

#ifndef _SYNOPTIC_CELL_LISTENER_H_
#define _SYNOPTIC_CELL_LISTENER_H_

#include "cell_listener_if.h"
#include "synoptic_internal_cell.h"
#include "synoptic_cell.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
  class synoptic_cell_listener: public cell_listener_if
  {
  public:
    synoptic_cell_listener(synoptic_cell & p_cell, synoptic_internal_cell<SIZE> & p_internal_cell);

    // Methods inherited from cell_listener_if
    void set_value(const unsigned int & p_value, const unsigned int & p_hypothesis_level) override;
    void clear_value(void) override;
    void set_hypothesis_level(const unsigned int & p_level) override;
    void mark_as_initial_value(void) override;
    void set_horizontal_candidate(const unsigned int & p_index,
				  const unsigned int & p_value,
				  const unsigned int & p_hypothesis_level) override;
    void set_vertical_candidate(const unsigned int & p_index,
				const unsigned int & p_value,
				const unsigned int & p_hypothesis_level) override;
    void set_square_candidate(const unsigned int & p_index,
			      const unsigned int & p_value,
			      const unsigned int & p_hypothesis_level) override;
    void set_available_value(const unsigned int & p_index,
			     bool p_value,
			     const unsigned int & p_hypothesis_level) override;

    void set_release_value(const unsigned int & p_index,
			   bool p_value,
			   const unsigned int & p_hypothesis_level) override;
    void set_internal_state(const t_FSM_state & p_index,
			    bool p_value) override;
    // End of methods inherited from cell_listener_if

  private:
    synoptic_cell & m_cell;
    synoptic_internal_cell<SIZE> & m_internal_cell;
    unsigned int m_hypothesis_level;
    bool m_initial_value;
  };
}

#include "synoptic_cell_listener.hpp"

#endif // _SYNOPTIC_CELL_LISTENER_H_
// EOF
