/*
 * FastString.hpp
 *
 */
#ifndef INCLUDE_COMMON_FASTSTRING_HPP_FILE
#define INCLUDE_COMMON_FASTSTRING_HPP_FILE

#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>

/* public header */

namespace Common
{
/** \brief implementation of short string with direct access to data.
 */
class FastString
{
public:
  /** \brief create empty string.
   */
  FastString(void)
  {
    data_[0]=0;
  }
  /** \brief create copy of a given string.
   *  \param str string to create it from.
   *
   *  NULL will be translated to empty string. too long
   *  string will be truncated.
   */
  FastString(const char *str)
  {
    fromString(str);
  }
  /** \brief access to elements, without range-check.
   *  \param pos element to take.
   *  \return char on given posiont.
   */
  char operator[](unsigned char pos) const
  {
    assertPos(pos);
    return data_[pos];
  }
  /** \brief access to elements, without range-check - const version.
   *  \param pos element to take.
   *  \return char on given posiont.
   */
  char &operator[](unsigned char pos)
  {
    assertPos(pos);
    return data_[pos];
  }
  /** \brief get const pointer to data.
   *  \return read-only data pointer.
   */
  const char *c_str(void) const
  {
    return data_;
  }
  /** \brief get access to raw data.
   *  \return data pointer, that can be written.
   *
   *  this method is provided for performance reasons, though its usage
   *  should be avoided. if needed, use with extreme caution.
   */
  char *get(void)
  {
    return data_;
  }
  /** \brief computes lenght of string.
   *  \return string's lenght (size).
   */
  size_t size(void) const
  {
    return strlen(data_);
  }
  /** \brief gets maximum length of a string, that can be held inside.
   *  \return maximum stirng size.
   */
  static size_t maxSize(void)
  {
    return sizeof(data_)-1;
  }
  /** \brief assign data from c-string.
   *  \param str intring to get data from.
   *  \return this object.
   */
  const FastString &operator=(const char *str)
  {
    fromString(str);
    return *this;
  }
  /** \brief assign data from std::string.
   *  \param str intring to get data from.
   *  \return this object.
   */
  const FastString &operator=(const std::string &str)
  {
    fromString( str.c_str() );
    return *this;
  }

private:
  void assertPos(unsigned char pos) const
  {
    ignore(pos);
    assert( pos<=maxSize() && "requested index out of scope" );
  }
  void ignore(unsigned char) const
  {
  }

  void fromString(const char *str)
  {
    if(str==NULL)
      data_[0]=0;
    else
    {
      strncpy(data_, str, sizeof(data_) );
      data_[maxSize()]=0;   // ensure NULL-termination
    }
  }

  char data_[64+1];   // max password length
}; // class FastString

} // namespace Common

#endif
