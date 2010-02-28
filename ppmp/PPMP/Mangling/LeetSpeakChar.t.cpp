/*
 * LeetSpeakChar.t.cpp
 *
 */
#include <tut/tut.hpp>
#include <map>
#include <queue>
#include <string>

#include "PPMP/Mangling/LeetSpeakChar.hpp"

using namespace std;
using namespace PPMP;
using namespace PPMP::Mangling;

namespace
{

struct TestClass: public CallForwarder,
                  public LUTUpdater
{
  map<char, char> out_;
  queue<string>   expected_;

  virtual void processNext(void)
  {
    stringstream from;
    stringstream to;
    // compute results
    for(map<char, char>::const_iterator it=out_.begin(); it!=out_.end(); ++it)
    {
      from<<it->first;
      to  <<it->second;
    }
    const string tmp=from.str() + "->" + to.str();

    // check
    tut::ensure_equals("invalid translation", tmp, expected_.front() );
    expected_.pop();
  }

  virtual void updateLUT(char from, char to)
  {
    out_[from]=to;
  }
};

typedef tut::test_group<TestClass> factory;
typedef factory::object            testObj;

factory tf("PPMP/Mangling/LeetSpeakChar");
} // unnamed namespace


namespace tut
{

// test some leet-speaking
template<>
template<>
void testObj::test<1>(void)
{
  LeetSpeakChar<'a', boost::mpl::vector_c<char, 'X', 'Y', 'Z'> > lsc(*this, *this);
  expected_.push("a->X");
  expected_.push("a->Y");
  expected_.push("a->Z");

  // test
  lsc.processNext();

  // check if nothing has left
  ensure_equals("not all elements generated", expected_.size(), 0);
}

// test 1-element subsitution
template<>
template<>
void testObj::test<2>(void)
{
  LeetSpeakChar<'a', boost::mpl::vector_c<char, 'Z'> > lsc(*this, *this);
  expected_.push("a->Z");

  // test
  lsc.processNext();

  // check if nothing has left
  ensure_equals("not all elements generated", expected_.size(), 0);
}

// test chain
template<>
template<>
void testObj::test<3>(void)
{
  LeetSpeakChar<'a', boost::mpl::vector_c<char, 'Z', 'Q', 'F'> > lscA(*this, *this);
  LeetSpeakChar<'b', boost::mpl::vector_c<char, 'X', 'W'> >      lscB(lscA,  *this);
  expected_.push("ab->ZX");
  expected_.push("ab->QX");
  expected_.push("ab->FX");
  expected_.push("ab->ZW");
  expected_.push("ab->QW");
  expected_.push("ab->FW");

  // test
  lscB.processNext();

  // check if nothing has left
  ensure_equals("not all elements generated", expected_.size(), 0);
}

} // namespace tut
