#ifndef S_INTERNAL_STATE_HPP
#define S_INTERNAL_STATE_HPP

#include "S_types.h"

template<unsigned int SIZE> 
class S_internal_state
{
public:
  S_internal_state(const unsigned int & p_sub_x,const unsigned int & p_sub_y,const unsigned int & p_initial_value=0):
    //TO DELETE    m_group_vertical_mask(1 << p_sub_x),
    //TO DELETE    m_group_horizontal_mask(1 << p_sub_y),
    m_available_values((1 << S_configuration<SIZE>::m_nb_value) -1),
    m_nb_available_values(p_initial_value != 0 ? 1 : S_configuration<SIZE>::m_nb_value),
    m_values_to_release(0),
    m_value(0),
    m_value_set(false),
    m_value_sent(false),
    m_hypothesis_state(false),
    m_hypothesis_sent(false)
  {
    for(uint32_t l_index = 0 ; l_index < S_configuration<SIZE>::m_nb_value; ++l_index)
      {
        //TO DELETE        m_group_vertical_candidates[l_index] = (1 << SIZE) - 1;
        //TO DELETE        m_group_horizontal_candidates[l_index] = (1 << SIZE) - 1;

        m_vertical_candidates[l_index] = S_configuration<SIZE>::m_nb_value - 1;
        m_horizontal_candidates[l_index] = S_configuration<SIZE>::m_nb_value - 1;
        m_square_candidates[l_index] = S_configuration<SIZE>::m_nb_value - 1;
      }
    if(p_initial_value)
      {
        set_value(p_initial_value-1);
      }
  }

  //TO DELETE  void remove_group_vertical_candidate(const sc_bv<S_utils<SIZE*SIZE>::m_nb_bits_for_value> & p_value, const sc_bv<S_utils<SIZE>::m_nb_bits_for_value> & p_sub_x)
  //TO DELETE  {
  //TO DELETE    assert(p_value.to_uint());
  //TO DELETE    std::cout << "Current group vertical candidate for value " << p_value.to_uint() << " = " << m_group_vertical_candidates[p_value.to_uint()-1].to_uint() << std::endl ;
  //TO DELETE    m_group_vertical_candidates[p_value.to_uint()-1] &= ~(1 << p_sub_x.to_uint());
  //TO DELETE    std::cout << "New group vertical candidate for value " << p_value.to_uint() << " = " << m_group_vertical_candidates[p_value.to_uint()-1].to_uint() << std::endl ;
  //TO DELETE    if(m_available_values[p_value.to_uint()-1] == true && m_group_vertical_candidates[p_value.to_uint()-1] == m_group_vertical_mask && m_group_horizontal_candidates[p_value.to_uint()-1] == m_group_horizontal_mask && m_square_candidates[p_value.to_uint()-1]==1)
  //TO DELETE      {
  //TO DELETE        m_value = p_value;
  //TO DELETE      }
  //TO DELETE  }

  //TO DELETE  void remove_group_horizontal_candidate(const sc_bv<S_utils<SIZE*SIZE>::m_nb_bits_for_value> & p_value, const sc_bv<S_utils<SIZE>::m_nb_bits_for_value> & p_sub_x)
  //TO DELETE  {
  //TO DELETE    assert(p_value.to_uint());
  //TO DELETE    std::cout << "Current group horizontal candidate for value " << p_value.to_uint() << " = " << m_group_horizontal_candidates[p_value.to_uint()-1].to_uint() << std::endl ;
  //TO DELETE    m_group_horizontal_candidates[p_value.to_uint()-1] &= ~(1 << p_sub_x.to_uint());
  //TO DELETE    std::cout << "New group horizontal candidate for value " << p_value.to_uint() << " = " << m_group_horizontal_candidates[p_value.to_uint()-1].to_uint() << std::endl ;
  //TO DELETE    if(m_available_values[p_value.to_uint()-1] == true && m_group_vertical_candidates[p_value.to_uint()-1] == m_group_vertical_mask && m_group_horizontal_candidates[p_value.to_uint()-1] == m_group_horizontal_mask && m_square_candidates[p_value.to_uint()-1]==1)
  //TO DELETE      {
  //TO DELETE        m_value = p_value;
  //TO DELETE      }
  //TO DELETE  }

  unsigned int get_real_value(const typename S_types<SIZE>::t_data_type & p_value)
  {
    return p_value.to_uint()+1;
  }

