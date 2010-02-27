/*
 * Mangler.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE
#define INCLUDE_PPMP_MANGLING_MANGLER_HPP_FILE

#include "Common/FastString.hpp"
#include "PPMP/Processor.hpp"

namespace PPMP
{
namespace Mangling
{

class Mangler: public Processor
{
public:
  virtual void process(Common::FastString &str)
  {
    mangleImpl(str, out_);
  }

protected:
  explicit Mangler(Processor &out);

private:
  virtual void mangleImpl(Common::FastString &str, Processor &out) = 0;

  Processor &out_;
}; // class Mangler

} // namespace Mangling
} // namespace PPMP

#endif
