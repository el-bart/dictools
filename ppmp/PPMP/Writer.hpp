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

namespace PPMP
{

class Writer: private boost::noncopyable
{
public:
  explicit Writer(std::ostream &os);

  void write(const Common::FastString &str);

private:
  std::ostream &os_;
}; // class Writer

} // namespace PPMP

#endif
