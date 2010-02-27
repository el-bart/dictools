/*
 * MangleLUT.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <string>

#include "PPMP/Mangling/MangleLUT.hpp"

using namespace PPMP::Mangling;

namespace
{

struct TestClass: public MangleLUT
{
  TestClass(void):
    MangleLUT(1)
  {
  }
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
  const Common::FastString in("aAbBcCqQ");
  const StringsSet &str=mangle(in);
  ensure_equals("invalid number of elements", str.size(), 1);
  ensure_equals("invalid LUT translation", str[0].c_str(),
                                           std::string("QAbBcxqQ") );
}

} // namespace tut
