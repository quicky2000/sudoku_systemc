#ifndef S_MESSAGE_BASE_HPP
#define S_MESSAGE_BASE_HPP

#include "S_types.h"

template<unsigned int SIZE>
class S_message_analyser_if;

template<unsigned int SIZE>
class S_message_base
{
public:

  typedef enum {SET_VALUE,RELEASE_VALUE,REQ_HYP,SET_HYP_LEVEL,INVALID_STATE} t_cmd_message;

  virtual void be_treated(S_message_analyser_if<SIZE> * p_analyser)const=0;

  S_message_base(const typename S_types<SIZE>::t_group_type & p_vertical_group,
                 const typename S_types<SIZE>::t_group_type & p_vertical_sub_group,
                 const typename S_types<SIZE>::t_group_type & p_horizontal_group,
                 const typename S_types<SIZE>::t_group_type & p_horizontal_sub_group,
                 const typename S_types<SIZE>::t_cmd_type & p_cmd,
                 const typename S_types<SIZE>::t_data_type & p_data):
    m_vertical_group(p_vertical_group),
    m_vertical_sub_group(p_vertical_sub_group),
    m_horizontal_group(p_horizontal_group),
    m_horizontal_sub_group(p_horizontal_sub_group),
    m_cmd(p_cmd),
    m_data(p_data)
  {
  }

  const typename S_types<SIZE>::t_group_type & get_vertical_group(void)const
  {
    return m_vertical_group;
  }

  const typename S_types<SIZE>::t_group_type & get_vertical_sub_group(void)const
  {
    return m_vertical_sub_group;
  }

  const typename S_types<SIZE>::t_group_type & get_horizontal_group(void)const
  {
    return m_horizontal_group;
  }

  const typename S_types<SIZE>::t_group_type & get_horizontal_sub_group(void)const
  {
    return m_horizontal_sub_group;
  }

  const typename S_types<SIZE>::t_cmd_type & get_cmd(void)const
  {
    return m_cmd;
  }

  const typename S_types<SIZE>::t_data_type & get_data(void)const
  {
    return m_data;
  }

  void display(void)const
  {
    std::cout << "MESSAGE from [" 
              << m_vertical_group.to_uint() << "," 
              << m_vertical_sub_group.to_uint() << "][" 
              << m_horizontal_group.to_uint() << "," 
              << m_horizontal_sub_group.to_uint() << "] : "
              << S_message_base<SIZE>::to_string(m_cmd) << "("
              << m_data.to_uint()+1 << ")" << std::endl ;
  }

  static const std::string to_string(const typename S_types<SIZE>::t_cmd_type & p_cmd)
  {
    switch(p_cmd.to_uint())
      {
      case SET_VALUE:
        return "SET_VALUE";
      case RELEASE_VALUE:
        return "RELEASE_VALUE";
      case REQ_HYP:
        return "REQ_HYP";
      case SET_HYP_LEVEL:
        return "SET_HYP_LEVEL";
      case INVALID_STATE:
        return "INVALID_STATE";
      default:
        std::cout << "Unknown cmd value " << p_cmd.to_uint() << std::endl ;
        exit(-1);
      }
  }

private:
  typename S_types<SIZE>::t_group_type m_vertical_group;
  typename S_types<SIZE>::t_group_type m_vertical_sub_group;
  typename S_types<SIZE>::t_group_type m_horizontal_group;
  typename S_types<SIZE>::t_group_type m_horizontal_sub_group;
  typename S_types<SIZE>::t_cmd_type m_cmd;
  typename S_types<SIZE>::t_data_type m_data;
};
#endif
