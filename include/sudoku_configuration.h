#ifndef SUDOKU_CONFIGURATION_H
#define SUDOKU_CONFIGURATION_H

#include "sudoku_utils.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_configuration
    {
    public:
      static const unsigned int m_nb_value;
      static const unsigned int m_nb_cmd;
      static const unsigned int m_group_nb_bits;
      static const unsigned int m_cmd_nb_bits;
      static const unsigned int m_coded_value_nb_bits;
      static const unsigned int m_internal_value_nb_bits;
    }
  ;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_nb_value = SIZE * SIZE;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_nb_cmd = 5;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_group_nb_bits = sudoku_utils<SIZE>::m_nb_bits_for_value;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_cmd_nb_bits = sudoku_utils<m_nb_cmd>::m_nb_bits_for_nb_values;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_coded_value_nb_bits = sudoku_utils<SIZE*SIZE>::m_nb_bits_for_nb_values;
  template<unsigned int SIZE> const unsigned int sudoku_configuration<SIZE>::m_internal_value_nb_bits = sudoku_utils<SIZE*SIZE>::m_nb_bits_for_value;
}
#endif // SUDOKU_CONFIGURATION_H
//EOF
