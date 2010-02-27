/*
 * LookUpTable.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LOOKUPTABLE_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LOOKUPTABLE_HPP_FILE

#include <cassert>

namespace PPMP
{
namespace Mangling
{

/** \brief lookup table's engine implementation.
 */
class LookUpTable
{
public:
  /** \brief transform with LUT operation.
   *  \param c input char.
   *  \return LUT-translated char.
   */
  char operator[](const char c) const
  {
    return lut_[ index(c) ];
  }

protected:
  /** \brief create instence.
   */
  LookUpTable(void)
  {
    for(int i=0; i<static_cast<int>( sizeof(lut_) ); ++i)
      lut_[i]=static_cast<char>(i);
  }
  /** \brief modifiy LUT mapping.
   *  \param from position to modify.
   *  \param to   new entry.
   */
  void changeEntry(const char from, const char to)
  {
    lut_[ index(from) ]=to;
  }

private:
  inline unsigned int index(const char c) const
  {
    const unsigned char uc=(unsigned char)(c);
    const unsigned int  i =uc;
    //assert( 0<=i );
    assert( i<256 );
    return i;
  }

  char lut_[256];   // all characters are mapped
}; // class LookUpTable

} // namesapce Mangling
} // namespace PPMP

#endif
