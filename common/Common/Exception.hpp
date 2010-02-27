/*
 * Exception.hpp
 *
 */
#ifndef INCLUDE_COMMON_EXCEPTION_HPP_FILE
#define INCLUDE_COMMON_EXCEPTION_HPP_FILE

#include "System/Exceptions/RuntimeError.hpp"

/* public header */

namespace Common
{

struct Exception: public System::Exceptions::RuntimeError<Exception>
{
  Exception(const Location &where, const std::string &what):
    System::Exceptions::RuntimeError<Exception>(where, what)
  {
  }
};

} // namespace Common

#endif
