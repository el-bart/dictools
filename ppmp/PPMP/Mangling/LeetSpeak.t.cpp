/*
 * LeetSpeak.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <sstream>
#include <queue>

#include "PPMP/Mangling/LeetSpeak.hpp"

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
    assert( str.size()<=3 );
    if( string( str.c_str() )==str_.c_str() )   // this means empty run
      return;

    tut::ensure("too many elements produced", q_.size()>0 );
    tut::ensure_equals("invalid string", str.c_str(), q_.front() );
    q_.pop();
  }

  Common::FastString str_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/LeetSpeak");
} // unnamed namespace


namespace tut
{

// test some leet-speaking
template<>
template<>
void testObj::test<1>(void)
{
  LeetSpeak ls(*this);
  q_.push("@52");
  q_.push("452");
  q_.push("@$2");
  q_.push("4$2");
  q_.push("@z2");
  q_.push("4z2");
  q_.push("@5%");
  q_.push("45%");
  q_.push("@$%");
  q_.push("4$%");
  q_.push("@z%");
  q_.push("4z%");
  q_.push("@5s");
  q_.push("45s");
  q_.push("@$s");
  q_.push("4$s");
  q_.push("@zs");
  q_.push("4zs");

  // test
  Common::FastString fs("asz");
  str_=fs;
  ls.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test very simple leet-speaking
template<>
template<>
void testObj::test<2>(void)
{
  LeetSpeak ls(*this);
  q_.push("@5");
  q_.push("45");
  q_.push("@$");
  q_.push("4$");
  q_.push("@z");
  q_.push("4z");

  // test
  Common::FastString fs("as");
  str_=fs;
  ls.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

// test translation, when no transofrmation is present
template<>
template<>
void testObj::test<3>(void)
{
  LeetSpeak ls(*this);

  // test
  Common::FastString fs("vwx");
  str_=fs;
  ls.process(fs);

  // check if nothing has left
  ensure_equals("not all elements generated", q_.size(), 0);
}

} // namespace tut
