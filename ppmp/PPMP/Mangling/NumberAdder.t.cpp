/*
 * NumberAdder.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <queue>

#include "PPMP/Mangling/NumberAdder.hpp"

using namespace std;
using namespace Common;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  virtual void process(Common::FastString &str)
  {
    tut::ensure("too many elements returned", out_.size()>0 );
    tut::ensure_equals("invalid value", str.c_str(), out_.front() );
    out_.pop();
  }

  queue<string> out_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/NumberAdder");
} // unnamed namespace


namespace tut
{

// test adding single number
template<>
template<>
void testObj::test<1>(void)
{
  out_.push("str6");
  NumberAdder nc(*this, Common::Range(6,6) );
  FastString  tmp("str");
  nc.process(tmp);
}

// test adding multiple numbers
template<>
template<>
void testObj::test<2>(void)
{
  out_.push("str11");
  out_.push("str12");
  out_.push("str13");
  NumberAdder nc(*this, Common::Range(11,13) );
  FastString  tmp("str");
  nc.process(tmp);
}

// test negative numbers
template<>
template<>
void testObj::test<3>(void)
{
  out_.push("str-3");
  out_.push("str-2");
  NumberAdder nc(*this, Common::Range(-2,-3) );
  FastString  tmp("str");
  nc.process(tmp);
}

} // namespace tut
