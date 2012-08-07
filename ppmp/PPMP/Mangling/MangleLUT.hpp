/*
 * MangleLUT.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_MANGLELUT_HPP_FILE
#define INCLUDE_PPMP_MANGLING_MANGLELUT_HPP_FILE

#include "PPMP/Mangling/Mangler.hpp"
#include "PPMP/Mangling/LookUpTable.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief generic LUT-processor implementation.
 */
class MangleLUT: public  Mangler,
                 private LookUpTable
{
protected:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  explicit MangleLUT(Processor &out):
    Mangler(out)
  {
  }
  /** \brief method for changing entry in LUT.
   *  \param from position to modify.
   *  \param to   new entry.
   */
  inline void changeLUT(const char from, const char to)
  {
    changeEntry(from, to);
  }

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out);
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
