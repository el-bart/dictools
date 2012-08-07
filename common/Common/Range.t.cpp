/*
 * Range.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "Common/Range.hpp"

using namespace Common;

namespace
{
struct TestClass
{
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("Common/Range");
} // unnamed namespace


namespace tut
{

// test typical range
template<>
template<>
void testObj::test<1>(void)
{
  const Range r(2, 5);
  ensure_equals("invalid from value", r.from(), 2);
  ensure_equals("invalid to value", r.to(), 5);
  ensure_equals("invalid span", r.span(), 4);
}

// test single number
template<>
template<>
void testObj::test<2>(void)
{
  const Range r(6, 6);
  ensure_equals("invalid from value", r.from(), 6);
  ensure_equals("invalid to value", r.to(), 6);
  ensure_equals("invalid span", r.span(), 1);
}

// test negative values
template<>
template<>
void testObj::test<3>(void)
{
  const Range r(-5, -2);
  ensure_equals("invalid from value", r.from(), -5);
  ensure_equals("invalid to value", r.to(), -2);
  ensure_equals("invalid span", r.span(), 4);
}

// test typical range, reverse order
template<>
template<>
void testObj::test<4>(void)
{
  const Range r(5, 2);
  ensure_equals("invalid from value", r.from(), 2);
  ensure_equals("invalid to value", r.to(), 5);
  ensure_equals("invalid span", r.span(), 4);
}

// test negative values, reverse order
template<>
template<>
void testObj::test<5>(void)
{
  const Range r(-2, -5);
  ensure_equals("invalid from value", r.from(), -5);
  ensure_equals("invalid to value", r.to(), -2);
  ensure_equals("invalid span", r.span(), 4);
}

} // namespace tut
