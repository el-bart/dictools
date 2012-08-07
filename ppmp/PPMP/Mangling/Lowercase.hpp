/*
 * Lowercase.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LOWERCASE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LOWERCASE_HPP_FILE

#include "PPMP/Mangling/MangleLUT.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief mangler converting string to lower case.
 */
class Lowercase: public MangleLUT
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit Lowercase(Processor &out);
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
