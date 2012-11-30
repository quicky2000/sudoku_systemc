#ifndef S_MESSAGE_ANALYSER_IF_HPP
#define S_MESSAGE_ANALYSER_IF_HPP

template<unsigned int SIZE> 
class S_message_set_value;
template<unsigned int SIZE> 
class S_message_release_value;
template<unsigned int SIZE> 
class S_message_req_hypothesis;

template<unsigned int SIZE> 
class S_message_analyser_if
{
public:
  virtual void treat(S_message_set_value<SIZE> const * p_message)=0;
  virtual void treat(S_message_release_value<SIZE> const * p_message)=0;
  virtual void treat(S_message_req_hypothesis<SIZE> const * p_message)=0;
};
#endif // S_MESSAGE_ANALYSER_IF_HPP
//EOF
