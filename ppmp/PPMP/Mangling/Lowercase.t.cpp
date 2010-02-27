/*
 * Lowercase.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>

#include "PPMP/Mangling/Lowercase.hpp"

using namespace PPMP::Mangling;

namespace
{

struct TestClass
{
  void check(const char *str, const char *expected)
  {
    const Lowercase::StringsSet &out=lc_.mangle(str);
    tut::ensure_equals("invalid size", out.size(), 1);
    tut::ensure_equals("invalid value", out[0].c_str(), std::string(expected) );
  }

  Lowercase lc_;
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
