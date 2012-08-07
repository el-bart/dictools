/*
 * Underscore.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/Underscore.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    us_(*this)
  {
  }

  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  Underscore us_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/Underscore");
} // unnamed namespace


namespace tut
{

// test empty set
template<>
template<>
void testObj::test<1>(void)
{
  q_.push("");
  q_.push("_");
  // test
  Common::FastString fs("");
  us_.process(fs);
  // nothing should be in queue
  ensure_equals("something's left", q_.size(), 0);
}

// test simple set
template<>
template<>
void testObj::test<2>(void)
{
  q_.push("ab");
  q_.push("_ab");
  q_.push("a_b");
  q_.push("ab_");

  // test
  Common::FastString fs("ab");
  us_.process(fs);
  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test longer sequence
template<>
template<>
void testObj::test<3>(void)
{
  q_.push("$abc6");
  q_.push("_$abc6");
  q_.push("$_abc6");
  q_.push("$a_bc6");
  q_.push("$ab_c6");
  q_.push("$abc_6");
  q_.push("$abc6_");

  // test
  Common::FastString fs("$abc6");
  us_.process(fs);
  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
