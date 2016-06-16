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

//------------------------------------------------------------------------------
sudoku_cell_FSM_state::sudoku_cell_FSM_state(void):
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
}

//----------------------------------------------------------------------------
void sudoku_cell_FSM_state::set_check_sent(bool p_sent)
{
  m_check_sent = p_sent;
  m_valid_check = true;
  if(p_sent)
    {
      m_check_granted = false;
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
}

//----------------------------------------------------------------------------
void sudoku_cell_FSM_state::set_new_level_sent(bool p_sent)
{
  m_set_new_level_sent = p_sent;
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
}

// EOF
