/*
 * Reader.cpp
 *
 */
#include "PPMP/Reader.hpp"
#include <string>

using namespace std;

namespace PPMP
{

Reader::Reader(std::istream &is):
  is_(is)
{
}

bool Reader::read(Common::FastString &out)
{
  string tmp;
  if( !getline(is_, tmp) )
    return false;
  out=tmp;
  return true;
}

} // namespace PPMP
