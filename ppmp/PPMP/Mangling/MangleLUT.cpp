/*
 * MangleLUT.cpp
 *
 */
#include "PPMP/Mangling/Lowercase.hpp"
#include <cassert>

namespace PPMP
{
namespace Mangling
{

void MangleLUT::mangleImpl(const Common::FastString &in, StringsSet &out)
{
  assert( out.size()==1 );
  Common::FastString &str=out[0];
  out[0]=0; // in case loop never executed
  for(int i=0; in[i]!=0; ++i)
    str[i]=(*this)[ in[i] ];    // perform LUT
}

} // namespace Mangling
} // namespace PPMP
