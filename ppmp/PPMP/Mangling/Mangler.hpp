/*
 * Mangler.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE
#define INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE

#include <vector>

#include "Common/FastString.hpp"

namespace PPMP
{
namespace Mangling
{

class Mangler
{
public:
  typedef std::vector<Common::FastString> StringsSet;

  virtual ~Mangler(void);

  const StringsSet &mangle(const Common::FastString &in)
  {
    mangleImpl(in, out_);
    return out_;
  }

private:
  virtual void mangleImpl(const Common::FastString &in, StringsSet &out) = 0;

  StringsSet out_;
}; // class Mangler

} // namespace Mangling
} // namespace PPMP

#endif
