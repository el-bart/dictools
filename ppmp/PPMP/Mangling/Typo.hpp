/*
 * Typo.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_TYPO_HPP_FILE
#define INCLUDE_PPMP_MANGLING_TYPO_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief processor for making typos in strings.
 */
class Typo: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit Typo(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);
}; // class Typo

} // namespace Mangling
} // namespace PPMP

#endif
