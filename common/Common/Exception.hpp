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

/** \brief base exception for all components.
 */
struct Exception: public System::Exceptions::RuntimeError<Exception>
{
  /** \brief create exception information.
   *  \param where place where exception has been risen.
   *  \param what  comment on exception.
   */
  Exception(const Location &where, const std::string &what):
    System::Exceptions::RuntimeError<Exception>(where, what)
  {
  }
};

} // namespace Common

#endif
