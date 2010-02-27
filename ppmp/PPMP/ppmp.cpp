/*
 * ppmp.cpp
 *
 */
#include <iostream>

#include "Common/Exception.hpp"
#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Reader.hpp"
#include "PPMP/Writer.hpp"

using namespace std;
using namespace PPMP;

int main(int /*argc*/, char **argv)
{
  try
  {
    Reader rd(cin);
    Writer wr(cout);


    // TODO
  }
  catch(const Common::Exception &ex)
  {
    cerr<<argv[0]<<": exception("<<ex.getTypeName()<<"): "<<ex.what()<<endl;
  }
  catch(const std::exception &ex)
  {
    cerr<<argv[0]<<": exception(std::exception): "<<ex.what()<<endl;
  }
  catch(...)
  {
    cerr<<argv[0]<<": exception(<unknown>): aborting..."<<endl;
  }

  return 0;
}
