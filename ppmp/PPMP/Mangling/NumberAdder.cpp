/*
 * NumberAdder.cpp
 *
 */
#include "PPMP/Mangling/NumberAdder.hpp"
#include <cstdio>
#include <cassert>

namespace PPMP
{
namespace Mangling
{

NumberAdder::NumberAdder(Processor &out, const Common::Range r):
  Mangler(out),
  r_(r)
{
}

void NumberAdder::mangleImpl(Common::FastString &str, Processor &out)
{
  const Common::FastString in  =str;        // make local copy
  int                      from=r_.from();
  for(size_t i=0; i<r_.span(); ++i)
  {
    snprintf( str.get(), Common::FastString::maxSize(), "%s%d", in.c_str(), from);
    ++from;
    out.process(str);
  }
  assert( from==r_.to()+1 );
}

} // namespace Mangling
} // namespace PPMP
