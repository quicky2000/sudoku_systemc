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
#ifndef SYNOPTIC_BUS_LISTENER_IF_H
#define SYNOPTIC_BUS_LISTENER_IF_H

namespace sudoku_systemc
{
  class synoptic_bus_listener_if
  {
  public:
    virtual void set_acq(bool p_acq) = 0;
    virtual void set_req(bool p_req) = 0;
    virtual void set_message(const std::string & p_msg) = 0;
    virtual void no_message(void) = 0;
    virtual ~synoptic_bus_listener_if(void){}
  };
}
#endif // SYNOPTIC_BUS_LISTENER_IF_H
// EOF
