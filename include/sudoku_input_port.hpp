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

//------------------------------------------------------------------------------
template<unsigned int SIZE> 
void sudoku_input_port<SIZE>::operator () (sudoku_bus<SIZE> & p_bus)
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

//------------------------------------------------------------------------------
template<unsigned int SIZE> 
sudoku_input_port<SIZE>::sudoku_input_port(const std::string & p_name):
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

// EOF
