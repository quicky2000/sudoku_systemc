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
								     const typename sudoku_types<SIZE>::t_data_type & p_data);
    private:
    };

#include "sudoku_message_factory.hpp"

}
#endif // SUDOKU_MESSAGE_FACTORY_H
// EOF
