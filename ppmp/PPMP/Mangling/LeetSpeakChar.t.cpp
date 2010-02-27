/*
 * LeetSpeakChar.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/LeetSpeakChar.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  queue<string> q_;

  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/LeetSpeakChar");
} // unnamed namespace


namespace tut
{

// test some leet-speaking
template<>
template<>
void testObj::test<1>(void)
{
  LeetSpeakChar< boost::mpl::vector_c<char, 'X', 'Y', 'Z'> > lsc(*this, 'a');
  q_.push("XAbX");
  q_.push("YAbY");
  q_.push("ZAbZ");

  // test
  Common::FastString fs("aAba");
  lsc.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test 1-element subsitution
template<>
template<>
void testObj::test<2>(void)
{
  LeetSpeakChar< boost::mpl::vector_c<char, 'Z'> > lsc(*this, 'a');
  q_.push("ZAbZ");

  // test
  Common::FastString fs("aAba");
  lsc.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
