/*
 * LeetSpeakChar.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LEETSPEAKCHAR_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LEETSPEAKCHAR_HPP_FILE

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector_c.hpp>

#include "PPMP/Mangling/MangleLUT.hpp"

namespace PPMP
{
namespace Mangling
{

/** \brief converts given char to most common leet-speak equivalents.
 */
template<typename TVectorC>
class LeetSpeakChar: public MangleLUT
{
public:
  /** \brief create processor.
   *  \param out next (output) processor.
   */
  LeetSpeakChar(Processor &out, char c):
    MangleLUT(out),
    c_(c)
  {
  }

private:
  struct MakeSubst
  {
    MakeSubst(const char c, Processor *out, const Common::FastString &str):
      c_(c),
      out_(out),
      str_(str)
    {
    }

    template<typename T>
    void operator()(const T t) const
    {
      Common::FastString tmp;
      for(size_t j=0; j<str_.size(); ++j)
        tmp[j]=(str_[j]==c_)?t:str_[j];
      tmp[ str_.size() ]=0;

      out_->process(tmp);
    }

    char                c_;
    Processor          *out_;
    Common::FastString  str_;
  }; // struct MakeSubst


  virtual void mangleImpl(Common::FastString &str, Processor &out)
  {
    boost::mpl::for_each<TVectorC>( MakeSubst(c_, &out, str) );
    //for(size_t i=0; i<boost::mpl::size<TVectorC>::type::value; ++i)
    /*{
      const char         change=boost::mpl::at_c<TVectorC, i>::type::value;
    }*/
  }

  const char c_;
}; // class LeetSpeakChar

} // namespace Mangling
} // namespace PPMP

#endif
