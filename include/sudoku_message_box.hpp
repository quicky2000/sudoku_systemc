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
template<unsigned int SIZE>
sudoku_message_box<SIZE>::sudoku_message_box(void):
  m_empty(true),
  m_message(nullptr)
{
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
void sudoku_message_box<SIZE>::set_message(sudoku_message_base<SIZE> const * p_message)
{
  m_empty = false;
  m_message = p_message;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
sudoku_message_base<SIZE> const * sudoku_message_box<SIZE>::get_message(void)
{
  sudoku_message_base<SIZE> const * l_result = m_message;
  m_empty = true;
  m_message = nullptr;
  return l_result;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
bool sudoku_message_box<SIZE>::is_empty(void)const
{
  return m_empty;
}

// EOF
