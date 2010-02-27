/*
 * Uppercase.cpp
 *
 */
#include "PPMP/Mangling/Uppercase.hpp"

namespace PPMP
{
namespace Mangling
{

Uppercase::Uppercase(Processor &out):
  MangleLUT(out)
{
  for(char from='a', to='A'; from<='z'; ++from, ++to)
    changeLUT(from, to);
}

} // namespace Mangling
} // namespace PPMP
