#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "systemc.h"
#include "sudoku_cell.h"
#include "sudoku_bus.h"
#include "to_string_if.h"
#include <iostream>
#include <map>

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku:
  public sc_module,
    public to_string_if
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
		  m_cells2[l_x][l_y] = new sudoku_cell<SIZE>(l_cell_name_stream.str().c_str(),*this,l_x,l_y,l_init_value);
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

      bool is_cell_value_set(unsigned int p_x,unsigned int p_y)const;
      const typename sudoku_types<SIZE>::t_data_type & get_cell_value(unsigned int p_x,unsigned int p_y)const;

      sc_in<bool> m_clk;
  private:
      std::string to_string(void)const;

      void clk_management(void)
      {
	m_clk_sig.write(m_clk.read());
      }

      sc_signal<bool> m_clk_sig;
      //TO DELETE  S_cell<SIZE> ***m_cells;
      sudoku_cell<SIZE> *m_cells2[SIZE*SIZE][SIZE*SIZE];
      sudoku_bus<SIZE> *m_buses[SIZE*SIZE*SIZE*SIZE];
  };

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
#endif
//EOF
