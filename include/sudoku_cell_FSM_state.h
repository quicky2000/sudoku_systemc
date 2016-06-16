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
#ifndef SUDOKU_CELL_FSM_STATE_H
#define SUDOKU_CELL_FSM_STATE_H

class sudoku_cell_FSM_state
{
 public:
  inline sudoku_cell_FSM_state(void);
  inline void reset(void);

  // Value management
  inline const bool is_value_sent(void)const;
  inline void value_sent(bool p_sent);

  // Hypothesis management
  inline const bool is_hypothesis_sent(void)const;
  inline void hypothesis_sent(bool p_value);
  inline void set_hypothesis_accepted(bool p_accepted);
  inline const bool is_hypothesis_accepted(void)const;
  inline void set_hypothesis_returned(bool p_returned);
  inline const bool is_hypothesis_returned(void)const;

  // Check management
  inline void set_check_sent(bool p_sent);
  inline const bool is_check_sent(void)const;
  inline void invalid_check(void);
  inline const bool is_check_valid(void)const;
  inline void set_check_granted(void);
  inline const bool is_check_granted(void)const;

  // Level management
  inline void set_new_level_sent(bool p_sent);
  inline const bool is_new_level_sent(void)const;

  // Invalid state management
  inline const bool is_invalid_state(void)const;
  inline void set_invalid_state(bool);
  inline const bool is_invalid_sent(void)const;
  inline void invalid_sent(bool p_value);
 private:
  bool m_value_sent;

  bool m_check_sent;
  bool m_valid_check;
  bool m_check_granted;

  bool m_hypothesis_sent;
  bool m_hypothesis_accepted;
  bool m_hypothesis_returned;

  // Invalid state management
  bool m_invalid_state; 
  bool m_invalid_sent;

  bool m_set_new_level_sent;
};

#include "sudoku_cell_FSM_state.hpp"

#endif // SUDOKU_CELL_FSM_STATE_H
// EOF
