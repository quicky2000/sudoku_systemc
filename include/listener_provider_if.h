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

#ifndef _LISTENER_PROVIDER_IF_
#define _LISTENER_PROVIDER_IF_
namespace sudoku_systemc
{
  class cell_listener_if;

  /**
     Interface to provide cell listeners
   */
  class listener_provider_if
  {
  public:
    /**
       Return reference on cell listener dedicated to sudoku cell whose coordinates are provided in parameters
       @param p_x cell abscissa
       @param p_y cell ordinate
       @return reference on cell listener dedicated to sudoku cell whose coordinates are provided in parameters
     */
    virtual cell_listener_if & get_cell_listener(const unsigned int & p_x, const unsigned int & p_y)=0;

    inline virtual ~listener_provider_if(void){}
  private:
  };
}

#endif // _LISTENER_PROVIDER_IF_
// EOF
