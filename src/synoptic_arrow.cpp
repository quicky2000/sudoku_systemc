/*
  This file is part of sudoku_systemc
  Copyright (C) 2016  Julien Thevenon ( julien_thevenon at yahoo.fr )

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

#include "synoptic_arrow.h"

namespace sudoku_systemc
{
  const unsigned int synoptic_arrow::m_ref_dim = 3;
  std::set<std::pair<unsigned int, unsigned int> > synoptic_arrow::m_left_arrow_pixels;
  std::set<std::pair<unsigned int, unsigned int> > synoptic_arrow::m_right_arrow_pixels;
  unsigned int synoptic_arrow::m_computed_height = 2 * (m_ref_dim - 1) + 1;
}
// EOF
