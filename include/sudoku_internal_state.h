#ifndef SUDOKU_INTERNAL_STATE_H
#define SUDOKU_INTERNAL_STATE_H

#include "sudoku_types.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE> 
    class sudoku_internal_state
    {
    public:
      sudoku_internal_state(const unsigned int & p_sub_x,const unsigned int & p_sub_y,const unsigned int & p_initial_value);

      unsigned int get_real_value(const typename sudoku_types<SIZE>::t_data_type & p_value)const;
      void remove_vertical_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_horizontal_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_square_candidate(const typename sudoku_types<SIZE>::t_data_type & p_value);
      void remove_available_value(const typename sudoku_types<SIZE>::t_data_type & p_value);
      const typename sudoku_types<SIZE>::t_nb_available_values & get_nb_available_values(void)const;
      const typename sudoku_types<SIZE>::t_available_values & get_values_to_release(void)const;
      const typename sudoku_types<SIZE>::t_data_type get_remaining_value(void);

      // Value management
      inline const bool is_value_sent(void)const;
      inline void value_sent(bool p_sent);
      inline const typename sudoku_types<SIZE>::t_data_type & get_value(void)const;
      inline const bool is_value_set(void)const;

      // Hypothesis management
      inline const bool is_hypothesis_sent(void)const;
      inline void hypothesis_sent(bool p_value);
      inline void set_hypothesis_accepted(bool p_accepted);
      inline const bool is_hypothesis_accepted(void)const;
      inline void set_hypothesis_returned(bool p_returned);
      inline const bool is_hypothesis_returned(void)const;

      // Check management
      inline void set_check_sent(bool p_sent);
      inline const bool is_check_sent(void)const;
      inline void invalid_check(void);
      inline const bool is_check_valid(void)const;
      inline void set_check_granted(void);
      inline const bool is_check_granted(void)const;

      // Level management
      inline void set_new_level_sent(bool p_sent);
      inline const bool is_new_level_sent(void)const;
      const unsigned int & get_hypothesis_level(void)const;

    private:
      void set_value(const typename sudoku_types<SIZE>::t_data_type & p_value);

      typename sudoku_types<SIZE>::t_group_candidate m_vertical_candidates[sudoku_configuration<SIZE>::m_nb_value];
      typename sudoku_types<SIZE>::t_group_candidate m_horizontal_candidates[sudoku_configuration<SIZE>::m_nb_value];
      typename sudoku_types<SIZE>::t_group_candidate m_square_candidates[sudoku_configuration<SIZE>::m_nb_value];

      typename sudoku_types<SIZE>::t_available_values m_available_values;
      typename sudoku_types<SIZE>::t_nb_available_values m_nb_available_values;

      typename sudoku_types<SIZE>::t_available_values m_values_to_release;

      typename sudoku_types<SIZE>::t_data_type m_value;
      bool m_value_set;
      bool m_value_sent;

      bool m_check_sent;
      bool m_valid_check;
      bool m_check_granted;

      bool m_hypothesis_sent;
      bool m_hypothesis_accepted;
      bool m_hypothesis_returned;

      bool m_set_new_level_sent;
      unsigned int m_hypothesis_level;
    };

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
    void sudoku_internal_state<SIZE>::set_check_sent(bool p_sent)
    {
      m_check_sent = p_sent;
      m_valid_check = true;
      if(p_sent)
	{
	  m_check_granted = false;
	}
    }
  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    const bool sudoku_internal_state<SIZE>::is_check_sent(void)const
    {
      return m_check_sent;
    }

  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    void sudoku_internal_state<SIZE>::invalid_check(void)
    {
      m_valid_check = false;
    }
  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    const bool sudoku_internal_state<SIZE>::is_check_valid(void)const
    {
      return m_valid_check;
    }
  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    void sudoku_internal_state<SIZE>::set_check_granted(void)
    {
      m_check_granted = true;
    }
  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    const bool sudoku_internal_state<SIZE>::is_check_granted(void)const
    {
      return m_check_granted;
    }


  //----------------------------------------------------------------------------
  template<unsigned int SIZE> 
    sudoku_internal_state<SIZE>::sudoku_internal_state(const unsigned int & p_sub_x,const unsigned int & p_sub_y,const unsigned int & p_initial_value=0):
    m_available_values((1 << sudoku_configuration<SIZE>::m_nb_value) -1),
    m_nb_available_values(p_initial_value != 0 ? 1 : sudoku_configuration<SIZE>::m_nb_value),
    m_values_to_release(0),
    m_value(0),
    m_value_set(false),
    m_value_sent(false),
    m_check_sent(false),
    m_valid_check(true),
    m_check_granted(false),
    m_hypothesis_sent(false),
    m_hypothesis_accepted(false),
    m_hypothesis_returned(false),
    m_set_new_level_sent(false),
    m_hypothesis_level(0)
      {
	for(uint32_t l_index = 0 ; l_index < sudoku_configuration<SIZE>::m_nb_value; ++l_index)
	  {
	    m_vertical_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
	    m_horizontal_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
	    m_square_candidates[l_index] = sudoku_configuration<SIZE>::m_nb_value - 1;
	  }
	if(p_initial_value)
	  {
	    set_value(p_initial_value-1);
	  }
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
	    m_hypothesis_sent = false;
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
      const bool sudoku_internal_state<SIZE>::is_value_sent(void)const
      {
	return m_value_sent;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      void sudoku_internal_state<SIZE>::value_sent(bool p_sent)
      {
	m_value_sent = p_sent;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      const bool sudoku_internal_state<SIZE>::is_hypothesis_sent(void)const
      {
	return m_hypothesis_sent;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      void sudoku_internal_state<SIZE>::hypothesis_sent(bool p_value)
      {
	m_hypothesis_sent = p_value;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      const bool sudoku_internal_state<SIZE>::is_hypothesis_accepted(void)const
      {
	return m_hypothesis_accepted;
      }
    
    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
    void sudoku_internal_state<SIZE>::set_hypothesis_accepted(bool p_accepted)
      {
	m_hypothesis_accepted = p_accepted;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      const bool sudoku_internal_state<SIZE>::is_hypothesis_returned(void)const
      {
	return m_hypothesis_returned;
      }
    
    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
    void sudoku_internal_state<SIZE>::set_hypothesis_returned(bool p_returned)
      {
	m_hypothesis_returned = p_returned;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      void sudoku_internal_state<SIZE>::set_new_level_sent(bool p_sent)
      {
	m_set_new_level_sent = p_sent;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      const bool sudoku_internal_state<SIZE>::is_new_level_sent(void)const
      {
	return m_set_new_level_sent;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      const unsigned int & sudoku_internal_state<SIZE>::get_hypothesis_level(void)const
      {
	return m_hypothesis_level;
      }

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      void sudoku_internal_state<SIZE>::set_value(const typename sudoku_types<SIZE>::t_data_type & p_value)
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

    //----------------------------------------------------------------------------
    template<unsigned int SIZE> 
      unsigned int sudoku_internal_state<SIZE>::get_real_value(const typename sudoku_types<SIZE>::t_data_type & p_value)const
      {
	return p_value.to_uint()+1;
      }


}
#endif // SUDOKU_INTERNAL_STATE_H
//EOF
