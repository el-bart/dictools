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
  a_(out), A_(a_),
  b_(A_),  B_(b_),
  c_(B_),  C_(c_),
  d_(C_),  D_(d_),
  e_(D_),  E_(e_),
  f_(E_),  F_(f_),
  g_(F_),  G_(g_),
  h_(G_),  H_(h_),
  i_(H_),  I_(i_),
  k_(I_),  K_(k_),
  l_(K_),  L_(l_),
  n_(L_),  N_(n_),
  o_(N_),  O_(o_),
  s_(O_),  S_(s_),
  t_(S_),  T_(t_),
  u_(T_),  U_(u_),
  y_(U_),  Y_(y_),
  z_(Y_),  Z_(z_)
{
}

void LeetSpeak::mangleImpl(Common::FastString &str, Processor &/*out*/)
{
  Z_.process(str);
}

} // namespace Mangling
} // namespace PPMP
