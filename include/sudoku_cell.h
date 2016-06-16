/*
    This file is part of sudoku_systemc
    Copyright (C) 2012  Julien Thevenon ( julien_thevenon at yahoo.fr )

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
#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

#include "systemc.h"
#include <iostream>
#include <sstream>
#include <inttypes.h>
#include "sudoku_input_port.h"
#include "sudoku_output_port.h"
#include "sudoku_message_box.h"
#include "sudoku_message_factory.h"
#include "sudoku_internal_state.h"
#include "sudoku_cell_FSM_state.h"
#include "sudoku_message_analyzer_if.h"

#include "general_monitor.h"
#include "to_string_if.h"
namespace sudoku_systemc
{
  template<unsigned int SIZE,unsigned int MAX_NB_STATE = SIZE * SIZE>
    class sudoku_cell:public sc_module,
    public sudoku_message_analyser_if<SIZE>
    {
      public:
      SC_HAS_PROCESS(sudoku_cell);
      sudoku_cell(sc_module_name name,
		  const to_string_if & p_whole,
		  const uint32_t & p_x,
		  const uint32_t & p_y,
		  cell_listener_if & p_listener,
		  const uint32_t p_init_value=0);

      bool is_value_set(void)const;
      const typename sudoku_types<SIZE>::t_data_type & get_value(void)const;

      sc_in<bool> m_clk;
      sudoku_input_port<SIZE> m_input_port;
      sudoku_output_port<SIZE> m_output_port;
      private:
      void print_name(void);
      void delete_message(const sudoku_message_base<SIZE>* p_message);
      void treat_common(const sudoku_message_base<SIZE>* p_message);
      void treat(const sudoku_message_set_value<SIZE>* p_message);
      void treat(const sudoku_message_check<SIZE>* p_message);
      void treat(const sudoku_message_release_value<SIZE>* p_message);
      void treat(const sudoku_message_req_hypothesis<SIZE>* p_message);
      void treat(const sudoku_message_set_hyp_level<SIZE>* p_message);
      void treat(const sudoku_message_invalid_state<SIZE>* p_message);
 
      inline bool is_mine(const sudoku_message_base<SIZE> * const p_message)const;
      inline const sudoku_message_base<SIZE> * const generate_message_to_send(void);

      void run(void);
      void listen_input_port(void);
      void manage_output_port(void);

      bool less_than_position(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group1,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group2,
			      const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group2);


      const to_string_if & m_whole;
      // Coordinates informations
      const uint32_t m_x;
      const uint32_t m_y;
      const uint32_t m_id;
      // Group and subgroup informations
      const uint32_t m_vertical_group;
      const uint32_t m_vertical_sub_group;
      const uint32_t m_horizontal_group;
      const uint32_t m_horizontal_sub_group;

      sudoku_internal_state<SIZE> * m_internal_states[MAX_NB_STATE];
      sudoku_message_box<SIZE> m_input_box;
      sudoku_message_box<SIZE> m_output_box;
      uint32_t m_activity_counter;
      const sudoku_message_base<SIZE> * m_message_to_forward;
      unsigned int m_general_hypothesis_level;
      unsigned int m_nb_state;

      sudoku_cell_FSM_state m_FSM_state;

      // Simulation stop management
      static bool m_sc_stop_called;
    };

  #include "sudoku_cell.hpp"
}
#endif // SUDOKU_CELL_H
//EOF
