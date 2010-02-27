/*
 * SimpleLeetSpeak.cpp
 *
 */
#include "PPMP/Mangling/SimpleLeetSpeak.hpp"

namespace PPMP
{
namespace Mangling
{

SimpleLeetSpeak::SimpleLeetSpeak(Processor &out):
  MangleLUT(out)
{
  changeLUT('a', '4');
  changeLUT('A', '4');

  changeLUT('e', '3');
  changeLUT('E', '3');

  changeLUT('i', '1');
  changeLUT('I', '1');

  changeLUT('s', '$');
  changeLUT('S', '$');

  changeLUT('o', '0');
  changeLUT('O', '0');

  changeLUT('b', '8');
  changeLUT('B', '8');

  changeLUT('g', '9');
  changeLUT('G', '9');

  changeLUT('s', 'z');
  changeLUT('S', '5');
}

} // namespace Mangling
} // namespace PPMP
