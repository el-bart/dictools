/*
 * Reverser.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_REVERSER_HPP_FILE
#define INCLUDE_PPMP_MANGLING_REVERSER_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief processor reverting string.
 */
class Reverser: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit Reverser(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);
}; // class Reverser

} // namespace Mangling
} // namespace PPMP

#endif
