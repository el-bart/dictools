/*
 * Lowercase.cpp
 *
 */
#include "PPMP/Mangling/Lowercase.hpp"
#include <cassert>

namespace PPMP
{
namespace Mangling
{

Lowercase::Lowercase(void):
  MangleLUT(1)  // always one reposnse
{
  for(char from='A', to='a'; from<='Z'; ++from, ++to)
    changeLUT(from, to);
}

} // namespace Mangling
} // namespace PPMP
