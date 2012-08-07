/*
 * Mangler.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/ProcessorStub.t.hpp"
#include <string>

using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct Derived: public Mangler
{
  Derived(Processor &out):
    Mangler(out),
    tmp_(NULL)
  {
  }

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out)
  {
    if(tmp_==NULL)
      tmp_=&out;
    else
      tut::ensure("destination processor changed", tmp_==&out);

    str[0]='Q';
    str[1]=0;
    out.process(str);
  }

  Processor *tmp_;
};

struct TestClass
{
  ProcessorStub ps_;
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
  Derived d(ps_);
}

// check virtual call
template<>
template<>
void testObj::test<2>(void)
{
  Derived d(ps_);
  Common::FastString str("abc");
  d.process(str);
  d.process(str);        // should not throw
}

// check output
template<>
template<>
void testObj::test<3>(void)
{
  Derived            d(ps_);
  Common::FastString str("abc");
  d.process(str);
  ensure_equals("invalid output string", str.c_str(), std::string("Q") );
}

} // namespace tut
