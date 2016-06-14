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
#ifndef SUDOKU_MESSAGE_FACTORY_H
#define SUDOKU_MESSAGE_FACTORY_H

#include "sudoku_message_set_value.h"
#include "sudoku_message_release_value.h"
#include "sudoku_message_check.h"
#include "sudoku_message_req_hypothesis.h"
#include "sudoku_message_set_hyp_level.h"
#include "sudoku_message_invalid_state.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_factory
    {
    public:
      static inline sudoku_message_base<SIZE> const * decode_message(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
								     const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group,
								     const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group,
								     const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group,
								     const typename sudoku_types<SIZE>::t_cmd_type & p_cmd,
								     const typename sudoku_types<SIZE>::t_data_type & p_data)
	{
	  sudoku_message_base<SIZE> *l_result = nullptr;
	  switch((typename sudoku_message_base<SIZE>::t_cmd_message)p_cmd.to_uint())
	    {
	    case sudoku_message_base<SIZE>::t_cmd_message::SET_VALUE:
	      {
		l_result = new sudoku_message_set_value<SIZE>(p_vertical_group,
							      p_vertical_sub_group,
							      p_horizontal_group,
							      p_horizontal_sub_group,
							      p_data);
	      }
	      break;
	    case sudoku_message_base<SIZE>::t_cmd_message::RELEASE_VALUE:
	      l_result = new sudoku_message_release_value<SIZE>(p_vertical_group,
								p_vertical_sub_group,
								p_horizontal_group,
								p_horizontal_sub_group,
								p_data);
	      break;
	    case sudoku_message_base<SIZE>::t_cmd_message::REQ_HYP:
	      l_result = new sudoku_message_req_hypothesis<SIZE>(p_vertical_group,
								 p_vertical_sub_group,
								 p_horizontal_group,
								 p_horizontal_sub_group,
								 p_data);
	      break;
	    case sudoku_message_base<SIZE>::t_cmd_message::CHECK:
	      l_result = new sudoku_message_check<SIZE>(p_vertical_group,
							p_vertical_sub_group,
							p_horizontal_group,
							p_horizontal_sub_group,
							p_data);
	      break;
	    case sudoku_message_base<SIZE>::t_cmd_message::SET_HYP_LEVEL:
	      l_result = new sudoku_message_set_hyp_level<SIZE>(p_vertical_group,
								p_vertical_sub_group,
								p_horizontal_group,
								p_horizontal_sub_group,
								p_data);
	      break;
	    case sudoku_message_base<SIZE>::t_cmd_message::INVALID_STATE:
	      l_result = new sudoku_message_invalid_state<SIZE>(p_vertical_group,
								p_vertical_sub_group,
								p_horizontal_group,
								p_horizontal_sub_group,
								p_data);
	      break;
	    default:
	      std::cout << "ERROR : unkown command field value " << p_cmd.to_uint() << std::endl ;
	      exit(-1);
	    }
	  return l_result;
	}

    private:
    };
}
#endif // SUDOKU_MESSAGE_FACTORY_H
//EOF
