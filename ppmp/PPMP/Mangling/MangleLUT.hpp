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

class MangleLUT: public  Mangler,
                 private LookUpTable
{
protected:
  MangleLUT(const size_t size=0):
    Mangler(size)
  {
  }

  inline void changeLUT(const char from, const char to)
  {
    changeEntry(from, to);
  }

private:
  virtual void mangleImpl(const Common::FastString &in, StringsSet &out);
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
