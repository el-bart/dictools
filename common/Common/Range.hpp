/*
 * Range.hpp
 *
 */
#ifndef INCLUDE_COMMON_RANGE_HPP_FILE
#define INCLUDE_COMMON_RANGE_HPP_FILE

/* public header */

#include <cstdlib>
#include <cassert>

namespace Common
{
/** \brief representation of range of numbers.
 */
class Range
{
public:
  /** \brief create number's range.
   *  \param from start number.
   *  \param to   stop number.
   *
   *  if class is givne paramters in reverse order (i.e. from>to) it
   *  will be properly set automatically.
   *  class supports negative numbers as well.
   */
  Range(int from, int to);
  /** \brief get lower number.
   *  \return number to start counting from.
   */
  int from(void) const
  {
    return from_;
  }
  /** \brief get higher number.
   *  \return number to stop counting on.
   */
  int to(void) const
  {
    return to_;
  }
  /** \brief compute range size.
   *  \return number of elements in range.
   */
  size_t span(void) const
  {
    assert( to()>=from() );
    return to()-from()+1;
  }

private:
  int from_;
  int to_;
}; // class Range

} // namespace Common

#endif
