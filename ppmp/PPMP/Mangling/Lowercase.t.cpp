/*
 * Lowercase.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <cassert>

#include "PPMP/Mangling/Lowercase.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    lc_(*this),
    expected_(NULL)
  {
  }

  void check(const char *str, const char *expected)
  {
    expected_=expected;
    Common::FastString fs(str);
    lc_.process(fs);
  }

private:
  virtual void process(Common::FastString &str)
  {
    assert(expected_!=NULL);
    tut::ensure_equals("invalid string", str.c_str(), string(expected_) );
  }

  Lowercase   lc_;
  const char *expected_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/Lowercase");
} // unnamed namespace


namespace tut
{

// test basic strings
template<>
template<>
void testObj::test<1>(void)
{
  check("AabCdeFghijXYZ", "aabcdefghijxyz");
}

// test with some non-letters
template<>
template<>
void testObj::test<2>(void)
{
  check("^a0/[H!", "^a0/[h!");
}

} // namespace tut
