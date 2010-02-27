/*
 * Uppercase.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>
#include <cassert>

#include "PPMP/Mangling/Uppercase.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public Processor
{
  TestClass(void):
    uc_(*this),
    expected_(NULL)
  {
  }

  void check(const char *str, const char *expected)
  {
    expected_=expected;
    Common::FastString fs(str);
    uc_.process(fs);
  }

private:
  virtual void process(Common::FastString &str)
  {
    assert(expected_!=NULL);
    tut::ensure_equals("invalid string", str.c_str(), string(expected_) );
  }

  Uppercase   uc_;
  const char *expected_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/Uppercase");
} // unnamed namespace


namespace tut
{

// test basic strings
template<>
template<>
void testObj::test<1>(void)
{
  check("AabCdeFghijXYZ", "AABCDEFGHIJXYZ");
}

// test with some non-letters
template<>
template<>
void testObj::test<2>(void)
{
  check("^a0/[H!", "^A0/[H!");
}

} // namespace tut
