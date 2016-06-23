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

#ifndef SUDOKU_BUS_PROBE_H
#define SUDOKU_BUS_PROBE_H

#include "systemc.h"
#include "sudoku_types.h"
#include "synoptic_bus_listener_if.h"
#include <string>

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_bus_probe: public sc_module, public sudoku_message_analyser_if<SIZE>
    {
    public:
      SC_HAS_PROCESS(sudoku_bus_probe);
      sudoku_bus_probe(const sc_module_name p_name, synoptic_bus_listener_if & p_listener);
      void bind(const sudoku_bus<SIZE> & p_bus, const sc_signal<bool> & p_clk);
    private:
      void run(void);
      void treat(const sudoku_message_set_value<SIZE> * p_message) override;
      void treat(const sudoku_message_release_value<SIZE> * p_message) override;
      void treat(const sudoku_message_check<SIZE> * p_message) override;
      void treat(const sudoku_message_req_hypothesis<SIZE> * p_message) override;
      void treat(const sudoku_message_set_hyp_level<SIZE>  * p_message) override;
      void treat(const sudoku_message_invalid_state<SIZE>  * p_message) override;

      synoptic_bus_listener_if & m_listener;
      sc_in<bool> m_clk;
      sc_in<bool> m_req;
      sc_in<bool> m_acq;
      sc_in<typename sudoku_types<SIZE>::t_group_type> m_vertical_group;
      sc_in<typename sudoku_types<SIZE>::t_group_type> m_vertical_sub_group;
      sc_in<typename sudoku_types<SIZE>::t_group_type> m_horizontal_group;
      sc_in<typename sudoku_types<SIZE>::t_group_type> m_horizontal_sub_group;
      sc_in<typename sudoku_types<SIZE>::t_cmd_type> m_cmd;
      sc_in<typename sudoku_types<SIZE>::t_data_type> m_data;
    };
}

#include "sudoku_bus_probe.hpp"
#endif // SUDOKU_BUS_PROBE_H
// EOF
