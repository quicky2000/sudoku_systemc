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
#endif // SUDOKU_CELL_FSM_STATE_H
