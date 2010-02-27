/*
 * AppendShortYear.cpp
 *
 */
#include "PPMP/Mangling/AppendShortYear.hpp"

using namespace Common;

namespace PPMP
{
namespace Mangling
{

AppendShortYear::AppendShortYear(Processor &out):
  Mangler(out),
  na199x_(out, Range(70, 99) ),
  na200x_(out, Range( 0,  9) ),
  na201x_(out, Range( 0,  1) )
{
}

void AppendShortYear::mangleImpl(Common::FastString &str, Processor &/*out*/)
{
  const size_t len=str.size();
  FastString   tmp=str;
  na199x_.process(tmp);

  tmp=str;
  // add '0' before actual iteration
  tmp[len]  ='0';
  tmp[len+1]=0;
  na200x_.process(tmp);

  tmp=str;
  // add '1' before actual iteration
  tmp[len]  ='1';
  tmp[len+1]=0;
  na201x_.process(tmp);
}

} // namespace Mangling
} // namespace PPMP
