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

class FastString
{
public:
  FastString(void)
  {
    data_[0]=0;
  }

  FastString(const char *str)
  {
    fromString(str);
  }

  char operator[](unsigned char pos) const
  {
    assertPos(pos);
    return data_[pos];
  }

  char &operator[](unsigned char pos)
  {
    assertPos(pos);
    return data_[pos];
  }

  const char *c_str(void) const
  {
    return data_;
  }

  char *get(void)
  {
    return data_;
  }

  size_t size(void) const
  {
    return strlen(data_);
  }

  static size_t maxSize(void)
  {
    return sizeof(data_)-1;
  }

  const FastString &operator=(const char *str)
  {
    fromString(str);
    return *this;
  }

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
