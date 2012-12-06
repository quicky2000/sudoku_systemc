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
      //    l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(7,0),8));
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
      //  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(0,7),8));
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
      //  l_init_values.insert(std::map<std::pair<unsigned int,unsigned int>,unsigned int>::value_type(std::pair<unsigned int,unsigned int>(3,2),3));
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
      break;
    case 5:
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
      break;
    case 6:
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
      break;
    default:
      std::cout << "ERROR : unsupported test case index " << l_index << std::endl;
      exit(-1);
    }

  top l_top("S",l_init_values);
  sc_start();
  sc_stop();
  exit(0);
}
//EOF
