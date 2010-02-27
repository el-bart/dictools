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
#include "PPMP/Output.hpp"

namespace PPMP
{

class Writer: private boost::noncopyable,
              public  Output
{
public:
  explicit Writer(std::ostream &os);

  void write(const Common::FastString &str);
  virtual void process(Common::FastString &str);

private:
  std::ostream &os_;
}; // class Writer

} // namespace PPMP

#endif
