#ifndef _TO_STRING_IF_H_
#define _TO_STRING_IF_H_

class to_string_if
{
 public:
  inline virtual ~to_string_if(void){}
  virtual std::string to_string(void)const=0;
};
#endif //  _TO_STRING_IF_H_
