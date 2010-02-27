/*
 * AppendYear.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_APPENDTYEAR_HPP_FILE
#define INCLUDE_PPMP_MANGLING_APPENDTYEAR_HPP_FILE

#include "PPMP/Mangling/NumberAdder.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief processor appending year number to string.
 */
class AppendYear: public NumberAdder
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit AppendYear(Processor &out);
}; // class AppendYear

} // namespace Mangling
} // namespace PPMP

#endif
