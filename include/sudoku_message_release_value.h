#ifndef SUDOKU_MESSAGE_RELEASE_VALUE_H
#define SUDOKU_MESSAGE_RELEASE_VALUE_H

#include "sudoku_message_base.h"
#include "sudoku_message_analyzer_if.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_release_value: public sudoku_message_base<SIZE>
  {
  public:
    sudoku_message_release_value(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group,
				 const typename sudoku_types<SIZE>::t_data_type & p_value):
      sudoku_message_base<SIZE>(p_vertical_group,
				p_vertical_sub_group,
				p_horizontal_group,
				p_horizontal_sub_group,
				sudoku_message_base<SIZE>::RELEASE_VALUE,
				p_value)
      {
      }

      void be_treated(sudoku_message_analyser_if<SIZE> * p_analyser)const
      {
	assert(p_analyser);
	p_analyser->treat(this);
      }
  private:
  };
}
#endif // SUDOKU_MESSAGE_RELEASE_VALUE_H
//EOP