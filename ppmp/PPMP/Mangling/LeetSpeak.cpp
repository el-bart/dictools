/*
 * LeetSpeak.cpp
 *
 */
#include "PPMP/Mangling/LeetSpeak.hpp"

namespace PPMP
{
namespace Mangling
{

LeetSpeak::LeetSpeak(Processor &out):
  Mangler(out),
  str_(NULL),
  proc_(NULL),
  lut_(out),
  a_(*this, *this), A_(a_, *this),
  b_(A_,    *this), B_(b_, *this),
  c_(B_,    *this), C_(c_, *this),
  d_(C_,    *this), D_(d_, *this),
  e_(D_,    *this), E_(e_, *this),
  f_(E_,    *this), F_(f_, *this),
  g_(F_,    *this), G_(g_, *this),
  h_(G_,    *this), H_(h_, *this),
  i_(H_,    *this), I_(i_, *this),
  k_(I_,    *this), K_(k_, *this),
  l_(K_,    *this), L_(l_, *this),
  n_(L_,    *this), N_(n_, *this),
  o_(N_,    *this), O_(o_, *this),
  s_(O_,    *this), S_(s_, *this),
  t_(S_,    *this), T_(t_, *this),
  u_(T_,    *this), U_(u_, *this),
  y_(U_,    *this), Y_(y_, *this),
  z_(Y_,    *this), Z_(z_, *this)
{
}

void LeetSpeak::mangleImpl(Common::FastString &str, Processor &out)
{
  proc_=&out;
  str_ =&str;
  Z_.processNext();     // go!
  proc_=NULL;
  str_ =NULL;
}

void LeetSpeak::processNext(void)
{
  assert(proc_!=NULL);
  assert(str_ !=NULL);
  Common::FastString tmp=*str_;
  // go to next processor
  lut_.process(tmp);        // do actuall LUT
}

void LeetSpeak::updateLUT(char from, char to)
{
  lut_.update(from, to);
}

} // namespace Mangling
} // namespace PPMP
