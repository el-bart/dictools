/*
 * SimpleLeetSpeak.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/SimpleLeetSpeak.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    sls_(*this)
  {
  }

  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  SimpleLeetSpeak sls_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/SimpleLeetSpeak");
} // unnamed namespace


namespace tut
{

// test simple leet-speaking
template<>
template<>
void testObj::test<1>(void)
{
  q_.push("4488Cc3311JjLl005z77");

  // test
  Common::FastString fs("AaBbCcEeIiJjLlOoSsTt");
  sls_.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
