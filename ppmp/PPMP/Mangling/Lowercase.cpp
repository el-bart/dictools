/*
 * Lowercase.cpp
 *
 */
#include "PPMP/Mangling/Lowercase.hpp"

namespace PPMP
{
namespace Mangling
{

Lowercase::Lowercase(Processor &out):
  MangleLUT(out)
{
  for(char from='A', to='a'; from<='Z'; ++from, ++to)
    changeLUT(from, to);
}

} // namespace Mangling
} // namespace PPMP
