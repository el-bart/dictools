/*
 * SimpleLeetSpeak.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_SIMPLELEETSPEAK_HPP_FILE
#define INCLUDE_PPMP_MANGLING_SIMPLELEETSPEAK_HPP_FILE

#include "PPMP/Mangling/MangleLUT.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief convert to leet speak - just the basic substitutions.
 */
class SimpleLeetSpeak: public MangleLUT
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit SimpleLeetSpeak(Processor &out);
}; // class SimpleLeetSpeak

} // namespace Mangling
} // namespace PPMP

#endif
