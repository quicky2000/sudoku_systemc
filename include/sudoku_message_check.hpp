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
sudoku_message_check<SIZE>::sudoku_message_check(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
						 const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group,
						 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group,
						 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group,
						 const typename sudoku_types<SIZE>::t_data_type & p_value):
  sudoku_message_base<SIZE>(p_vertical_group,
			    p_vertical_sub_group,
			    p_horizontal_group,
			    p_horizontal_sub_group,
			    typename sudoku_types<SIZE>::t_cmd_type((int)sudoku_message_base<SIZE>::t_cmd_message::CHECK),
			    p_value)
{
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
void sudoku_message_check<SIZE>::be_treated(sudoku_message_analyser_if<SIZE> * p_analyser)const
{
  assert(p_analyser);
  p_analyser->treat(this);
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
bool sudoku_message_check<SIZE>::is_valid(void)const
{
  return this->get_data().to_uint() & 0x1;
}

// EOF
