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
sudoku_message_base<SIZE>::sudoku_message_base(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
					       const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group,
					       const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group,
					       const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group,
					       const typename sudoku_types<SIZE>::t_cmd_type & p_cmd,
					       const typename sudoku_types<SIZE>::t_data_type & p_data):
  m_vertical_group(p_vertical_group),
  m_vertical_sub_group(p_vertical_sub_group),
  m_horizontal_group(p_horizontal_group),
  m_horizontal_sub_group(p_horizontal_sub_group),
  m_cmd(p_cmd),
  m_data(p_data)
{
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_group_type & sudoku_message_base<SIZE>::get_vertical_group(void)const
{
  return m_vertical_group;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_group_type & sudoku_message_base<SIZE>::get_vertical_sub_group(void)const
{
  return m_vertical_sub_group;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_group_type & sudoku_message_base<SIZE>::get_horizontal_group(void)const
{
  return m_horizontal_group;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_group_type & sudoku_message_base<SIZE>::get_horizontal_sub_group(void)const
{
  return m_horizontal_sub_group;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_cmd_type & sudoku_message_base<SIZE>::get_cmd(void)const
{
  return m_cmd;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const typename sudoku_types<SIZE>::t_data_type & sudoku_message_base<SIZE>::get_data(void)const
{
  return m_data;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
void sudoku_message_base<SIZE>::display(void)const
{
  std::cout << "MESSAGE from [" 
	    << m_vertical_group.to_uint() << "," 
	    << m_vertical_sub_group.to_uint() << "][" 
	    << m_horizontal_group.to_uint() << "," 
	    << m_horizontal_sub_group.to_uint() << "] : "
	    << SIZE * m_vertical_group.to_uint() + m_vertical_sub_group.to_uint() << "_"
	    << SIZE * m_horizontal_group.to_uint() + m_horizontal_sub_group.to_uint() << " "
	    << sudoku_message_base<SIZE>::to_string(m_cmd) << "("
	    << m_data.to_uint()+1 << ")" << std::endl ;
}

//------------------------------------------------------------------------------
template<unsigned int SIZE>
const std::string sudoku_message_base<SIZE>::to_string(const typename sudoku_types<SIZE>::t_cmd_type & p_cmd)
{
  switch((t_cmd_message)p_cmd.to_uint())
    {
    case t_cmd_message::SET_VALUE:
      return "SET_VALUE";
    case t_cmd_message::RELEASE_VALUE:
      return "RELEASE_VALUE";
    case t_cmd_message::CHECK:
      return "CHECK";
    case t_cmd_message::REQ_HYP:
      return "REQ_HYP";
    case t_cmd_message::SET_HYP_LEVEL:
      return "SET_HYP_LEVEL";
    case t_cmd_message::INVALID_STATE:
      return "INVALID_STATE";
    default:
      std::cout << "Unknown cmd value " << p_cmd.to_uint() << std::endl ;
      exit(-1);
    }
}
// EOF
