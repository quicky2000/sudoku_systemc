#ifndef SUDOKU_MESSAGE_ANALYSER_IF_H
#define SUDOKU_MESSAGE_ANALYSER_IF_H

namespace sudoku_systemc
{
  template<unsigned int SIZE> 
    class sudoku_message_set_value;
  template<unsigned int SIZE> 
    class sudoku_message_release_value;
  template<unsigned int SIZE> 
    class sudoku_message_check;
  template<unsigned int SIZE> 
    class sudoku_message_req_hypothesis;
  template<unsigned int SIZE> 
    class sudoku_message_set_hyp_level;

  template<unsigned int SIZE> 
    class sudoku_message_analyser_if
    {
    public:
      virtual void treat(const sudoku_message_set_value<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_release_value<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_check<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_req_hypothesis<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_set_hyp_level<SIZE>  * p_message)=0;
      inline virtual ~sudoku_message_analyser_if(){}
    };
}
#endif // SUDOKU_MESSAGE_ANALYSER_IF_H
//EOF
