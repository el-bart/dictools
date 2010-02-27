/*
 * ExceptionInvalidRange.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_EXCEPTIONINVALIDRANGE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_EXCEPTIONINVALIDRANGE_HPP_FILE

#include "Common/Exception.hpp"

namespace PPMP
{
namespace Mangling
{

struct ExceptionInvalidRange: public Common::Exception
{
  ExceptionInvalidRange(const Location &where, int from, int to):
    Common::Exception(where, cc("given range is invalid: ", from, " -> ", to) )
  {
  }
};

} // namespace Mangling
} // namespace Common

#endif
