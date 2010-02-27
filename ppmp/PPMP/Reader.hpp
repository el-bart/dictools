/*
 * Reader.hpp
 *
 */
#ifndef INCLUDE_PPMP_READER_HPP_FILE
#define INCLUDE_PPMP_READER_HPP_FILE

/* public header */

#include <iostream>
#include <boost/noncopyable.hpp>

#include "Common/FastString.hpp"

namespace PPMP
{

class Reader: private boost::noncopyable
{
public:
  explicit Reader(std::istream &is);

  bool read(Common::FastString &out);

private:
  std::istream &is_;
}; // class Reader

} // namespace PPMP

#endif