  // Return true if it was latest candidate
  void remove_vertical_candidate(const typename S_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current vertical candidate for value " << get_real_value(p_value) << " = " << m_vertical_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_vertical_candidates[p_value.to_uint()] = m_vertical_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current vertical candidate for value " << get_real_value(p_value) << " = " << m_vertical_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_vertical_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
        set_value(p_value);
      }
  }

  // Return true if it was latest candidate
  void remove_horizontal_candidate(const typename S_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current horizontal candidate for value " << get_real_value(p_value) << " = " << m_horizontal_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_horizontal_candidates[p_value.to_uint()] = m_horizontal_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current horizontal candidate for value " << get_real_value(p_value) << " = " << m_horizontal_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_horizontal_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
        set_value(p_value);
      }
  }

  // Return true if it was latest candidate
  void remove_square_candidate(const typename S_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current square candidate for value " << get_real_value(p_value) << " = " << m_square_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_square_candidates[p_value.to_uint()] = m_square_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current square candidate for value " << get_real_value(p_value) << " = " << m_square_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_square_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
        set_value(p_value);
      }
  }

  void remove_available_value(const typename S_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current available values " << m_available_values << std::endl ;
    std::cout << "Nb available values " << m_nb_available_values.to_uint() << std::endl ;
    if(m_available_values[p_value.to_uint()] == true) 
      {
        m_available_values[p_value.to_uint()] = false;
        std::cout << "New available values " << m_available_values << std::endl ;
        m_nb_available_values = m_nb_available_values.to_uint() - 1;
        std::cout << "New available values " << m_nb_available_values.to_uint() << std::endl ;
        m_values_to_release[p_value.to_uint()] = true;
        if(m_nb_available_values.to_uint() == 1)
          {
            unsigned int l_index = 0;
            while(m_available_values[l_index] == false)
              {
                ++l_index;
              }
            set_value(l_index);
            assert(m_available_values == 0);
            assert(m_nb_available_values == 0);
          }
      }
  }

  const typename S_types<SIZE>::t_nb_available_values & get_nb_available_values(void)const
  {
    return m_nb_available_values;
  }

  const typename S_types<SIZE>::t_available_values & get_values_to_release(void)const
  {
    return m_values_to_release;
  }

  const typename S_types<SIZE>::t_data_type get_remaining_value(void)
  {
    typename S_types<SIZE>::t_data_type l_index = S_configuration<SIZE>::m_nb_value - 1;
    while(m_values_to_release[l_index.to_uint()]==false)
      {
        l_index = l_index.to_uint()-1;
      }
    m_values_to_release[l_index.to_uint()]= false;
    return l_index;
  }

  //TO DELETE  const typename S_types<SIZE>::t_available_values & get_available_values(void)const
  //TO DELETE  {
  //TO DELETE    return m_available_values;
  //TO DELETE  }

  const typename S_types<SIZE>::t_data_type & get_value(void)const
  {
    assert(m_value_set);
    return m_value;
  }
  const bool is_value_set(void)const
  {
    return m_value_set;
  }
  const bool is_value_sent(void)const
  {
    return m_value_sent;
  }
  void value_sent(bool p_sent)
  {
    m_value_sent = p_sent;
  }

  const bool is_hypothesis_sent(void)const
  {
    return m_hypothesis_sent;
  }

  void hypothesis_sent(void)
  {
    m_hypothesis_sent = true;
  }

  const bool is_hypothesis_state(void)const
  {
    return m_hypothesis_state;
  }

  void hypothesis_state(void)
  {
    m_hypothesis_state = true;
  }
private:
  void set_value(const typename S_types<SIZE>::t_data_type & p_value)
  {
    assert(!m_value_set);
    assert(m_value.to_uint() == 0);
    assert(m_available_values[p_value.to_uint()] == true);
    assert(m_nb_available_values.to_uint());
    m_value_set = true;
    m_value = p_value;
    m_available_values[p_value.to_uint()] = false;
    m_nb_available_values = m_nb_available_values.to_uint() - 1;
    m_values_to_release |= m_available_values;
  }

  //TO DELETE  sc_bv<SIZE> m_group_vertical_candidates[SIZE*SIZE];
  //TO DELETE  sc_bv<SIZE> m_group_vertical_mask;
  //TO DELETE  sc_bv<SIZE> m_group_horizontal_candidates[SIZE*SIZE];
  //TO DELETE  sc_bv<SIZE> m_group_horizontal_mask;

  typename S_types<SIZE>::t_group_candidate m_vertical_candidates[S_configuration<SIZE>::m_nb_value];
  typename S_types<SIZE>::t_group_candidate m_horizontal_candidates[S_configuration<SIZE>::m_nb_value];
  typename S_types<SIZE>::t_group_candidate m_square_candidates[S_configuration<SIZE>::m_nb_value];

  typename S_types<SIZE>::t_available_values m_available_values;
  typename S_types<SIZE>::t_nb_available_values m_nb_available_values;

  typename S_types<SIZE>::t_available_values m_values_to_release;

  typename S_types<SIZE>::t_data_type m_value;
  bool m_value_set;
  bool m_value_sent;

  bool m_hypothesis_state;
  bool m_hypothesis_sent;

};

#endif // S_INTERNAL_STATE_HPP
//EOF
