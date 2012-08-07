/*
 * MangleLUT.cpp
 *
 */
#include "PPMP/Mangling/Lowercase.hpp"

namespace PPMP
{
namespace Mangling
{

void MangleLUT::mangleImpl(Common::FastString &str, Processor &out)
{
  for(int i=0; str[i]!=0; ++i)
    str[i]=(*this)[ str[i] ];    // perform LUT

  out.process(str);
}

} // namespace Mangling
} // namespace PPMP
