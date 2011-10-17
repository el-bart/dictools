/*
 * ppmp.cpp
 *
 */
#include <iostream>
#include <vector>

#include "Common/Exception.hpp"
#include "PPMP/Reader.hpp"
#include "PPMP/Writer.hpp"
#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Mangling/Lowercase.hpp"
#include "PPMP/Mangling/Uppercase.hpp"
#include "PPMP/Mangling/NumberAdder.hpp"
#include "PPMP/Mangling/AppendShortYear.hpp"
#include "PPMP/Mangling/AppendYear.hpp"
#include "PPMP/Mangling/LeetSpeak.hpp"
#include "PPMP/Mangling/Lowercase.hpp"
#include "PPMP/Mangling/Reverser.hpp"
#include "PPMP/Mangling/SimpleLeetSpeak.hpp"
#include "PPMP/Mangling/Typo.hpp"
#include "PPMP/Mangling/Uppercase.hpp"
#include "PPMP/Mangling/AllCases.hpp"
#include "PPMP/Mangling/Underscore.hpp"

using namespace std;
using namespace Common;
using namespace PPMP;
using namespace PPMP::Mangling;

int main(int /*argc*/, char **argv)
{
  try
  {
    Reader rd(cin);
    Writer wr(cout);

    typedef std::vector<Processor*> Processors;
    Processors   procs;

    NumberAdder na(wr, Range(0, 9) );
    procs.push_back(&na);

    AppendShortYear asy(wr);
    procs.push_back(&wr);

    AppendYear ay(wr);
    procs.push_back(&ay);

    LeetSpeak ls(wr);
    procs.push_back(&ls);

    Lowercase lc(wr);
    procs.push_back(&lc);

    Reverser rev(wr);
    procs.push_back(&rev);

    SimpleLeetSpeak sls(wr);
    procs.push_back(&sls);

    Typo t(wr);
    procs.push_back(&t);

    Uppercase uc(wr);
    procs.push_back(&uc);

    AllCases ac(wr);
    procs.push_back(&ac);

    Underscore us(wr);
    procs.push_back(&us);

    FastString str;
    while( rd.read(str) )
    {
      for(Processors::const_iterator it=procs.begin(); it!=procs.end(); ++it)
      {
        FastString tmp(str);
        (*it)->process(tmp);
      }
    }
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
