/*
 * Uppercase.cpp
 *
 */
#include "PPMP/Mangling/Uppercase.hpp"

namespace PPMP
{
namespace Mangling
{

Uppercase::Uppercase(void):
  MangleLUT(1)  // always one reposnse
{
  for(char from='a', to='A'; from<='z'; ++from, ++to)
    changeLUT(from, to);
}

} // namespace Mangling
} // namespace PPMP
