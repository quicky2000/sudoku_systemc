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

#include <sstream>

namespace sudoku_systemc
{
  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  sudoku_bus_probe<SIZE>::sudoku_bus_probe(const sc_module_name p_name, synoptic_bus_listener_if & p_listener):
    sc_module(p_name),
    m_listener(p_listener),
    m_clk("clk"),
    m_req("req"),
    m_acq("acq"),
    m_vertical_group("vertical_group"),
    m_vertical_sub_group("vertical_sub_group"),
    m_horizontal_group("horizontal_group"),
    m_horizontal_sub_group("horizontal_sub_group"),
    m_cmd("cmd"),
    m_data("data")
  {
    SC_METHOD(run);
    sensitive << m_clk;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::bind(const sudoku_bus<SIZE> & p_bus, const sc_signal<bool> & p_clk)
  {
    m_clk(p_clk);
    m_req(p_bus.m_req);
    m_acq(p_bus.m_acq);
    m_vertical_group(p_bus.m_vertical_group);
    m_vertical_sub_group(p_bus.m_vertical_sub_group);
    m_horizontal_group(p_bus.m_horizontal_group);
    m_horizontal_sub_group(p_bus.m_horizontal_sub_group);
    m_cmd(p_bus.m_cmd);
    m_data(p_bus.m_data);
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::run(void)
  {
    m_listener.set_acq(m_acq.read());
    m_listener.set_req(m_req.read());
    if(m_acq.read() && m_req.read())
      {
	sudoku_message_base<SIZE> const * l_message = sudoku_message_factory<SIZE>::decode_message(m_vertical_group.read(),
												   m_vertical_sub_group.read(),
												   m_horizontal_group.read(),
												   m_horizontal_sub_group.read(),
												   m_cmd.read(),
												   m_data.read()
												   );
	l_message->be_treated(this);
	delete l_message;
      }
    else
      {
	m_listener.no_message();
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_set_value<SIZE> * p_message)
  {
    std::stringstream l_stream;
    l_stream << (p_message->get_data().to_uint() + 1);
    m_listener.set_message("SV" + l_stream.str());
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_release_value<SIZE> * p_message)
  {
    std::stringstream l_stream;
    l_stream << (p_message->get_data().to_uint() + 1);
    m_listener.set_message("RV" + l_stream.str());
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_check<SIZE> * p_message)
  {
    m_listener.set_message("CHK");
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_req_hypothesis<SIZE> * p_message)
  {
    std::stringstream l_stream;
    l_stream << p_message->get_data().to_uint();
    m_listener.set_message("RH" + l_stream.str());
 }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_set_hyp_level<SIZE>  * p_message)
  {
    m_listener.set_message("SHY");
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_bus_probe<SIZE>::treat(const sudoku_message_invalid_state<SIZE>  * p_message)
  {
    m_listener.set_message("INV");
  }

}
// EOF
