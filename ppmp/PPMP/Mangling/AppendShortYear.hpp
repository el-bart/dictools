/*
 * AppendShortYear.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_APPENDSHORTYEAR_HPP_FILE
#define INCLUDE_PPMP_MANGLING_APPENDSHORTYEAR_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Mangling/NumberAdder.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief processor appending 2-digit year number to string.
 */
class AppendShortYear: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit AppendShortYear(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);

  NumberAdder na199x_;
  NumberAdder na200x_;
  NumberAdder na201x_;
}; // class AppendShortYear

} // namespace Mangling
} // namespace PPMP

#endif
