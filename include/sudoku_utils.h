#ifndef SUDOKU_UTILS_HPP
#define SUDOKU_UTILS_HPP

namespace sudoku_systemc
{
  template<unsigned int VALUE>
    class sudoku_utils
    {
    private:
      static inline unsigned int get_nb_bits_for_value(void)
	{
	  return (VALUE == 0) ? 0 : (1+sudoku_utils<(VALUE >> 1)>::get_nb_bits());
	}
    public:
      static const unsigned int m_nb_bits_for_value;
      static const unsigned int m_nb_bits_for_nb_values;
    };

  template<unsigned int VALUE> const unsigned int sudoku_utils<VALUE>::m_nb_bits_for_value = (VALUE == 0) ? 0 : (1+sudoku_utils<(VALUE >> 1)>::m_nb_bits_for_value);
  template<unsigned int VALUE> const unsigned int sudoku_utils<VALUE>::m_nb_bits_for_nb_values = sudoku_utils<VALUE-1>::m_nb_bits_for_value;
}
#endif // SUDOKU_UTILS_HPP
//EOF
