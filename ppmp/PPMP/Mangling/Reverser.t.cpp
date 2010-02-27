/*
 * Reverser.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <cassert>

#include "PPMP/Mangling/Reverser.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    rev_(*this),
    expected_(NULL)
  {
  }

  void check(const char *str, const char *expected)
  {
    expected_=expected;
    Common::FastString fs(str);
    rev_.process(fs);
  }

private:
  virtual void process(Common::FastString &str)
  {
    assert(expected_!=NULL);
    tut::ensure_equals("invalid string", str.c_str(), string(expected_) );
  }

  Reverser    rev_;
  const char *expected_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/Reverser");
} // unnamed namespace


namespace tut
{

// test basic string
template<>
template<>
void testObj::test<1>(void)
{
  check("abcd", "dcba");
}

// test empty string
template<>
template<>
void testObj::test<2>(void)
{
  check("", "");
}

// test 1-element string
template<>
template<>
void testObj::test<3>(void)
{
  check("a", "a");
}

// test non-parity count.
template<>
template<>
void testObj::test<4>(void)
{
  check("abc", "cba");
}

// test two-elements
template<>
template<>
void testObj::test<5>(void)
{
  check("ab", "ba");
}

} // namespace tut
