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
  HelperLUT          *lut_;
}; // class LeetSpeak

} // namespace Mangling
} // namespace PPMP

#endif
