/*
 * Writer.cpp
 *
 */
#include "PPMP/Writer.hpp"
#include <cassert>

using namespace std;

namespace PPMP
{

Writer::Writer(std::ostream &os):
  os_(os)
{
}

void Writer::write(const Common::FastString &str)
{
  assert( str.c_str()!=NULL );
  os_<<str.c_str()<<endl;
}

void process(Common::FastString &str)
{
  write(str);
}

} // namespace PPMP
