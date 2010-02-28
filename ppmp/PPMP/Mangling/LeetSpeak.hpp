/*
 * LeetSpeak.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LEETSPEAK_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LEETSPEAK_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Mangling/MangleLUT.hpp"
#include "PPMP/Mangling/LeetSpeakChar.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief converts given string to leet-speak
 */
class LeetSpeak: public  Mangler,
                 private CallForwarder,
                 private LUTUpdater
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit LeetSpeak(Processor &out);

private:
  struct HelperLUT: public MangleLUT
  {
    explicit HelperLUT(Processor &out):
      MangleLUT(out)
    {
    }

    void update(char from, char to)
    {
      changeLUT(from, to);
    }
  }; // struct HelperLUT

  virtual void mangleImpl(Common::FastString &str, Processor &out);

  virtual void processNext(void);
  virtual void updateLUT(char from, char to);


  Common::FastString *str_;
  Processor          *proc_;
  HelperLUT           lut_;

  LeetSpeakChar<'a', boost::mpl::vector_c<char, '@','4'> >       a_;
  LeetSpeakChar<'A', boost::mpl::vector_c<char, '@','4'> >       A_;

  LeetSpeakChar<'b', boost::mpl::vector_c<char, '8'> >           b_;
  LeetSpeakChar<'B', boost::mpl::vector_c<char, '8'> >           B_;

  LeetSpeakChar<'c', boost::mpl::vector_c<char, '[','<','('> >   c_;
  LeetSpeakChar<'C', boost::mpl::vector_c<char, '[','<','('> >   C_;

  LeetSpeakChar<'d', boost::mpl::vector_c<char, ']','>',')'> >   d_;
  LeetSpeakChar<'D', boost::mpl::vector_c<char, ']','>',')'> >   D_;

  LeetSpeakChar<'e', boost::mpl::vector_c<char, '3','&','{'> >   e_;
  LeetSpeakChar<'E', boost::mpl::vector_c<char, '3','&','{'> >   E_;

  LeetSpeakChar<'f', boost::mpl::vector_c<char, 'v'> >           f_;
  LeetSpeakChar<'F', boost::mpl::vector_c<char, 'v'> >           F_;

  LeetSpeakChar<'g', boost::mpl::vector_c<char, '6','&','9'> >   g_;
  LeetSpeakChar<'G', boost::mpl::vector_c<char, '6','&','9'> >   G_;

  LeetSpeakChar<'h', boost::mpl::vector_c<char, '#'> >           h_;
  LeetSpeakChar<'H', boost::mpl::vector_c<char, '#'> >           H_;

  LeetSpeakChar<'i', boost::mpl::vector_c<char, '1','!','|'> >   i_;
  LeetSpeakChar<'I', boost::mpl::vector_c<char, '1','!','|'> >   I_;

  // no 'j'

  LeetSpeakChar<'k', boost::mpl::vector_c<char, 'x'> >           k_;
  LeetSpeakChar<'K', boost::mpl::vector_c<char, 'X'> >           K_;

  LeetSpeakChar<'l', boost::mpl::vector_c<char, '1', '7', '|'> > l_;
  LeetSpeakChar<'L', boost::mpl::vector_c<char, '1', '7', '|'> > L_;

  // no 'm'

  LeetSpeakChar<'n', boost::mpl::vector_c<char, '^'> >           n_;
  LeetSpeakChar<'N', boost::mpl::vector_c<char, '^'> >           N_;

  LeetSpeakChar<'o', boost::mpl::vector_c<char, '0'> >           o_;
  LeetSpeakChar<'O', boost::mpl::vector_c<char, '0'> >           O_;

  // no 'p'

  // no 'q'

  // no 'r'

  LeetSpeakChar<'s', boost::mpl::vector_c<char, '5','$','z'> >   s_;
  LeetSpeakChar<'S', boost::mpl::vector_c<char, '5','$','Z'> >   S_;

  LeetSpeakChar<'t', boost::mpl::vector_c<char, '7','+'> >       t_;
  LeetSpeakChar<'T', boost::mpl::vector_c<char, '7','+'> >       T_;

  LeetSpeakChar<'u', boost::mpl::vector_c<char, 'v'> >           u_;
  LeetSpeakChar<'U', boost::mpl::vector_c<char, 'V'> >           U_;

  // no 'v'

  // no 'w'

  // no 'x'

  LeetSpeakChar<'y', boost::mpl::vector_c<char, 'j','4','7'> >   y_;
  LeetSpeakChar<'Y', boost::mpl::vector_c<char, 'j','4','7'> >   Y_;

  LeetSpeakChar<'z', boost::mpl::vector_c<char, '2','%','s'> >   z_;
  LeetSpeakChar<'Z', boost::mpl::vector_c<char, '2','%','S'> >   Z_;
}; // class LeetSpeak

} // namespace Mangling
} // namespace PPMP

#endif
