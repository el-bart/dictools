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

/** \brief data reader.
 *
 *  reads each input line and returns it as s string.
 */
class Reader: private boost::noncopyable
{
public:
  /** \brief create reader.
   *  \param is input stream to read from.
   */
  explicit Reader(std::istream &is);

  /** \brief read entry.
   *  \param out output string paramter.
   *  \return true if reading succedded, false otherwise.
   */
  bool read(Common::FastString &out);

private:
  std::istream &is_;
}; // class Reader

} // namespace PPMP

#endif
