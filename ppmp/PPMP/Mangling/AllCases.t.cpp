/*
 * AllCases.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/AllCases.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    ac_(*this)
  {
  }

  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  AllCases ac_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/AllCases");
} // unnamed namespace


namespace tut
{

// test empty output set
template<>
template<>
void testObj::test<1>(void)
{
  q_.push("666");
  // test
  Common::FastString fs("666");
  ac_.process(fs);
  // nothing should be in queue
  ensure_equals("something's left", q_.size(), 0);
}

// test simple set (only letters)
template<>
template<>
void testObj::test<2>(void)
{
  q_.push("ab");
  q_.push("Ab");
  q_.push("aB");
  q_.push("AB");

  // test
  Common::FastString fs("ab");
  ac_.process(fs);
  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test example set (mixed elements)
template<>
template<>
void testObj::test<3>(void)
{
  q_.push("42X-f");
  q_.push("42x-f");
  q_.push("42X-F");
  q_.push("42x-F");

  // test
  Common::FastString fs("42X-f");
  ac_.process(fs);
  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test longer sequence
template<>
template<>
void testObj::test<4>(void)
{
  q_.push("$abc6");
  q_.push("$Abc6");
  q_.push("$aBc6");
  q_.push("$ABc6");
  q_.push("$abC6");
  q_.push("$AbC6");
  q_.push("$aBC6");
  q_.push("$ABC6");

  // test
  Common::FastString fs("$abc6");
  ac_.process(fs);
  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
