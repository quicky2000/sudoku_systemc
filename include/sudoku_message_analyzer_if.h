#ifndef SUDOKU_MESSAGE_ANALYSER_IF_H
#define SUDOKU_MESSAGE_ANALYSER_IF_H

namespace sudoku_systemc
{
  template<unsigned int SIZE> 
    class sudoku_message_set_value;
  template<unsigned int SIZE> 
    class sudoku_message_release_value;
  template<unsigned int SIZE> 
    class sudoku_message_req_hypothesis;

  template<unsigned int SIZE> 
    class sudoku_message_analyser_if
    {
    public:
      virtual void treat(sudoku_message_set_value<SIZE> const * p_message)=0;
      virtual void treat(sudoku_message_release_value<SIZE> const * p_message)=0;
      virtual void treat(sudoku_message_req_hypothesis<SIZE> const * p_message)=0;
    };
}
#endif // SUDOKU_MESSAGE_ANALYSER_IF_H
//EOF
