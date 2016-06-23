/*    This file is part of sudoku_systemc
      The aim of this software is to solvde dicoplus game
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
//----------------------------------------------------------------------------
const uint32_t & synoptic_char::get_width(void)
{
  return m_width;
}
//----------------------------------------------------------------------------
const uint32_t & synoptic_char::get_height(void)
{
  return m_height;
}

//----------------------------------------------------------------------------
void synoptic_char::init(void)
{
  if(!m_content_representation.size())
    {
      // The key is the Unicode code point
      m_content_representation.insert(table_t::value_type(' ', 0x0000000000000));
      m_content_representation.insert(table_t::value_type('A', 0x00454631fc631));
      m_content_representation.insert(table_t::value_type('B', 0x01e4a52e4a53e));
      m_content_representation.insert(table_t::value_type('C', 0x00e8c2108422e));
      m_content_representation.insert(table_t::value_type('D', 0x01e4a5294a53e));
      m_content_representation.insert(table_t::value_type('E', 0x01f8421e8421f));
      m_content_representation.insert(table_t::value_type('F', 0x01f8421e84210));
      m_content_representation.insert(table_t::value_type('G', 0x00e8c2109c62e));
      m_content_representation.insert(table_t::value_type('H', 0x0118c63f8c631));
      m_content_representation.insert(table_t::value_type('I', 0x00e210842108e));
      m_content_representation.insert(table_t::value_type('J', 0x0071084210a4c));
      m_content_representation.insert(table_t::value_type('K', 0x0118ca98a4a31));
      m_content_representation.insert(table_t::value_type('L', 0x010842108421f));
      m_content_representation.insert(table_t::value_type('M', 0x0118eeb58c631));
      m_content_representation.insert(table_t::value_type('N', 0x011ce6b59ce31));
      m_content_representation.insert(table_t::value_type('O', 0x00e8c6318c62e));
      m_content_representation.insert(table_t::value_type('P', 0x01e8c63e84210));
      m_content_representation.insert(table_t::value_type('Q', 0x1d18c6318d5c1));
      m_content_representation.insert(table_t::value_type('R', 0x01e8c63ea4a31));
      m_content_representation.insert(table_t::value_type('S', 0x00e8c20e0862e));
      m_content_representation.insert(table_t::value_type('T', 0x01f2108421084));
      m_content_representation.insert(table_t::value_type('U', 0x0118c6318c62e));
      m_content_representation.insert(table_t::value_type('V', 0x0118c62a52884));
      m_content_representation.insert(table_t::value_type('W', 0x0118c635ad6aa));
      m_content_representation.insert(table_t::value_type('X', 0x0118a94452a31));
      m_content_representation.insert(table_t::value_type('Y', 0x0118a94421084));
      m_content_representation.insert(table_t::value_type('Z', 0x01f088444221f));
      //      m_content_representation.insert(table_t::value_type('0', 0x00E8C6358C62E));
      m_content_representation.insert(table_t::value_type('0', 0x1D18C6B18C62E));
      m_content_representation.insert(table_t::value_type('1', 0x08CA10842109F));
      m_content_representation.insert(table_t::value_type('2', 0x1D1884444420F));
      m_content_representation.insert(table_t::value_type('3', 0x1D1085C10862E));
      m_content_representation.insert(table_t::value_type('4', 0x04654A52F8842));
      m_content_representation.insert(table_t::value_type('5', 0x3F0843C10862E));
      m_content_representation.insert(table_t::value_type('6', 0x1D1842D98C62E));
      m_content_representation.insert(table_t::value_type('7', 0x3E11088442210));
      m_content_representation.insert(table_t::value_type('8', 0x1D18C5D18C62E));
      m_content_representation.insert(table_t::value_type('9', 0x1D18C5E108898));
      m_content_representation.insert(table_t::value_type('#', 0xFFFFFFFFFFFFFFFF));
    }
  else
    {
      throw quicky_exception::quicky_logic_exception("synoptic_char content representation already initialised",__LINE__,__FILE__);
    }
}

//----------------------------------------------------------------------------
synoptic_char::synoptic_char(synoptic::zone_owner_if & p_owner,
			     const std::string & p_name):
  synoptic::custom_field_zone(p_owner,p_name,m_width,m_height)
{
}

//--------------------------------------------------------------------------
const uint64_t & synoptic_char::get_content_representation(const uint32_t & p_content)
{
  std::map<uint32_t,uint64_t>::const_iterator l_iter = m_content_representation.find(p_content);
  if(m_content_representation.end() != l_iter)
    {
      return l_iter->second;
    }
  return m_default_representation;
}

// EOF
