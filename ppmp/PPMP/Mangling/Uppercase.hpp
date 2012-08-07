/*
 * Uppercase.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_UPPERCASE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_UPPERCASE_HPP_FILE

#include "PPMP/Mangling/MangleLUT.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief convert string to upper-case processor.
 */
class Uppercase: public MangleLUT
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit Uppercase(Processor &out);
}; // class Uppercase

} // namespace Mangling
} // namespace PPMP

#endif
