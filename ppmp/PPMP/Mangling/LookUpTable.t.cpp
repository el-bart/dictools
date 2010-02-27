/*
 * LookUpTable.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "PPMP/Mangling/LookUpTable.hpp"

using namespace PPMP::Mangling;

namespace
{

struct TestClass: public LookUpTable
{
  TestClass(void):
    l_(*this)
  {
  }

  void check(const char c, const char is) const
  {
    tut::ensure_equals("invalid char", l_[c], is);
  }

  LookUpTable &l_;
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/LookUpTable");
} // unnamed namespace


namespace tut
{

// test gettting small element
template<>
template<>
void testObj::test<1>(void)
{
  check(42, 42);
}

// test getting >127 element
template<>
template<>
void testObj::test<2>(void)
{
  check(220, 220);
}

// test changing some element
template<>
template<>
void testObj::test<3>(void)
{
  changeEntry(131, 42);
  check(131, 42);
}

// test const []
template<>
template<>
void testObj::test<4>(void)
{
  const LookUpTable &lut=*this;
  ensure_equals("invalid element", lut['a'], 'a');  // should compile
}

} // namespace tut
