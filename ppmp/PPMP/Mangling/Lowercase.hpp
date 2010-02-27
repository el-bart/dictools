/*
 * Lowercase.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LOWERCASE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LOWERCASE_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

class Lowercase: public Mangler
{
public:
  Lowercase(void);

private:
  virtual void mangleImpl(const Common::FastString &in, StringsSet &out);
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
