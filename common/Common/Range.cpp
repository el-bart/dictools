/*
 * Range.cpp
 *
 */
#include "Common/Range.hpp"

namespace Common
{

Range::Range(int from, int to)
{
  if(from>to)
  {
    from_=to;
    to_  =from;
  }
  else
  {
    from_=from;
    to_  =to;
  }
}

} // namespace Common
