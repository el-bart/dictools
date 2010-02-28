/*
 * LeetSpeak.cpp
 *
 */
#include "PPMP/Mangling/LeetSpeak.hpp"
#include <deque>
#include <boost/shared_ptr.hpp>
#include <cstring>
#include <cassert>

using namespace std;
using namespace boost;

namespace PPMP
{
namespace Mangling
{

LeetSpeak::LeetSpeak(Processor &out):
  Mangler(out),
  str_(NULL),
  proc_(NULL),
  lut_(NULL)
{
}

namespace
{
typedef shared_ptr<CallForwarder> CharPtr;
typedef deque<CharPtr>            CallChain;

// helper call. check if given entry exists in string and
// adds it to the chain, if needed.
template<char C, typename TVectorC>
CallForwarder *addIfCharInUse(const Common::FastString &str,
                              CallChain                &cc,
                              CallForwarder            *next,
                              LUTUpdater               &updater)
{
  assert(next!=NULL);
  const size_t len=str.size();
  for(size_t i=0; i<len; ++i)
    if( str[i]==C )             // ok - string has this char
    {
      CharPtr ptr( new LeetSpeakChar<C, TVectorC>(*next, updater) );
      cc.push_back(ptr);
      return ptr.get();         // return new one
    }
  return next;                  // if nothing added, nothing happened
} // addIfCharInUse()

} // unnamed namespace

void LeetSpeak::mangleImpl(Common::FastString &str, Processor &out)
{
  HelperLUT      lut(out);
  CallChain      cc;
  CallForwarder *next=this;

  lut_ =&lut;
  proc_=&out;
  str_ =&str;

  next=addIfCharInUse<'a', boost::mpl::vector_c<char, '@','4'> >(str, cc, next, *this);
  next=addIfCharInUse<'A', boost::mpl::vector_c<char, '@','4'> >(str, cc, next, *this);

  next=addIfCharInUse<'b', boost::mpl::vector_c<char, '8'> >(str, cc, next, *this);
  next=addIfCharInUse<'B', boost::mpl::vector_c<char, '8'> >(str, cc, next, *this);

  next=addIfCharInUse<'c', boost::mpl::vector_c<char, '[','<','('> >(str, cc, next, *this);
  next=addIfCharInUse<'C', boost::mpl::vector_c<char, '[','<','('> >(str, cc, next, *this);

  next=addIfCharInUse<'d', boost::mpl::vector_c<char, ']','>',')'> >(str, cc, next, *this);
  next=addIfCharInUse<'D', boost::mpl::vector_c<char, ']','>',')'> >(str, cc, next, *this);

  next=addIfCharInUse<'e', boost::mpl::vector_c<char, '3','&','{'> >(str, cc, next, *this);
  next=addIfCharInUse<'E', boost::mpl::vector_c<char, '3','&','{'> >(str, cc, next, *this);

  next=addIfCharInUse<'f', boost::mpl::vector_c<char, 'v'> >(str, cc, next, *this);
  next=addIfCharInUse<'F', boost::mpl::vector_c<char, 'v'> >(str, cc, next, *this);

  next=addIfCharInUse<'g', boost::mpl::vector_c<char, '6','&','9'> >(str, cc, next, *this);
  next=addIfCharInUse<'G', boost::mpl::vector_c<char, '6','&','9'> >(str, cc, next, *this);

  next=addIfCharInUse<'h', boost::mpl::vector_c<char, '#'> >(str, cc, next, *this);
  next=addIfCharInUse<'H', boost::mpl::vector_c<char, '#'> >(str, cc, next, *this);

  next=addIfCharInUse<'i', boost::mpl::vector_c<char, '1','!','|'> >(str, cc, next, *this);
  next=addIfCharInUse<'I', boost::mpl::vector_c<char, '1','!','|'> >(str, cc, next, *this);

  // no 'j'

  next=addIfCharInUse<'k', boost::mpl::vector_c<char, 'x'> >(str, cc, next, *this);
  next=addIfCharInUse<'K', boost::mpl::vector_c<char, 'X'> >(str, cc, next, *this);

  next=addIfCharInUse<'l', boost::mpl::vector_c<char, '1', '7', '|'> >(str, cc, next, *this);
  next=addIfCharInUse<'L', boost::mpl::vector_c<char, '1', '7', '|'> >(str, cc, next, *this);

  // no 'm'

  next=addIfCharInUse<'n', boost::mpl::vector_c<char, '^'> >(str, cc, next, *this);
  next=addIfCharInUse<'N', boost::mpl::vector_c<char, '^'> >(str, cc, next, *this);

  next=addIfCharInUse<'o', boost::mpl::vector_c<char, '0'> >(str, cc, next, *this);
  next=addIfCharInUse<'O', boost::mpl::vector_c<char, '0'> >(str, cc, next, *this);

  // no 'p'

  // no 'q'

  // no 'r'

  next=addIfCharInUse<'s', boost::mpl::vector_c<char, '5','$','z'> >(str, cc, next, *this);
  next=addIfCharInUse<'S', boost::mpl::vector_c<char, '5','$','Z'> >(str, cc, next, *this);

  next=addIfCharInUse<'t', boost::mpl::vector_c<char, '7','+'> >(str, cc, next, *this);
  next=addIfCharInUse<'T', boost::mpl::vector_c<char, '7','+'> >(str, cc, next, *this);

  next=addIfCharInUse<'u', boost::mpl::vector_c<char, 'v'> >(str, cc, next, *this);
  next=addIfCharInUse<'U', boost::mpl::vector_c<char, 'V'> >(str, cc, next, *this);

  // no 'v'

  // no 'w'

  // no 'x'

  next=addIfCharInUse<'y', boost::mpl::vector_c<char, 'j','4','7'> >(str, cc, next, *this);
  next=addIfCharInUse<'Y', boost::mpl::vector_c<char, 'j','4','7'> >(str, cc, next, *this);

  next=addIfCharInUse<'z', boost::mpl::vector_c<char, '2','%','s'> >(str, cc, next, *this);
  next=addIfCharInUse<'Z', boost::mpl::vector_c<char, '2','%','S'> >(str, cc, next, *this);

  assert(next!=NULL);
  next->processNext();      // go!

  lut_ =NULL;
  proc_=NULL;
  str_ =NULL;
}

void LeetSpeak::processNext(void)
{
  assert(str_ !=NULL);
  assert(lut_ !=NULL);
  Common::FastString tmp=*str_;
  // go to next processor
  lut_->process(tmp);       // do actuall LUT and proceed
}

void LeetSpeak::updateLUT(char from, char to)
{
  assert(lut_!=NULL);
  lut_->update(from, to);
}

} // namespace Mangling
} // namespace PPMP
