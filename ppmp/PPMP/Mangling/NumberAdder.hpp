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

class NumberAdder: public Mangler
{
public:
  explicit NumberAdder(Common::Range r);

private:
  virtual void mangleImpl(const Common::FastString &in, StringsSet &out);

  const Common::Range r_;
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
