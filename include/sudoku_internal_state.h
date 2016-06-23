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
#ifndef SUDOKU_INTERNAL_STATE_H
#define SUDOKU_INTERNAL_STATE_H

#include "sudoku_types.h"
#include "cell_listener_if.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE> 
    class sudoku_internal_state
    {
    public:
      sudoku_internal_state(const unsigned int & p_sub_x,const unsigned int & p_sub_y,const unsigned int & p_initial_value, cell_listener_if & p_listener);
      sudoku_internal_state(const sudoku_internal_state<SIZE> & p_initial_state,const unsigned int & p_hypothesis_level);

      unsigned int get_real_value(const typename sudoku_types<SIZE>::t_data_type & p_value)const;
      void remove_vertical_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_horizontal_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_square_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_available_value(const typename sudoku_types<SIZE>::t_data_type & p_value);
      const typename sudoku_types<SIZE>::t_nb_available_values & get_nb_available_values(void)const;
      const typename sudoku_types<SIZE>::t_data_type make_hypothesis(void);
      const typename sudoku_types<SIZE>::t_available_values & get_values_to_release(void)const;
      const typename sudoku_types<SIZE>::t_data_type get_remaining_value(void);

      // Value management
      inline const typename sudoku_types<SIZE>::t_data_type & get_value(void)const;
      inline const bool is_value_set(void)const;
      void set_value(const typename sudoku_types<SIZE>::t_data_type & p_value);

      const unsigned int & get_hypothesis_level(void)const;

      bool is_modified(void)const ;
      void notify_listener(void);

    private:
      void set_horizontal_candidate(const unsigned int & p_index, const typename sudoku_types<SIZE>::t_group_candidate & p_value);
      void set_vertical_candidate(const unsigned int & p_index, const typename sudoku_types<SIZE>::t_group_candidate & p_value);
      void set_square_candidate(const unsigned int & p_index, const typename sudoku_types<SIZE>::t_group_candidate & p_value);
      void set_available_value(const unsigned int & p_index, bool p_value);
      void set_release_value(const unsigned int & p_index, bool p_value);

      cell_listener_if & m_listener;

      typename sudoku_types<SIZE>::t_group_candidate m_vertical_candidates[sudoku_configuration<SIZE>::m_nb_value];
      typename sudoku_types<SIZE>::t_group_candidate m_horizontal_candidates[sudoku_configuration<SIZE>::m_nb_value];
      typename sudoku_types<SIZE>::t_group_candidate m_square_candidates[sudoku_configuration<SIZE>::m_nb_value];

      typename sudoku_types<SIZE>::t_available_values m_available_values;
      typename sudoku_types<SIZE>::t_nb_available_values m_nb_available_values;

      typename sudoku_types<SIZE>::t_available_values m_values_to_release;

      typename sudoku_types<SIZE>::t_data_type m_value;

      bool m_value_set;

      unsigned int m_hypothesis_level;
      bool m_modified;

    };
}

#include "sudoku_internal_state.hpp"

#endif // SUDOKU_INTERNAL_STATE_H
//EOF
