/*
 * AllCases.cpp
 *
 */
#include <vector>
#include <ctype.h>

#include "PPMP/Mangling/AllCases.hpp"


namespace PPMP
{
namespace Mangling
{

AllCases::AllCases(Processor &out):
  Mangler(out)
{
}

namespace
{
inline char toggleCase(const char in)
{
  // TODO: implement this using LUT
  if( islower(in) )
    return toupper(in);
  else
    return tolower(in);
}
} // unnamed namespace

void AllCases::mangleImpl(Common::FastString &str, Processor &out)
{
  const size_t len=str.size();

  // positions with letters
  std::vector<size_t> pos;
  for(size_t i=0; i<len; ++i)
    if( isalpha(str[i]) )
      pos.push_back(i);

  // compute number of permutations available
  const size_t perms=1<<pos.size();

  // output all permutations
  for(size_t i=0; i<perms; ++i)
  {
    Common::FastString tmp(str);
    for(size_t j=0; j<pos.size(); ++j)
      if( (i & (1<<j))!=0 )
        tmp[pos[j]]=toggleCase(tmp[pos[j]]);
    out.process(tmp);
  }
}

} // namespace Mangling
} // namespace PPMP
