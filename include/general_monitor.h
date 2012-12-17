#ifndef _GENERAL_MONITOR_H_
#define _GENERAL_MONITOR_H_

#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>

namespace sudoku_systemc
{
  class general_monitor
  {
  public:
    inline general_monitor(void);
    inline void push_hypothesis(const unsigned int & p_x,
				const unsigned int & p_y,
				const unsigned int & p_value);
    inline void pop_hypothesis(const unsigned int & p_x,
			       const unsigned int & p_y,
			       const unsigned int & p_value);
    inline static general_monitor * get_unique_instance(void);
    inline ~general_monitor(void);
    inline void display(void);
  private:
    typedef std::map<std::pair<unsigned int,unsigned int>,std::vector<unsigned int> *> t_hypothesis_db;
    t_hypothesis_db m_hypothesis;
    unsigned int m_nb_hypothesis;
    static general_monitor * m_unique_instance;
  };

  //----------------------------------------------------------------------------
  general_monitor::general_monitor(void):
    m_nb_hypothesis(0)
    {
    }

  //----------------------------------------------------------------------------
  general_monitor * general_monitor::get_unique_instance(void)
    {
      if(m_unique_instance == NULL)
	{
	  m_unique_instance = new general_monitor();
	}
      return m_unique_instance;
    }
  //----------------------------------------------------------------------------
  void general_monitor::push_hypothesis(const unsigned int & p_x,
					const unsigned int & p_y,
					const unsigned int & p_value)
  {
    t_hypothesis_db::iterator l_iter = m_hypothesis.find(std::pair<unsigned int,unsigned int>(p_x,p_y));
    if(l_iter == m_hypothesis.end())
      {
	l_iter = m_hypothesis.insert(t_hypothesis_db::value_type(std::pair<unsigned int,unsigned int>(p_x,p_y),new std::vector<unsigned int>())).first;
      }
    l_iter->second->push_back(p_value);
    ++m_nb_hypothesis;
  }

  //----------------------------------------------------------------------------
  void general_monitor::pop_hypothesis(const unsigned int & p_x,
				       const unsigned int & p_y,
				       const unsigned int & p_value)
  {
    t_hypothesis_db::iterator l_iter = m_hypothesis.find(std::pair<unsigned int,unsigned int>(p_x,p_y));
    assert(l_iter != m_hypothesis.end());
    std::vector<unsigned int>::iterator l_value_iter = l_iter->second->begin();
    while(l_value_iter != l_iter->second->end())
      {
	if(p_value==*l_value_iter)
	  {
	    l_iter->second->erase(l_value_iter);
	    l_value_iter = l_iter->second->end();
	  }
	else
	  {
	    ++l_value_iter;
	  }
      }
    --m_nb_hypothesis;
  }

  //----------------------------------------------------------------------------
  general_monitor::~general_monitor(void)
   {
     for(t_hypothesis_db::iterator l_iter = m_hypothesis.begin();
	 l_iter != m_hypothesis.end();
	 ++l_iter)
       {
	 delete l_iter->second;
       }
   }
  //----------------------------------------------------------------------------
  void general_monitor::display(void)
  {
    std::cout << "Nb hypothesis : " << m_nb_hypothesis << std::endl ;
     for(t_hypothesis_db::iterator l_iter = m_hypothesis.begin();
	 l_iter != m_hypothesis.end();
	 ++l_iter)
       {
	 if(l_iter->second->size())
	   {
	     std::cout << "Cell[" << l_iter->first.first << "," << l_iter->first.second << "] has " << l_iter->second->size() << " pending" << std::endl ;
	     for(std::vector<unsigned int>::const_iterator l_iter_hyp = l_iter->second->begin();
		 l_iter_hyp != l_iter->second->end();
		 ++l_iter_hyp)
	       {
		 std::cout << "\tHyp : " << *l_iter_hyp << std::endl ;
	       }
	   }
       }
  }
}
#endif // _GENERAL_MONITOR_H_
//EOF
