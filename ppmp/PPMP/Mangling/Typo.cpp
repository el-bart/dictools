/*
 * Typo.cpp
 *
 */
#include "PPMP/Mangling/Typo.hpp"

namespace PPMP
{
namespace Mangling
{

Typo::Typo(Processor &out):
  Mangler(out)
{
}

void Typo::mangleImpl(Common::FastString &str, Processor &out)
{
  Common::FastString tmp;
  const size_t       len=str.size();
  for(size_t i=1; i<len; ++i)
  {
    tmp     =str;
    tmp[i]  =str[i-1];
    tmp[i-1]=str[i];
    // forward
    out.process(tmp);
  }
}

} // namespace Mangling
} // namespace PPMP
