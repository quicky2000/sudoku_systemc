/*    This file is part of sudoku_systemc
      The aim of this software is to solvde dicoplus game
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

#ifndef _CELL_LISTENER_IF_H_
#define _CELL_LISTENER_IF_H_
namespace sudoku_systemc
{
  class cell_listener_if
  {
  public:
    virtual void set_value(const unsigned int & p_value, const unsigned int & p_hypothesis_level)=0;
    virtual void clear_value(void)=0;
    virtual void set_hypothesis_level(const unsigned int & p_level)=0;
    virtual void mark_as_initial_value(void)=0;

    inline virtual ~cell_listener_if(void){}
  private:
  };
}

#endif // _CELL_LISTENER_IF_H_
// EOF
