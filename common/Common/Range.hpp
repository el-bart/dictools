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

class Range
{
public:
  Range(int from, int to);

  int from(void) const
  {
    return from_;
  }
  int to(void) const
  {
    return to_;
  }

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
