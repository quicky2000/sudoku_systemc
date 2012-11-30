#include "top.hpp"

int sc_main(int argc, char ** argv)
{

  std::map<std::pair<unsigned int,unsigned int>,unsigned int> l_init_values;
#define TEST_CASE_10

#ifdef TEST_CASE_1
  // Horizontal
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),4));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),5));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),6));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),7));
    //    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),8));
    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));
#endif
#ifdef TEST_CASE_2
    // alone candidate
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),1));
#endif
#ifdef TEST_CASE_3
  //Vertical
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),7));
  //  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),9));
#endif

#ifdef TEST_CASE_4
  // Square
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),2));
  //  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),9));
#endif

#ifdef TEST_CASE_5
  //EASY
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),2));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),7));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),6));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),9));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),8));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),9));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
#endif
#ifdef TEST_CASE_6
  // Single candidate
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),1));
#endif
#ifdef TEST_CASE_7
  //Medium Genina
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),7));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),6));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),8));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),2));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),9));

#endif
#ifdef TEST_CASE_8
  //Hard Genina
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),5));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),9));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),5));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),2));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),9));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),4));
#endif
#ifdef TEST_CASE_9
  //Extreme Genina
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),8));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),5));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),7));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),2));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),9));
#endif

#ifdef TEST_CASE_10
  // Diabolic
  //  -------------
  //  | 3 |6  |8  |
  //  |2  |7  |1  |
  //  |  4| 3 | 5 |
  //  -------------
  //  |  5|2  |  1|
  //  |   |894|   |
  //  |9  |  3|4  |
  //  -------------
  //  | 7 | 2 |3  |
  //  |  9|  7|  2|
  //  |  3|  9| 7 |
  //  -------------
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),6));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),8));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),5));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),5));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),1));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),8));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),4));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),2));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),3));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),7));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),2));

  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),3));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),9));
  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),7));
  //  -------------
  //  |53 |6  |8  |
  //  |29 |7  |1 3|
  //  |  4|93 | 5 |
  //  -------------
  //  | 45|276|9 1|
  //  |   |894|  5|
  //  |9  |  3|4  |
  //  -------------
  //  | 7 | 2 |3  |
  //  | 59|3 7|6 2|
  //  | 23| 69|57 |
  //  -------------
#endif

  top l_top("S",l_init_values);
  sc_start();
  exit(0);
}
//EOF
