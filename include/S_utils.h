#ifndef S_UTILS_HPP
#define S_UTILS_HPP

template<unsigned int VALUE> class S_utils
{
private:
  static inline unsigned int get_nb_bits_for_value(void)
  {
    return (VALUE == 0) ? 0 : (1+S_utils<(VALUE >> 1)>::get_nb_bits());
  }
public:
  static const unsigned int m_nb_bits_for_value;
  static const unsigned int m_nb_bits_for_nb_values;
};

template<unsigned int VALUE> const unsigned int S_utils<VALUE>::m_nb_bits_for_value = (VALUE == 0) ? 0 : (1+S_utils<(VALUE >> 1)>::m_nb_bits_for_value);
template<unsigned int VALUE> const unsigned int S_utils<VALUE>::m_nb_bits_for_nb_values = S_utils<VALUE-1>::m_nb_bits_for_value;
#endif // S_UTILS_HPP
//EOF
