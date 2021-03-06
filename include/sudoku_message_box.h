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
#ifndef SUDOKU_MESSAGE_BOX_H
#define SUDOKU_MESSAGE_BOX_H

#include "sudoku_message_base.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_box
    {
    public:
      sudoku_message_box(void);

      inline void set_message(sudoku_message_base<SIZE> const * p_message);

      inline sudoku_message_base<SIZE> const * get_message(void);

      inline bool is_empty(void)const;

    private:
      bool m_empty;
      sudoku_message_base<SIZE> const * m_message;
    };

#include "sudoku_message_box.hpp"

}
#endif // SUDOKU_MESSAGE_BOX_H
// EOF
