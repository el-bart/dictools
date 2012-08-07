/*
 * Underscore.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_UNDERSCORE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_UNDERSCORE_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief add undersciores in each place separately.
 */
class Underscore: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit Underscore(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);
}; // class Underscore

} // namespace Mangling
} // namespace PPMP

#endif
