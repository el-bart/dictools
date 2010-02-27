/*
 * AppendYear.cpp
 *
 */
#include "PPMP/Mangling/AppendYear.hpp"

using namespace Common;

namespace PPMP
{
namespace Mangling
{

AppendYear::AppendYear(Processor &out):
  NumberAdder(out, Range(1970, 2010) )
{
}

} // namespace Mangling
} // namespace PPMP
