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
  NumberAdder(out, Range(1950, 2011) )  // TODO: fix this
{
}

} // namespace Mangling
} // namespace PPMP
