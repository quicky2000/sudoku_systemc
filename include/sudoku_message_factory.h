#ifndef SUDOKU_MESSAGE_FACTORY_H
#define SUDOKU_MESSAGE_FACTORY_H

#include "sudoku_message_set_value.h"
#include "sudoku_message_release_value.h"
#include "sudoku_message_check.h"
#include "sudoku_message_req_hypothesis.h"
#include "sudoku_message_set_hyp_level.h"

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
	  sudoku_message_base<SIZE> *l_result = NULL;
	  switch(p_cmd.to_uint())
	    {
	    case sudoku_message_base<SIZE>::SET_VALUE:
	      {
		l_result = new sudoku_message_set_value<SIZE>(p_vertical_group,
							      p_vertical_sub_group,
							      p_horizontal_group,
							      p_horizontal_sub_group,
							      p_data);
	      }
	      break;
	    case sudoku_message_base<SIZE>::RELEASE_VALUE:
	      l_result = new sudoku_message_release_value<SIZE>(p_vertical_group,
								p_vertical_sub_group,
								p_horizontal_group,
								p_horizontal_sub_group,
								p_data);
	      break;
	    case sudoku_message_base<SIZE>::REQ_HYP:
	      l_result = new sudoku_message_req_hypothesis<SIZE>(p_vertical_group,
								 p_vertical_sub_group,
								 p_horizontal_group,
								 p_horizontal_sub_group,
								 p_data);
	      break;
	    case sudoku_message_base<SIZE>::CHECK:
	      l_result = new sudoku_message_check<SIZE>(p_vertical_group,
							p_vertical_sub_group,
							p_horizontal_group,
							p_horizontal_sub_group,
							p_data);
	      break;
	    case sudoku_message_base<SIZE>::SET_HYP_LEVEL:
	      l_result = new sudoku_message_set_hyp_level<SIZE>(p_vertical_group,
								p_vertical_sub_group,
								p_horizontal_group,
								p_horizontal_sub_group,
								p_data);
	      break;
	    case sudoku_message_base<SIZE>::INVALID_STATE:
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
