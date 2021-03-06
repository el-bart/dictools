/*
 * AppendShortYear.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/AppendShortYear.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    asy_(*this)
  {
  }

  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  AppendShortYear asy_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/AppendShortYear");
} // unnamed namespace


namespace tut
{

// test appending short year
template<>
template<>
void testObj::test<1>(void)
{
  // prepare results to collect
  for(int i=70; i<=99; ++i)
  {
    stringstream ss;
    ss<<"abc"<<i;
    q_.push( ss.str() );
  }
  for(int i=0; i<=9; ++i)
  {
    stringstream ss;
    ss<<"abc0"<<i;
    q_.push( ss.str() );
  }
  q_.push("abc10");
  q_.push("abc11");

  // test
  Common::FastString fs("abc");
  asy_.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
