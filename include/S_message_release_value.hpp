#ifndef S_MESSAGE_RELEASE_VALUE_HPP
#define S_MESSAGE_RELEASE_VALUE_HPP

#include "S_message_base.hpp"

#include "S_message_analyzer_if.hpp"

template<unsigned int SIZE>
class S_message_release_value: public S_message_base<SIZE>
{
public:
  S_message_release_value(const typename S_types<SIZE>::t_group_type & p_vertical_group,
                          const typename S_types<SIZE>::t_group_type & p_vertical_sub_group,
                          const typename S_types<SIZE>::t_group_type & p_horizontal_group,
                          const typename S_types<SIZE>::t_group_type & p_horizontal_sub_group,
                          const typename S_types<SIZE>::t_data_type & p_value):
    S_message_base<SIZE>(p_vertical_group,
                         p_vertical_sub_group,
                         p_horizontal_group,
                         p_horizontal_sub_group,
                         S_message_base<SIZE>::RELEASE_VALUE,
                         p_value)
  {
  }

  void be_treated(S_message_analyser_if<SIZE> * p_analyser)const
  {
    assert(p_analyser);
    p_analyser->treat(this);
  }
private:
};

#endif // S_MESSAGE_RELEASE_VALUE_HPP
//EOP
