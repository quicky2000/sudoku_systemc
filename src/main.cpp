#include "top.h"

int sc_main(int argc, char ** argv)
{
  std::cout << "Receive " << argc << " parameters" << std::endl ;
  if(argc != 2 )
    {
      std::cout << "Usage is sudoku_systemc.exe <index of test case>" << std::endl ;
      exit(-1);
    }
  unsigned int l_index = atoi(argv[1]);
  std::map<std::pair<unsigned int,unsigned int>,unsigned int> l_init_values;
  std::map<std::pair<unsigned int,unsigned int>,unsigned int> l_reference_values;

  switch(l_index)
    {
    case 1:
      // Horizontal
      //  -------------
      //  |123|456|7 9|
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------  
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));
      //  -------------
      //  |123|456|789|
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));
      break;
    case 2:
      // alone candidate
      //  -------------
      //  |1  |   |   |
      //  |   |1  |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |  1|
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |1  |
      //  -------------  
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),1));
      //  -------------
      //  |1  |   |   |
      //  |   |1  |   |
      //  |   |   | 1 |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |  1|
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |1  |
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),1));
      break;
    case 3:
      //Vertical
      //  -------------
      //  |1  |   |   |
      //  |2  |   |   |
      //  |3  |   |   |
      //  -------------
      //  |4  |   |   |
      //  |5  |   |   |
      //  |6  |   |   |
      //  -------------
      //  |7  |   |   |
      //  |   |   |   |
      //  |9  |   |   |
      //  -------------  
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),9));
      //  -------------
      //  |1  |   |   |
      //  |2  |   |   |
      //  |3  |   |   |
      //  -------------
      //  |4  |   |   |
      //  |5  |   |   |
      //  |6  |   |   |
      //  -------------
      //  |7  |   |   |
      //  |8  |   |   |
      //  |9  |   |   |
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),9));
      break;
    case 4:
      // Square
      //  -------------
      //  |   |147|   |
      //  |   |258|   |
      //  |   | 69|   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------  
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),9));
      //  -------------
      //  |   |147|   |
      //  |   |258|   |
      //  |   |369|   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),9));
      break;
    case 5:
      // Single candidate
      //  -------------
      //  |1  |   |   |
      //  |   |1  |   |
      //  |   |   |1  |
      //  -------------
      //  | 1 |   |   |
      //  |   | 1 |   |
      //  |   |   | 1 |
      //  -------------
      //  |  1|   |   |
      //  |   |  1|   |
      //  |   |   |   |
      //  -------------  
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),1));
      //  -------------
      //  |1  |   |   |
      //  |   |1  |   |
      //  |   |   |1  |
      //  -------------
      //  | 1 |   |   |
      //  |   | 1 |   |
      //  |   |   | 1 |
      //  -------------
      //  |  1|   |   |
      //  |   |  1|   |
      //  |   |   |  1|
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),1));
      break;
    case 6:
      //EASY
      //  -------------
      //  |  6| 9 |2  |
      //  |1  |6 8|  7|
      //  | 8 |   | 1 |
      //  -------------
      //  | 37| 5 |46 |
      //  |   |369|   |
      //  | 91| 7 |58 |
      //  -------------
      //  | 2 |   | 9 |
      //  |9  |7 2|  4|
      //  |  8| 3 |1  |
      //  -------------  
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
      //  -------------
      //  |576|193|248|
      //  |149|628|357|
      //  |382|547|916|
      //  -------------
      //  |237|851|469|
      //  |854|369|721|
      //  |691|274|583|
      //  -------------
      //  |723|416|895|
      //  |915|782|634|
      //  |468|935|172|
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),8));


      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),7));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),6));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),9));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),1));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),3));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),5));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),4));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),2));
      break;
    case 7:
      //Medium Genina
      //  -------------
      //  |8  |194|  3|
      //  |  9|   |4  |
      //  |6  |   |  7|
      //  -------------
      //  | 6 |2 8| 1 |
      //  | 2 | 4 | 6 |
      //  | 1 |6 9| 8 |
      //  -------------
      //  |3  |   |  1|
      //  |  5|   |2  |
      //  |2  |576|  9|
      //  -------------  
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
      //  -------------
      //  |872|194|653|
      //  |159|367|428|
      //  |634|825|197|
      //  -------------
      //  |567|238|914|
      //  |928|741|365|
      //  |413|659|782|
      //  -------------
      //  |396|482|571|
      //  |785|913|246|
      //  |241|576|839|
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),3));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),8));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),7));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),4));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),5));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),2));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),1));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),6));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),9));
      break;
    case 8:
      //Hard Genina
      //  -------------
      //  |12 | 84|  5|
      //  |   |6  |3  |
      //  |   |   |  9|
      //  -------------
      //  |   |34 |25 |
      //  | 1 |598| 4 |
      //  | 34| 61|   |
      //  -------------
      //  |2  |   |   |
      //  |  8|  9|   |
      //  |6  |87 | 34|
      //  -------------  
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
      //  -------------
      //  |123|984|765|
      //  |497|615|382|
      //  |865|723|419|
      //  -------------
      //  |986|347|251|
      //  |712|598|643|
      //  |534|261|897|
      //  -------------
      //  |249|136|578|
      //  |378|459|126|
      //  |651|872|934|
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),5));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),2));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),9));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),1));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),3));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),7));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),8));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),6));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),4));
      break;
    case 9:
      //Extreme Genina
      //  -------------
      //  |6 3|  9|  8|
      //  |57 | 4 |  3|
      //  | 2 |  3|   |
      //  -------------
      //  |8  | 3 |   |
      //  | 5 | 1 | 4 |
      //  |   | 2 |  5|
      //  -------------
      //  |   |5  | 7 |
      //  |7  | 6 | 52|
      //  |4  |3  |1 9|
      //  -------------  
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
      //  -------------
      //  |613|759|428|
      //  |578|246|913|
      //  |924|183|567|
      //  -------------
      //  |847|635|291|
      //  |352|917|846|
      //  |196|824|735|
      //  -------------
      //  |231|598|674|
      //  |789|461|352|
      //  |465|372|189|
      //  -------------  
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),8));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),3));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),7));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),1));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),6));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),5));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),4));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),2));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),9));
      break;
    case 10:
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
      
      // Without hypothesis
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

      // With wrong hypothesis
      //  -------------
      //  |531|642|897|
      //  |296|758|143|
      //  |784|931|256|
      //  -------------
      //  |845|276|931|
      //  |312|894|765|
      //  |962|513|487|
      //  -------------
      //  |678|425|319|
      //  |459|387|612|
      //  |123|469|578|
      //  -------------

      // Ok
      //  -------------
      //  |537|641|829|
      //  |296|758|143|
      //  |814|932|756|
      //  -------------
      //  |345|276|981|
      //  |761|894|235|
      //  |982|513|467|
      //  -------------
      //  |678|125|394|
      //  |459|387|612|
      //  |123|469|578|
      //  -------------
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),3));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),6));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),1));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),5));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),7));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),4));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),2));
      
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),8));
      break;
    case 11:
      // Evil
      //  -------------
      //  |   |7  | 9 |
      //  |829| 6 | 47|
      //  | 6 |  3| 5 |
      //  -------------
      //  |  7|   |  9|
      //  | 3 |   | 7 |
      //  |2  |   |6  |
      //  -------------
      //  | 7 |4  | 6 |
      //  |14 | 3 |928|
      //  | 9 |  8|   |
      //  -------------
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),9));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),7));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),5));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),9));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),7));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),6));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),6));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),8));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),8));

      // Solution without hypothesis
      //  -------------
      //  |  3|7  | 96|
      //  |829| 6 |347|
      //  |76 |  3| 5 |
      //  -------------
      //  |  7|   |  9|
      //  |93 |   | 7 |
      //  |2  | 7 |6  |
      //  -------------
      //  | 78|4  | 6 |
      //  |14 | 37|928|
      //  | 92|  8|7 4|
      //  -------------

      // Solution using hypothesis
      //-------------
      //|513|742|896|
      //|829|165|347|
      //|764|893|152|
      //-------------
      //|487|356|219|
      //|936|281|475|
      //|251|974|683|
      //-------------
      //|378|429|561|
      //|145|637|928|
      //|692|518|734|
      //-------------



      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),6));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),7));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),2));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),9));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),5));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),3));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),1));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),8));


      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),4));
      break;
    case 12:
      // Excessive
      //  -------------
      //  | 2 | 6 | 7 |
      //  |9  |3 7|  1|
      //  |  7|   |3  |
      //  -------------
      //  | 8 | 9 | 5 |
      //  |7  |6 2|  3|
      //  | 4 | 5 | 6 |
      //  -------------
      //  |  4|   |9  |
      //  |1  |2 6|  8|
      //  | 3 | 8 | 1 |
      //  -------------
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),7));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),1));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),3));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),5));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),3));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),6));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),9));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),8));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),1));
      // Without hypothesis
      //  -------------
      //  | 2 | 6 | 7 |
      //  |9  |3 7|  1|
      //  |  7|   |3  |
      //  -------------
      //  | 8 | 9 | 5 |
      //  |7  |6 2|  3|
      //  | 4 | 5 | 6 |
      //  -------------
      //  |8 4|   |9  |
      //  |1  |2 6|  8|
      //  | 3 | 8 | 1 |
      //  -------------

      // With hypothesis
      //  -------------
      //  | 2 | 6 | 7 |
      //  |9  |3 7|  1|
      //  |  7|   |3  |
      //  -------------
      //  | 8 | 9 | 5 |
      //  |7  |6 2|  3|
      //  | 4 | 5 | 6 |
      //  -------------
      //  |8 4|   |9  |
      //  |1  |2 6|  8|
      //  | 3 | 8 | 1 |
      //  -------------

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),1));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),3));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),8));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),));
      break;
    case 13:
      // egregious
      //  -------------
      //  |7  |   |4  |
      //  | 3 | 8 | 6 |
      //  |5  |9  |2  |
      //  -------------
      //  |  8|   |  9|
      //  | 1 | 4 | 5 |
      //  |9  |   |1  |
      //  -------------
      //  |  6|  7|  8|
      //  | 7 | 1 | 3 |
      //  |  5|   |  2|
      //  -------------
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),4));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),6));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),2));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),9));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),5));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),1));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),8));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),3));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),2));
      //  -------------
      //  |7  |   |4  |
      //  | 3 | 8 | 6 |
      //  |5  |9  |2  |
      //  -------------
      //  |  8|   |3 9|
      //  | 1 | 49|85 |
      //  |9  |   |1  |
      //  -------------
      //  |  6|  7|  8|
      //  | 7 | 1 | 3 |
      //  |  5|   |  2|
      //  -------------
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),9));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),8));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),2));
      break;
    case 14:
      // Excruciating
      //  -------------
      //  |1  |   |  9|
      //  | 4 |6 9| 5 |
      //  |  9| 2 |4  |
      //  -------------
      //  | 2 |7 6| 4 |
      //  |  1|   |3  |
      //  | 3 |9 5| 2 |
      //  -------------
      //  |  7| 9 |8  |
      //  | 8 |3 4| 1 |
      //  |5  |   |  4|
      //  -------------
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),5));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),4));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),4));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),1));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),3));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),2));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),8));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),1));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),4));
      //  -------------
      //  |1  |   |  9|
      //  | 4 |6 9| 5 |
      //  |  9| 2 |4  |
      //  -------------
      //  | 2 |736| 4 |
      //  |  1|   |3  |
      //  | 34|915| 2 |
      //  -------------
      //  |4 7| 9 |8  |
      //  | 8 |3 4| 1 |
      //  |5 3|   |  4|
      //  -------------
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),9));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),6));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),1));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),4));
      break;
    case 15:
      // Extreme
      //  -------------
      //  |2  |   |  6|
      //  |  5| 2 | 1 |
      //  | 84|  9|3  |
      //  -------------
      //  |   |  3|2  |
      //  | 3 | 9 | 8 |
      //  |  7|5  |   |
      //  -------------
      //  |  6|7  |94 |
      //  | 9 | 3 |7  |
      //  |4  |   |  5|
      //  -------------
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),6));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),5));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),2));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),1));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),8));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),3));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),8));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),5));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),6));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),7));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),4));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),9));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),3));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),7));

      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),4));
      l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),5));
      // Extreme
      //  -------------
      //  |21 |   |  6|
      //  | 65| 2 | 1 |
      //  |784|  9|352|
      //  -------------
      //  |   |  3|2  |
      //  | 3 | 9 |58 |
      //  |  7|5  |   |
      //  -------------
      //  |  6|7  |94 |
      //  | 9 | 3 |7  |
      //  |47 |9  |  5|
      //  -------------
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,0),2));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,0),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,0),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,0),6));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,1),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,1),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,1),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,1),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,1),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,1),1));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,1),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,2),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,2),8));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,2),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,2),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,2),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,2),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,2),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,2),2));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,3),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,3),3));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,3),2));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,3),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,3),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,4),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,4),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,4),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,4),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,4),5));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,4),8));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,4),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,5),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,5),7));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,5),5));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,5),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,5),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,6),6));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,6),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,6),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,6),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,6),9));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,6),4));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,6),));

      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,7),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,7),3));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,7),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,7),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,7),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,7),));

      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,8),4));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(1,8),7));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(2,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,8),9));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(4,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(5,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(6,8),));
      //      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,8),));
      l_reference_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(8,8),5));
      break;
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
      //  |   |   |   |
      //  |   |   |   |
      //  |   |   |   |
      //  -------------
    default:
      std::cout << "ERROR : unsupported test case index " << l_index << std::endl;
      exit(-1);
    }

  top l_top("S",l_init_values);
  sc_start();

  l_top.check(l_reference_values);

  std::cout << l_top.to_string() << std::endl ;

  exit(0);
}
//EOF
