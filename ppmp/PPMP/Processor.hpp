/*
 * Processor.hpp
 *
 */
#ifndef INCLUDE_PPMP_PROCESSOR_HPP_FILE
#define INCLUDE_PPMP_PROCESSOR_HPP_FILE

#include <boost/noncopyable.hpp>

#include "Common/FastString.hpp"

namespace PPMP
{

struct Processor: private boost::noncopyable
{
  virtual ~Processor(void);

  virtual void process(Common::FastString &str) = 0;
}; // struct Processor

} // namespace PPMP

#endif
