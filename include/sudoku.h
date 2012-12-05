#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "systemc.h"
#include "sudoku_cell.h"
#include "sudoku_bus.h"
#include <iostream>
#include <map>

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku:public sc_module
  {
  public:
    SC_HAS_PROCESS(sudoku);
    sudoku(sc_module_name name,
	   const std::map<std::pair<unsigned int,unsigned int>,unsigned int> & p_init_values):
      sc_module(name),
      m_clk("clk"),
      m_clk_sig("clk_sig")
	{
	  std::cout << "Creation of sudoku" << std::endl ;

	  // Array to make bus binding easier
	  sudoku_cell<SIZE> * l_cells[SIZE*SIZE*SIZE*SIZE+1];

	  //TO DELETE    m_cells = new S_cell<SIZE>**[SIZE*SIZE];
	  for(uint32_t l_y = 0 ; l_y < SIZE * SIZE ; ++l_y)
	    {
	      //TO DELETE        m_cells[l_x] = new S_cell<SIZE>*[SIZE*SIZE];
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
		  m_cells2[l_x][l_y] = new sudoku_cell<SIZE>(l_cell_name_stream.str().c_str(),l_x,l_y,l_init_value);
		  m_cells2[l_x][l_y]->m_clk(m_clk_sig);

		  // Store cell for output port binding
		  l_cells[l_id+1] = m_cells2[l_x][l_y];

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

      ~sudoku(void)
	{
	  for(uint32_t l_x = 0 ; l_x < SIZE * SIZE ; ++l_x)
	    {
	      for(uint32_t l_y = 0 ; l_y < SIZE * SIZE ; ++l_y)
		{
		  delete m_cells2[l_x][l_y];
		}
	      //TO DELETE        delete[] m_cells[l_x];
	    }
	  //TO DELETE    delete[] m_cells;
	  for(uint32_t l_id = 0 ; l_id < SIZE*SIZE*SIZE*SIZE; ++l_id)
	    {
	      delete m_buses[l_id];
	    }
	}

      sc_in<bool> m_clk;
  private:
      void clk_management(void)
      {
	m_clk_sig.write(m_clk.read());
      }

      sc_signal<bool> m_clk_sig;
      //TO DELETE  S_cell<SIZE> ***m_cells;
      sudoku_cell<SIZE> *m_cells2[SIZE*SIZE][SIZE*SIZE];
      sudoku_bus<SIZE> *m_buses[SIZE*SIZE*SIZE*SIZE];
  };
}
#endif
//EOF
