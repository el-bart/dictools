/*
 * MangleLUT.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <cassert>

#include "PPMP/Mangling/MangleLUT.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestLUT: public Processor
{
  TestLUT(void):
    expected_(NULL),
    calls_(0)
  {
  }

  virtual void process(Common::FastString &str)
  {
    assert(expected_!=NULL);
    tut::ensure_equals("invalid string", str.c_str(), string(expected_) );
    ++calls_;
  }

  const char *expected_;
  int         calls_;
};

struct TestClass: public MangleLUT
{
  TestClass(void):
    MangleLUT(tlut_)
  {
  }

  TestLUT     tlut_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/MangleLUT");
} // unnamed namespace


namespace tut
{

// test setting translation
template<>
template<>
void testObj::test<1>(void)
{
  changeLUT('a', 'Q');  // change entry
  changeLUT('C', 'x');  // change entry
  Common::FastString in("aAbBcCqQ");
  tlut_.expected_="QAbBcxqQ";
  process(in);
}

// test forwarding to other processors
template<>
template<>
void testObj::test<2>(void)
{
  Common::FastString in("abc");
  tlut_.expected_="abc";
  process(in);
  ensure_equals("call not forwarded", tlut_.calls_, 1);
}

} // namespace tut
