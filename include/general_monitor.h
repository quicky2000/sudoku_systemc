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
#ifndef _GENERAL_MONITOR_H_
#define _GENERAL_MONITOR_H_

#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>

namespace sudoku_systemc
{
  class general_monitor
  {
  public:
    inline general_monitor(void);
    inline void push_hypothesis(const unsigned int & p_x,
				const unsigned int & p_y,
				const unsigned int & p_value);
    inline void pop_hypothesis(const unsigned int & p_x,
			       const unsigned int & p_y,
			       const unsigned int & p_value);
    inline static general_monitor * get_unique_instance(void);
    inline ~general_monitor(void);
    inline void display(void);
  private:
    typedef std::map<std::pair<unsigned int,unsigned int>,std::vector<unsigned int> *> t_hypothesis_db;
    t_hypothesis_db m_hypothesis;
    unsigned int m_nb_hypothesis;
    static general_monitor * m_unique_instance;
  };

#include "general_monitor.hpp"

}
#endif // _GENERAL_MONITOR_H_
//EOF



