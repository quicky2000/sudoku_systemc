#ifndef S_MESSAGE_BOX_HPP
#define S_MESSAGE_BOX_HPP

#include "S_message_base.h"

template<unsigned int SIZE>
class S_message_box
{
public:
  S_message_box(void):
    m_empty(true),
    m_message(NULL)
  {
  }

  inline void set_message(S_message_base<SIZE> const * p_message)
  {
    m_empty = false;
    m_message = p_message;
  }

  inline S_message_base<SIZE> const * get_message(void)
  {
    S_message_base<SIZE> const * l_result = m_message;
    m_empty = true;
    m_message = NULL;
    return l_result;
  }

  inline bool is_empty(void)const
  {
    return m_empty;
  }
private:
  bool m_empty;
  S_message_base<SIZE> const * m_message;
};

#endif // S_MESSAGE_BOX_HPP
//EOF
