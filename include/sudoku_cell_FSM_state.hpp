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

namespace sudoku_systemc
{
  //------------------------------------------------------------------------------
  sudoku_cell_FSM_state::sudoku_cell_FSM_state(cell_listener_if & p_listener):
    m_listener(p_listener),
    m_value_sent(false),
    m_check_sent(false),
    m_valid_check(true),
    m_check_granted(false),
    m_hypothesis_sent(false),
    m_hypothesis_accepted(false),
    m_hypothesis_returned(false),
    m_invalid_state(false),
    m_invalid_sent(false),
    m_set_new_level_sent(false)
  {
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALUE_SENT,m_value_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_SENT,m_check_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALID_CHECK,m_valid_check);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_GRANTED,m_check_granted);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_SENT, m_hypothesis_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_ACCEPTED, m_hypothesis_accepted);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_RETURNED, m_hypothesis_returned);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_STATE, m_invalid_state);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_SENT, m_invalid_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::SET_NEW_LEVEL_SENT, m_set_new_level_sent);
  }

  //------------------------------------------------------------------------------
  void sudoku_cell_FSM_state::reset(void)
  {
    m_value_sent = false;
    m_check_sent = false;
    m_valid_check = true;
    m_check_granted = false;
    m_hypothesis_sent = false;
    m_hypothesis_accepted = false;
    m_hypothesis_returned = false;
    m_set_new_level_sent = false;
    m_invalid_state = false;
    m_invalid_sent = false;

    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALUE_SENT,m_value_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_SENT,m_check_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALID_CHECK,m_valid_check);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_GRANTED,m_check_granted);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_SENT, m_hypothesis_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_ACCEPTED, m_hypothesis_accepted);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_RETURNED, m_hypothesis_returned);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_STATE, m_invalid_state);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_SENT, m_invalid_sent);
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::SET_NEW_LEVEL_SENT, m_set_new_level_sent);
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_check_sent(bool p_sent)
  {
    m_check_sent = p_sent;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_SENT,m_check_sent);
    m_valid_check = true;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALID_CHECK,m_valid_check);
    if(p_sent)
      {
	m_check_granted = false;
	m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_GRANTED,m_check_granted);
      }
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_check_sent(void)const
  {
    return m_check_sent;
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::invalid_check(void)
  {
    m_valid_check = false;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALID_CHECK,m_valid_check);
  }
  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_check_valid(void)const
  {
    return m_valid_check;
  }
  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_check_granted(void)
  {
    m_check_granted = true;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::CHECK_GRANTED,m_check_granted);
  }
  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_check_granted(void)const
  {
    return m_check_granted;
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_value_sent(void)const
  {
    return m_value_sent;
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::value_sent(bool p_sent)
  {
    m_value_sent = p_sent;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::VALUE_SENT,m_value_sent);
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_hypothesis_sent(void)const
  {
    return m_hypothesis_sent;
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::hypothesis_sent(bool p_value)
  {
    m_hypothesis_sent = p_value;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_SENT, m_hypothesis_sent);
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_hypothesis_accepted(void)const
  {
    return m_hypothesis_accepted;
  }
    
  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_hypothesis_accepted(bool p_accepted)
  {
    m_hypothesis_accepted = p_accepted;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_ACCEPTED, m_hypothesis_accepted);
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_hypothesis_returned(void)const
  {
    return m_hypothesis_returned;
  }
    
  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_hypothesis_returned(bool p_returned)
  {
    m_hypothesis_returned = p_returned;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::HYPOTHESIS_RETURNED, m_hypothesis_returned);
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_new_level_sent(bool p_sent)
  {
    m_set_new_level_sent = p_sent;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::SET_NEW_LEVEL_SENT, m_set_new_level_sent);
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_new_level_sent(void)const
  {
    return m_set_new_level_sent;
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_invalid_state(void)const
  {
    return m_invalid_state;
  }
  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::set_invalid_state(bool p_invalid)
  {
    m_invalid_state = p_invalid;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_STATE, m_invalid_state);
  }

  //----------------------------------------------------------------------------
  const bool sudoku_cell_FSM_state::is_invalid_sent(void)const
  {
    return m_invalid_sent;
  }

  //----------------------------------------------------------------------------
  void sudoku_cell_FSM_state::invalid_sent(bool p_value)
  {
    m_invalid_sent = p_value;
    m_listener.set_internal_state(cell_listener_if::t_FSM_state::INVALID_SENT, m_invalid_sent);
  }
}
// EOF
