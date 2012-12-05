#ifndef SUDOKU_TYPES_H
#define SUDOKU_TYPES_H

#include "sudoku_configuration.h"
#include "systemc.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_types
    {
    public:
      typedef sc_bv<sudoku_configuration<SIZE>::m_cmd_nb_bits > t_cmd_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_group_nb_bits > t_group_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_coded_value_nb_bits> t_data_type;
      typedef sc_bv<sudoku_configuration<SIZE>::m_nb_value> t_available_values;
      typedef sc_bv<sudoku_configuration<SIZE>::m_internal_value_nb_bits> t_nb_available_values;
      typedef sc_bv<sudoku_configuration<SIZE>::m_coded_value_nb_bits> t_group_candidate;
    }
  ;
}
#endif // SUDOKU_TYPES_H
//EOF
