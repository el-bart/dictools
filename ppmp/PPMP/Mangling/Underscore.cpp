/*
 * Underscore.cpp
 *
 */
#include <cassert>

#include "PPMP/Mangling/Underscore.hpp"

namespace PPMP
{
namespace Mangling
{

Underscore::Underscore(Processor &out):
  Mangler(out)
{
}


void Underscore::mangleImpl(Common::FastString &str, Processor &out)
{
  // raw string
  out.process(str);

  // version with underscores before some string
  const size_t len=str.size();
  for(size_t i=0; i<len; ++i)
  {
    Common::FastString tmp("");
    for(size_t j=0, w=0; j<len; ++j, ++w)
    {
      if(i==j)
      {
        assert(j==w);
        tmp[w]='_';
        ++w;
        assert(j+1==w);
      }
      tmp[w]=str[j];
      assert(w<=len);
    }
    tmp[len+2]=0;
    assert( tmp.size()==len+1 );
    out.process(tmp);
  }

  // final underscore
  str[len]  ='_';
  str[len+1]=0;
  out.process(str);
}

} // namespace Mangling
} // namespace PPMP
