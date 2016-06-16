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

namespace sudoku_systemc
{

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  sudoku<SIZE>::sudoku(sc_module_name name,
		       const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
    sc_module(name),
    m_clk("clk"),
    m_clk_sig("clk_sig")
  {
    std::cout << "Creation of sudoku" << std::endl ;

    // Array to make bus binding easier
    sudoku_cell<SIZE> * l_cells[SIZE * SIZE * SIZE * SIZE + 1];

    for(uint32_t l_y = 0 ; l_y < SIZE * SIZE ; ++l_y)
      {
	for(uint32_t l_x = 0 ; l_x < SIZE * SIZE ; ++l_x)
	  {
	    uint32_t l_id = l_x + l_y *SIZE *SIZE ; 

	    // Create communication bus
	    std::stringstream l_bus_name_stream;
	    l_bus_name_stream << "Bus_to_" << l_x << "_" << l_y ;
	    m_buses[l_id] = new sudoku_bus<SIZE>(l_bus_name_stream.str().c_str());

	    // Create cell
	    std::map<std::pair<unsigned int,unsigned int>,unsigned int>::const_iterator l_iter = p_init_values.find(std::pair<unsigned int,unsigned int>(l_x,l_y));
	    unsigned int l_init_value = (l_iter == p_init_values.end() ? 0 : l_iter->second);
	    std::stringstream l_cell_name_stream;
	    l_cell_name_stream << "Cell_" << l_x << "_" << l_y ;
	    m_cells2[l_x][l_y] = new sudoku_cell<SIZE>(l_cell_name_stream.str().c_str(),*this,l_x,l_y,l_init_value);
	    m_cells2[l_x][l_y]->m_clk(m_clk_sig);

	    // Store cell for output port binding
	    l_cells[l_id + 1] = m_cells2[l_x][l_y];

	    // Bind bus on cell input
	    m_cells2[l_x][l_y]->m_input_port(*m_buses[l_id]);
	  }
      }

    //Bind buses on cell output
    l_cells[0] = m_cells2[SIZE*SIZE-1][SIZE*SIZE-1];
    for(uint32_t l_id = 0 ; l_id < SIZE*SIZE*SIZE*SIZE; ++l_id)
      {
	l_cells[l_id]->m_output_port(*m_buses[l_id]);
      }

    SC_METHOD(clk_management);
    sensitive << m_clk;
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  sudoku<SIZE>::~sudoku(void)
  {
    for(uint32_t l_x = 0 ; l_x < SIZE * SIZE ; ++l_x)
      {
	for(uint32_t l_y = 0 ; l_y < SIZE * SIZE ; ++l_y)
	  {
	    delete m_cells2[l_x][l_y];
	  }
      }
    for(uint32_t l_id = 0 ; l_id < SIZE * SIZE * SIZE * SIZE; ++l_id)
      {
	delete m_buses[l_id];
      }
  }

  //------------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku<SIZE>::clk_management(void)
  {
    m_clk_sig.write(m_clk.read());
  }

  //------------------------------------------------------------------------
  template<unsigned int SIZE>
  std::string sudoku<SIZE>::to_string(void)const
  {
    std::stringstream l_result;
    unsigned int l_big_side_size = SIZE * SIZE;
    const std::string l_horizontal_separator = std::string(l_big_side_size*4+1,'-');
    const std::string l_horizontal_separator_2 = std::string(l_big_side_size*4+1,'+');
    for(unsigned int l_y = 0; l_y < l_big_side_size ; l_y++)
      {
	if( l_y % SIZE)
	  {
	    l_result << l_horizontal_separator << endl ;
	  }
	else
	  {
	    l_result << l_horizontal_separator_2 << endl ;
	  }

	for(unsigned int l_x = 0; l_x < l_big_side_size ; l_x++)
	  {
	    if( l_x % SIZE)
	      {
		l_result << "  "  ;
	      }
	    else
	      {
		l_result << "| "  ;
	      }
	    if(m_cells2[l_x][l_y]->is_value_set())
	      {
		l_result << m_cells2[l_x][l_y]->get_value().to_uint() + 1 ;
	      }
	    else
	      {
		l_result << " " ;
	      }
	    l_result << " ";
	  }
	l_result << "|" << endl ;
      }
    l_result << l_horizontal_separator << endl ;

    return l_result.str();
  }

  //------------------------------------------------------------------------
  template<unsigned int SIZE>
  bool sudoku<SIZE>::is_cell_value_set(unsigned int p_x,unsigned int p_y)const
  {
    assert(p_x < SIZE * SIZE);
    assert(p_y < SIZE * SIZE);
    return m_cells2[p_x][p_y]->is_value_set();
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  const typename sudoku_types<SIZE>::t_data_type & sudoku<SIZE>::get_cell_value(unsigned int p_x,unsigned int p_y)const
  {
    assert(p_x < SIZE * SIZE);
    assert(p_y < SIZE * SIZE);
    return m_cells2[p_x][p_y]->get_value();
  }
}

// EOF
