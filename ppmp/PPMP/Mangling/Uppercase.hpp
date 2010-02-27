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

class Uppercase: public MangleLUT
{
public:
  explicit Uppercase(Processor &out);
}; // class Uppercase

} // namespace Mangling
} // namespace PPMP

#endif
