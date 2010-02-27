/*
 * Mangler.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE
#define INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE

#include "Common/FastString.hpp"
#include "PPMP/Output.hpp"

namespace PPMP
{
namespace Mangling
{

class Mangler: public Output
{
public:
  const StringsSet &mangle(const Common::FastString &in)
  {
    mangleImpl(in, out_);
    return out_;
  }

protected:
  explicit Mangler(Output &out);

private:
  virtual void mangleImpl(const Common::FastString &in, Output &out) = 0;
  virtual void proceed(Common::FastString &str);


  Output &out_;
}; // class Mangler

} // namespace Mangling
} // namespace PPMP

#endif
