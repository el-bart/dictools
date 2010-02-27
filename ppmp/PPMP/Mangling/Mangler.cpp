/*
 * Mangler.cpp
 *
 */
#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

Mangler::Mangler(const size_t size):
  out_(size)
{
  assert( out_.size()==size );
}

Mangler::~Mangler(void)
{
}

} // namespace Mangling
} // namespace PPMP
