/*
 * ppmp.cpp
 *
 */
#include <iostream>

#include "Common/Exception.hpp"
#include "PPMP/Reader.hpp"
#include "PPMP/Writer.hpp"
#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Mangling/Lowercase.hpp"
#include "PPMP/Mangling/Uppercase.hpp"
#include "PPMP/Mangling/NumberAdder.hpp"

using namespace std;
using namespace Common;
using namespace PPMP;
using namespace PPMP::Mangling;

int main(int /*argc*/, char **argv)
{
  try
  {
    Reader       rd(cin);
    Writer       wr(cout);
    NumberAdder  na(wr, Range(0, 9) );
    Processor   &p=na;
    // TODO

    FastString str;
    while( rd.read(str) )
      p.process(str);
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
