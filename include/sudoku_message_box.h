#ifndef SUDOKU_MESSAGE_BOX_H
#define SUDOKU_MESSAGE_BOX_H

#include "sudoku_message_base.h"

namespace sudoku_systemc
{
  template<unsigned int SIZE>
    class sudoku_message_box
    {
    public:
      sudoku_message_box(void):
	m_empty(true),
	m_message(NULL)
	  {
	  }

	inline void set_message(sudoku_message_base<SIZE> const * p_message)
	  {
	    m_empty = false;
	    m_message = p_message;
	  }

	inline sudoku_message_base<SIZE> const * get_message(void)
	  {
	    sudoku_message_base<SIZE> const * l_result = m_message;
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
	sudoku_message_base<SIZE> const * m_message;
    };
}
#endif // SUDOKU_MESSAGE_BOX_H
//EOF
