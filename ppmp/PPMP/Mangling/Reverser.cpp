/*
 * Reverser.cpp
 *
 */
#include "PPMP/Mangling/Reverser.hpp"
#include <cassert>

namespace PPMP
{
namespace Mangling
{

Reverser::Reverser(Processor &out):
  Mangler(out)
{
}

void Reverser::mangleImpl(Common::FastString &str, Processor &out)
{
  const size_t len=str.size();
  for(size_t i=0; i<len/2; ++i)
  {
    const int  i2 =len-1-i;
    const char tmp=str[i];
    str[i] =str[i2];
    str[i2]=tmp;
  }

  out.process(str);
}

} // namespace Mangling
} // namespace PPMP
