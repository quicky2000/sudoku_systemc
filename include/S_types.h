#ifndef S_TYPES_HPP
#define S_TYPES_HPP

#include "S_configuration.h"
#include "systemc.h"

template<unsigned int SIZE>
class S_types
{
public:
  typedef sc_bv<S_configuration<SIZE>::m_cmd_nb_bits > t_cmd_type;
  typedef sc_bv<S_configuration<SIZE>::m_group_nb_bits > t_group_type;
  typedef sc_bv<S_configuration<SIZE>::m_coded_value_nb_bits> t_data_type;
  typedef sc_bv<S_configuration<SIZE>::m_nb_value> t_available_values;
  typedef sc_bv<S_configuration<SIZE>::m_internal_value_nb_bits> t_nb_available_values;
  typedef sc_bv<S_configuration<SIZE>::m_coded_value_nb_bits> t_group_candidate;
}
;

#endif // S_TYPES_HPP
