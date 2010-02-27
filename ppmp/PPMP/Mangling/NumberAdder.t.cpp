/*
 * NumberAdder.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>

#include "PPMP/Mangling/NumberAdder.hpp"

using namespace std;
using namespace Common;
using namespace PPMP::Mangling;

namespace
{

struct TestClass
{
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
  NumberAdder nc( Common::Range(6,6) );
  const NumberAdder::StringsSet &out=nc.mangle("str");
  ensure_equals("invalid size", out.size(), 1);
  ensure_equals("invalid value", out[0].c_str(), string("str6") );
}

// test adding multiple numbers
template<>
template<>
void testObj::test<2>(void)
{
  NumberAdder nc( Common::Range(11,13) );
  const NumberAdder::StringsSet &out=nc.mangle("str");
  ensure_equals("invalid size", out.size(), 3);
  ensure_equals("invalid value 1", out[0].c_str(), string("str11") );
  ensure_equals("invalid value 2", out[1].c_str(), string("str12") );
  ensure_equals("invalid value 3", out[2].c_str(), string("str13") );
}

// test negative numbers
template<>
template<>
void testObj::test<3>(void)
{
  NumberAdder nc( Common::Range(-2,-3) );
  const NumberAdder::StringsSet &out=nc.mangle("str");
  ensure_equals("invalid size", out.size(), 2);
  ensure_equals("invalid value 1", out[0].c_str(), string("str-3") );
  ensure_equals("invalid value 2", out[1].c_str(), string("str-2") );
}

} // namespace tut
