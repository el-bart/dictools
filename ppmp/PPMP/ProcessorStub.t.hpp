/*
 * ProcessorStub.hpp
 *
 */
#ifndef INCLUDE_PPMP_PROCESSORSTUB_HPP_FILE
#define INCLUDE_PPMP_PROCESSORSTUB_HPP_FILE

#include <boost/noncopyable.hpp>

#include "PPMP/Processor.hpp"

namespace PPMP
{

struct ProcessorStub: public Processor
{
  ProcessorStub(void):
    calls_(0)
  {
  }

  virtual void process(Common::FastString &/*str*/)
  {
    ++calls_;
  }

  int calls_;
}; // struct ProcessorStub

} // namespace PPMP

#endif
