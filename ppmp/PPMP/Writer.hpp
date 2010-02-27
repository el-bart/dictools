/*
 * Writer.hpp
 *
 */
#ifndef INCLUDE_PPMP_WRITER_HPP_FILE
#define INCLUDE_PPMP_WRITER_HPP_FILE

/* public header */

#include <iostream>
#include <boost/noncopyable.hpp>

#include "Common/FastString.hpp"
#include "PPMP/Processor.hpp"

namespace PPMP
{

class Writer: public Processor
{
public:
  explicit Writer(std::ostream &os);

  virtual void process(Common::FastString &str);

private:
  void write(const Common::FastString &str);

  std::ostream &os_;
}; // class Writer

} // namespace PPMP

#endif
