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
#ifndef SUDOKU_OUTPUT_PORT_H
#define SUDOKU_OUTPUT_PORT_H

#include "sudoku_bus.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE> class sudoku_output_port
    {
    public:
      sc_out<bool> m_req;
      sc_in<bool> m_acq;
      sc_out<typename sudoku_types<SIZE>::t_group_type> m_vertical_group;
      sc_out<typename sudoku_types<SIZE>::t_group_type> m_vertical_sub_group;
      sc_out<typename sudoku_types<SIZE>::t_group_type> m_horizontal_group;
      sc_out<typename sudoku_types<SIZE>::t_group_type> m_horizontal_sub_group;
      sc_out<typename sudoku_types<SIZE>::t_cmd_type> m_cmd;
      sc_out<typename sudoku_types<SIZE>::t_data_type> m_data;

      void operator () (sudoku_bus<SIZE> & p_bus)
      {
	m_req(p_bus.m_req);
	m_acq(p_bus.m_acq);
	m_vertical_group(p_bus.m_vertical_group);
	m_vertical_sub_group(p_bus.m_vertical_sub_group);
	m_horizontal_group(p_bus.m_horizontal_group);
	m_horizontal_sub_group(p_bus.m_horizontal_sub_group);
	m_cmd(p_bus.m_cmd);
	m_data(p_bus.m_data);
      }

      sudoku_output_port(const std::string & p_name):
	m_req((p_name+"_req").c_str()),
	m_acq((p_name+"_acq").c_str()),
	m_vertical_group((p_name+"_vertical_group").c_str()),
	m_vertical_sub_group((p_name+"_vertical_sub_group").c_str()),
	m_horizontal_group((p_name+"_horizontal_group").c_str()),
	m_horizontal_sub_group((p_name+"_horizontal_sub_group").c_str()),
	m_cmd((p_name+"_cmd").c_str()),
	m_data((p_name+"_data").c_str())
	  {
	  }
    private:
    };
}
#endif // SUDOKU_OUTPUT_PORT_H
//EOF
