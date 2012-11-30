#ifndef S_MESSAGE_FACTORY_HPP
#define S_MESSAGE_FACTORY_HPP

#include "S_message_set_value.hpp"
#include "S_message_release_value.hpp"
#include "S_message_req_hypothesis.hpp"

template<unsigned int SIZE>
class S_message_factory
{
public:
  static inline S_message_base<SIZE> const * decode_message(const typename S_types<SIZE>::t_group_type & p_vertical_group,
                                                            const typename S_types<SIZE>::t_group_type & p_vertical_sub_group,
                                                            const typename S_types<SIZE>::t_group_type & p_horizontal_group,
                                                            const typename S_types<SIZE>::t_group_type & p_horizontal_sub_group,
                                                            const typename S_types<SIZE>::t_cmd_type & p_cmd,
                                                            const typename S_types<SIZE>::t_data_type & p_data)
  {
    S_message_base<SIZE> *l_result = NULL;
    switch(p_cmd.to_uint())
      {
      case S_message_base<SIZE>::SET_VALUE:
        {
          l_result = new S_message_set_value<SIZE>(p_vertical_group,
                                                   p_vertical_sub_group,
                                                   p_horizontal_group,
                                                   p_horizontal_sub_group,
                                                   p_data);
        }
        break;
      case S_message_base<SIZE>::RELEASE_VALUE:
          l_result = new S_message_release_value<SIZE>(p_vertical_group,
                                                       p_vertical_sub_group,
                                                       p_horizontal_group,
                                                       p_horizontal_sub_group,
                                                       p_data);
        break;
      case S_message_base<SIZE>::REQ_HYP:
          l_result = new S_message_req_hypothesis<SIZE>(p_vertical_group,
                                                        p_vertical_sub_group,
                                                        p_horizontal_group,
                                                        p_horizontal_sub_group,
                                                        p_data);
        break;
      case S_message_base<SIZE>::SET_HYP_LEVEL:
        break;
      case S_message_base<SIZE>::INVALID_STATE:
        break;
      default:
        std::cout << "ERROR : unkown command field value " << p_cmd.to_uint() << std::endl ;
        exit(-1);
      }
    return l_result;
  }

private:
};

#endif // S_MESSAGE_FACTORY_HPP
//EOF
