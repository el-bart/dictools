/*
 * Reader.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "PPMP/Reader.hpp"
#include <sstream>

using namespace std;
using namespace Common;
using namespace PPMP;

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

factory tf("PPMP/Reader");
} // unnamed namespace


namespace tut
{

// check c-tor
template<>
template<>
void testObj::test<1>(void)
{
  Reader r(std::cin);
}

// check reading some lines
template<>
template<>
void testObj::test<2>(void)
{
  stringstream ss;
  Reader       r(ss);

  ss<<"line1"<<endl;
  ss<<"line 2"<<endl;
  ss<<"line: 3"<<endl;

  FastString fs;
  ensure("unable to read string 1", r.read(fs) );
  check(fs, "line1");
  ensure("unable to read string 2", r.read(fs) );
  check(fs, "line 2");
  ensure("unable to read string 3", r.read(fs) );
  check(fs, "line: 3");
  ensure("too many strings", !r.read(fs) );
}

// check reading when no new line is present ant the end
template<>
template<>
void testObj::test<3>(void)
{
  stringstream ss;
  Reader       r(ss);
  ss<<"line1";

  FastString fs;
  ensure("unable to read string", r.read(fs) );
  check(fs, "line1");
  ensure("too many strings", !r.read(fs) );
}

} // namespace tut
