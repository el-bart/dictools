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

/** \brief output processor (sink).
 */
class Writer: public Processor
{
public:
  /** \brief create output processor.
   *  \param os stream to write to.
   */
  explicit Writer(std::ostream &os);
  /** \brief output data to stream.
   *  \param str string to write.
   */
  virtual void process(Common::FastString &str);

private:
  void write(const Common::FastString &str);

  std::ostream &os_;
}; // class Writer

} // namespace PPMP

#endif
