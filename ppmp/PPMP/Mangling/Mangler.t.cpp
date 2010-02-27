/*
 * Mangler.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "PPMP/Mangling/Mangler.hpp"
#include <string>

using namespace PPMP::Mangling;

namespace
{

struct Derived: public Mangler
{
  Derived(void):
    tmp_(NULL)
  {
  }

private:
  virtual void mangleImpl(const Common::FastString &in, StringsSet &out)
  {
    if(tmp_==NULL)
      tmp_=&out;
    else
      tut::ensure("collection changed", tmp_==&out);

    out.resize(1);
    Common::FastString tmp=in;
    tmp[0]='Q';
    out[0]=tmp;
  }

  StringsSet *tmp_;
};

struct TestClass
{
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/Mangler");
} // unnamed namespace


namespace tut
{

// check c-tor
template<>
template<>
void testObj::test<1>(void)
{
  Derived d;
}

// check virtual call
template<>
template<>
void testObj::test<2>(void)
{
  Derived d;
  d.mangle("abc");
  d.mangle("x");        // should not throw
}

// check output
template<>
template<>
void testObj::test<3>(void)
{
  Derived d;
  const Derived::StringsSet &out=d.mangle("aX");
  ensure_equals("invalid output size", out.size(), 1);
  ensure_equals("invalid output string", out[0].c_str(), std::string("QX") );
}

namespace
{
struct DerivedSize: public Mangler
{
  DerivedSize(void):
    Mangler(42)
  {
  }

private:
  virtual void mangleImpl(const Common::FastString &/*in*/, StringsSet &out)
  {
    tut::ensure_equals("invalid collection size", out.size(), 42);
  }
}; // struct DerivedSize
} // unnamed namespace

// check explicit size setting
template<>
template<>
void testObj::test<4>(void)
{
  DerivedSize d;
  d.mangle("ab");   // checking is done here
}

} // namespace tut
