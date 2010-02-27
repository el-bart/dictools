/*
 * FastString.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "Common/FastString.hpp"

using namespace Common;

namespace
{
struct TestClass
{
  void check(const FastString &out, const std::string &expected) const
  {
    tut::ensure_equals("invalid output string", out.c_str(), expected);
  }
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("Common/FastString");
} // unnamed namespace


namespace tut
{

// test default c-tor
template<>
template<>
void testObj::test<1>(void)
{
  FastString fs;
  check(fs, "");
}

// test c-tor with paramter
template<>
template<>
void testObj::test<2>(void)
{
  const FastString fs("alice has a cat");
  check(fs, "alice has a cat");
}

// test too long string in c-tor
template<>
template<>
void testObj::test<3>(void)
{
  const FastString fs("01234567890123456789012345678901234567890123456789012345678901234");
  check(fs, "0123456789012345678901234567890123456789012345678901234567890123"); // note: last dig truncated
}

// check max-size
template<>
template<>
void testObj::test<4>(void)
{
  ensure_equals("invalid max size", FastString::maxSize(), 64);
}

// check size
template<>
template<>
void testObj::test<5>(void)
{
  const FastString fs("abc");
  ensure_equals("invalid size", fs.size(), 3);
}

// check non-const []
template<>
template<>
void testObj::test<6>(void)
{
  FastString fs("Abc");
  fs[2]='C';
  check(fs, "AbC");
}

// check const []
template<>
template<>
void testObj::test<7>(void)
{
  const FastString fs("abc");
  ensure_equals("invalid char 1", fs[0], 'a');
  ensure_equals("invalid char 2", fs[1], 'b');
  ensure_equals("invalid char 3", fs[2], 'c');
}

// check creation from NULL
template<>
template<>
void testObj::test<8>(void)
{
  const FastString fs(NULL);
  check(fs, "");
}

// check assignment of C-string
template<>
template<>
void testObj::test<9>(void)
{
  FastString fs("abc");
  fs="xyz";
  check(fs, "xyz");
}

// check assignment of NULL C-string
template<>
template<>
void testObj::test<10>(void)
{
  FastString fs("abc");
  fs=NULL;
  check(fs, "");
}

// check assignment of std::string
template<>
template<>
void testObj::test<11>(void)
{
  FastString fs("abc");
  fs=std::string("qwerty");
  check(fs, "qwerty");
}

// test assigning too long string
template<>
template<>
void testObj::test<12>(void)
{
  FastString fs("xyz");
  fs="01234567890123456789012345678901234567890123456789012345678901234";
  check(fs, "0123456789012345678901234567890123456789012345678901234567890123"); // note: last dig truncated
}

// check getting terminating zero with []
template<>
template<>
void testObj::test<13>(void)
{
  FastString fs("0123456789012345678901234567890123456789012345678901234567890123");
  ensure("unable to get last char", fs[ FastString::maxSize() ]==0 );
}

} // namespace tut
