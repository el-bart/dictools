/*
 * AppendYear.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/AppendYear.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    ay_(*this)
  {
  }

  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  AppendYear ay_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/AppendYear");
} // unnamed namespace


namespace tut
{

// test appending year
template<>
template<>
void testObj::test<1>(void)
{
  // prepare results to collect
  for(int i=1950; i<=2011; ++i)
  {
    stringstream ss;
    ss<<"abc"<<i;
    q_.push( ss.str() );
  }

  // test
  Common::FastString fs("abc");
  ay_.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
