/*
    This file is part of sudoku_systemc
    Copyright (C) 2012  Julien Thevenon ( julien_thevenon at yahoo.fr )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
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
    class sudoku_message_invalid_state;

  template<unsigned int SIZE> 
    class sudoku_message_analyser_if
    {
    public:
      virtual void treat(const sudoku_message_set_value<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_release_value<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_check<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_req_hypothesis<SIZE> * p_message)=0;
      virtual void treat(const sudoku_message_set_hyp_level<SIZE>  * p_message)=0;
      virtual void treat(const sudoku_message_invalid_state<SIZE>  * p_message)=0;
      inline virtual ~sudoku_message_analyser_if(){}
    };
}
#endif // SUDOKU_MESSAGE_ANALYSER_IF_H
//EOF
