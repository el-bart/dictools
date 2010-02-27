/*
 * Output.hpp
 *
 */
#ifndef INCLUDE_PPMP_OUTPUT_HPP_FILE
#define INCLUDE_PPMP_OUTPUT_HPP_FILE

#include <boost/noncopyable.hpp>

#include "Common/FastString.hpp"


struct Output: private boost::noncopyable
{
  virtual ~Output(void)
  {
  }

protected:
  virtual void proceed(Common::FastString &str) = 0;
}; // struct Output

#endif
