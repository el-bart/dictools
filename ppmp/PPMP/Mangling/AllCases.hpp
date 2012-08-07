/*
 * AllCases.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_ALLCASES_HPP_FILE
#define INCLUDE_PPMP_MANGLING_ALLCASES_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief make all possible case changes.
 */
class AllCases: public Mangler
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit AllCases(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);
}; // class AllCases

} // namespace Mangling
} // namespace PPMP

#endif
