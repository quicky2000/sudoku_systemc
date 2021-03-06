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
#ifndef SUDOKU_MESSAGE_INVALID_STATE_H
#define SUDOKU_MESSAGE_INVALID_STATE_H

#include "sudoku_message_base.h"
#include "sudoku_message_analyzer_if.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_invalid_state: public sudoku_message_base<SIZE>
  {
  public:
    sudoku_message_invalid_state(const typename sudoku_types<SIZE>::t_group_type & p_vertical_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_vertical_sub_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_group,
				 const typename sudoku_types<SIZE>::t_group_type & p_horizontal_sub_group,
				 const typename sudoku_types<SIZE>::t_data_type & p_value);

    void be_treated(sudoku_message_analyser_if<SIZE> * p_analyser)const override;

  private:
  };

#include "sudoku_message_invalid_state.hpp"

}
#endif // SUDOKU_MESSAGE_INVALID_STATE_H
// EOF
