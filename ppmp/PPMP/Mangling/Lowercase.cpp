/*
 * Lowercase.cpp
 *
 */
#include "PPMP/Mangling/Lowercase.hpp"

namespace PPMP
{
namespace Mangling
{

Lowercase::Lowercase(void):
  Mangler(1)    // always one reposnse
{
}

void Lowercase::mangleImpl(const Common::FastString &in, StringsSet &out)
{
  // TODO
}

} // namespace Mangling
} // namespace PPMP
