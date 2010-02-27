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

NumberAdder::NumberAdder(const Common::Range r):
  Mangler( r.span() ),
  r_(r)
{
}

void NumberAdder::mangleImpl(const Common::FastString &in, StringsSet &out)
{
  assert( out.size()==r_.span() );
  int from=r_.from();
  for(StringsSet::iterator it=out.begin(); it!=out.end(); ++it)
  {
    snprintf( it->get(), Common::FastString::maxSize(), "%s%d", in.c_str(), from);
    ++from;
  }
  assert( from==r_.to()+1 );
}

} // namespace Mangling
} // namespace PPMP
