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

/** \brief generic processor of string.
 */
struct Processor: private boost::noncopyable
{
  /** \brief ensure polymorphic destruction.
   */
  virtual ~Processor(void);

  /** \brief process user-provided string.
   *  \param str string to be processed.
   *
   *  \note 'str' is non-const reference, since for
   *        performance reasons other processors can change
   *        it at will. when process() exits str's content
   *        should be assumed to be random.
   */
  virtual void process(Common::FastString &str) = 0;
}; // struct Processor

} // namespace PPMP

#endif
