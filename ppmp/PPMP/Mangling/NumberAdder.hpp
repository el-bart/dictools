/*
 * NumberAdder.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_NUMBERADDER_HPP_FILE
#define INCLUDE_PPMP_MANGLING_NUMBERADDER_HPP_FILE

#include "Common/Range.hpp"
#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief processor appending numbers at the end of string.
 */
class NumberAdder: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   *  \param r   range to generate.
   */
  NumberAdder(Processor &out, Common::Range r);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);

  const Common::Range r_;
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
