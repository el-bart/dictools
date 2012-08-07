/*
 * Writer.t.cpp
 *
 */
#include <tut/tut.hpp>

#include "PPMP/Writer.hpp"
#include <sstream>

using namespace std;
using namespace Common;
using namespace PPMP;

namespace
{

struct TestClass
{
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Writer");
} // unnamed namespace


namespace tut
{

// check c-tor
template<>
template<>
void testObj::test<1>(void)
{
  Writer w(std::cout);
}

// check writing string
template<>
template<>
void testObj::test<2>(void)
{
  stringstream ss;
  Writer       w(ss);
  FastString   fs("abc");
  w.process(fs);

  {
    stringstream tmp;
    tmp<<"abc"<<endl;   // this is due to different possible implementaions
                        // of end::endl on different systems.
    ensure_equals("invalid string written", ss.str(), tmp.str() );
  }
}

} // namespace tut
