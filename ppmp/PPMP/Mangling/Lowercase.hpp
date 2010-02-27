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

class Lowercase: public MangleLUT
{
public:
  explicit Lowercase(Processor &out);
}; // class Lowercase

} // namespace Mangling
} // namespace PPMP

#endif
