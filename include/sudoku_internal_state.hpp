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

namespace sudoku_systemc
{

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  sudoku_internal_state<SIZE>::sudoku_internal_state(const unsigned int & p_sub_x,
						     const unsigned int & p_sub_y,
						     const unsigned int & p_initial_value,
						     cell_listener_if & p_listener):
    m_listener(p_listener),
    m_available_values((1 << sudoku_configuration<SIZE>::m_nb_value) -1),
    m_nb_available_values(p_initial_value != 0 ? 1 : sudoku_configuration<SIZE>::m_nb_value),
    m_values_to_release(0),
    m_value(0),
    m_value_set(false),
    m_hypothesis_level(0),
    m_modified(false)
  {
    for(uint32_t l_index = 0 ; l_index < sudoku_configuration<SIZE>::m_nb_value; ++l_index)
      {
	m_vertical_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
	m_horizontal_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
	m_square_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
      }
    if(p_initial_value)
      {
	set_value(p_initial_value - 1);
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  sudoku_internal_state<SIZE>::sudoku_internal_state(const sudoku_internal_state<SIZE> & p_initial_state,
						     const unsigned int & p_hypothesis_level):
    m_listener(p_initial_state.m_listener),
    m_available_values(p_initial_state.m_available_values),
    m_nb_available_values(p_initial_state.m_nb_available_values),
    m_values_to_release(p_initial_state.m_values_to_release),
    m_value(p_initial_state.m_value),
    m_value_set(p_initial_state.m_value_set),
    m_hypothesis_level(p_hypothesis_level),
    m_modified(false)
  {
    for(uint32_t l_index = 0 ; l_index < sudoku_configuration<SIZE>::m_nb_value; ++l_index)
      {
	m_vertical_candidates[l_index] = p_initial_state.m_vertical_candidates[l_index];
	m_horizontal_candidates[l_index] = p_initial_state.m_horizontal_candidates[l_index];
	m_square_candidates[l_index] = p_initial_state.m_square_candidates[l_index];
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const typename sudoku_types<SIZE>::t_data_type & sudoku_internal_state<SIZE>::get_value(void)const
  {
    assert(m_value_set);
    return m_value;
  }
  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const bool sudoku_internal_state<SIZE>::is_value_set(void)const
  {
    return m_value_set;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  void sudoku_internal_state<SIZE>::remove_vertical_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current vertical candidate for value " << get_real_value(p_value) << " = " << m_vertical_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_vertical_candidates[p_value.to_uint()] = m_vertical_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current vertical candidate for value " << get_real_value(p_value) << " = " << m_vertical_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_vertical_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
	set_value(p_value);
      }
    m_modified = true;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  void sudoku_internal_state<SIZE>::remove_horizontal_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current horizontal candidate for value " << get_real_value(p_value) << " = " << m_horizontal_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_horizontal_candidates[p_value.to_uint()] = m_horizontal_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current horizontal candidate for value " << get_real_value(p_value) << " = " << m_horizontal_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_horizontal_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
	set_value(p_value);
      }
    m_modified = true;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  void sudoku_internal_state<SIZE>::remove_square_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value)
  {
    std::cout << "Current square candidate for value " << get_real_value(p_value) << " = " << m_square_candidates[p_value.to_uint()].to_uint() << std::endl ;
    m_square_candidates[p_value.to_uint()] = m_square_candidates[p_value.to_uint()].to_uint()-1;
    std::cout << "New current square candidate for value " << get_real_value(p_value) << " = " << m_square_candidates[p_value.to_uint()].to_uint() << std::endl ;
    if(m_square_candidates[p_value.to_uint()] == 0 && m_available_values[p_value.to_uint()] == true)
      {
	set_value(p_value);
      }
    m_modified = true;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  void sudoku_internal_state<SIZE>::remove_available_value(const typename sudoku_types<SIZE>::t_data_type & p_value)
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
	    m_modified = true;
	  }
      }
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const typename sudoku_types<SIZE>::t_data_type sudoku_internal_state<SIZE>::make_hypothesis(void)
  {
    typename sudoku_types<SIZE>::t_data_type l_index = sudoku_configuration<SIZE>::m_nb_value - 1;
    while(m_available_values[l_index.to_uint()]==false)
      {
	l_index = l_index.to_uint()-1;
      }
    return l_index;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const typename sudoku_types<SIZE>::t_nb_available_values & sudoku_internal_state<SIZE>::get_nb_available_values(void)const
  {
    return m_nb_available_values;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const typename sudoku_types<SIZE>::t_available_values & sudoku_internal_state<SIZE>::get_values_to_release(void)const
  {
    return m_values_to_release;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const typename sudoku_types<SIZE>::t_data_type sudoku_internal_state<SIZE>::get_remaining_value(void)
  {
    typename sudoku_types<SIZE>::t_data_type l_index = sudoku_configuration<SIZE>::m_nb_value - 1;
    while(m_values_to_release[l_index.to_uint()]==false)
      {
	l_index = l_index.to_uint()-1;
      }
    m_values_to_release[l_index.to_uint()]= false;
    return l_index;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  const unsigned int & sudoku_internal_state<SIZE>::get_hypothesis_level(void)const
  {
    return m_hypothesis_level;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  bool sudoku_internal_state<SIZE>::is_modified(void)const
  {
    return m_modified;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  void sudoku_internal_state<SIZE>::set_value(const typename sudoku_types<SIZE>::t_data_type & p_value)
  {
    assert(!m_value_set);
    assert(m_value.to_uint() == 0);
    assert(m_available_values[p_value.to_uint()] == true);
    assert(m_nb_available_values.to_uint());
    m_listener.set_value(p_value.to_uint() + 1);
    m_value_set = true;
    m_value = p_value;
    m_available_values[p_value.to_uint()] = false;
    m_nb_available_values = m_nb_available_values.to_uint() - 1;
    m_values_to_release |= m_available_values;
    m_modified = true;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
  unsigned int sudoku_internal_state<SIZE>::get_real_value(const typename sudoku_types<SIZE>::t_data_type & p_value)const
  {
    return p_value.to_uint()+1;
  }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE>
  void sudoku_internal_state<SIZE>::notify_listener(void)
  {
    if(m_value_set)
      {
	m_listener.set_value(m_value.to_uint() + 1);
      }
    else
      {
	m_listener.clear_value();
      }
  }
}
//EOF
