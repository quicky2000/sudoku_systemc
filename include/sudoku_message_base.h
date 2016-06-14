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
#ifndef SUDOKU_MESSAGE_BASE_H
#define SUDOKU_MESSAGE_BASE_H

#include "sudoku_types.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_analyser_if;

  template<unsigned int SIZE>
    class sudoku_message_base
    {
    public:

      typedef enum class cmd_message {SET_VALUE,RELEASE_VALUE,CHECK,REQ_HYP,SET_HYP_LEVEL,INVALID_STATE} t_cmd_message;

      virtual void be_treated(sudoku_message_analyser_if<SIZE> * p_analyser)const=0;

      sudoku_message_base(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
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

	const typename sudoku_types<SIZE>::t_group_type & get_vertical_group(void)const
	{
	  return m_vertical_group;
	}

	const typename sudoku_types<SIZE>::t_group_type & get_vertical_sub_group(void)const
	{
	  return m_vertical_sub_group;
	}

	const typename sudoku_types<SIZE>::t_group_type & get_horizontal_group(void)const
	{
	  return m_horizontal_group;
	}

	const typename sudoku_types<SIZE>::t_group_type & get_horizontal_sub_group(void)const
	{
	  return m_horizontal_sub_group;
	}

	const typename sudoku_types<SIZE>::t_cmd_type & get_cmd(void)const
	{
	  return m_cmd;
	}

	const typename sudoku_types<SIZE>::t_data_type & get_data(void)const
	{
	  return m_data;
	}

	void display(void)const
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

	static const std::string to_string(const typename sudoku_types<SIZE>::t_cmd_type & p_cmd)
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

	inline virtual ~sudoku_message_base(void){}
    private:
	typename sudoku_types<SIZE>::t_group_type m_vertical_group;
	typename sudoku_types<SIZE>::t_group_type m_vertical_sub_group;
	typename sudoku_types<SIZE>::t_group_type m_horizontal_group;
	typename sudoku_types<SIZE>::t_group_type m_horizontal_sub_group;
	typename sudoku_types<SIZE>::t_cmd_type m_cmd;
	typename sudoku_types<SIZE>::t_data_type m_data;
    };
}
#endif // SUDOKU_MESSAGE_BASE_H
//EOF
