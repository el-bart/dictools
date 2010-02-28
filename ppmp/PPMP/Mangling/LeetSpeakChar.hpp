/*
 * LeetSpeakChar.hpp
 *
 */
#ifndef INCLUDE_PPMP_MANGLING_LEETSPEAKCHAR_HPP_FILE
#define INCLUDE_PPMP_MANGLING_LEETSPEAKCHAR_HPP_FILE

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/noncopyable.hpp>
#include <cassert>

namespace PPMP
{
namespace Mangling
{

/** \brief createor of objects' call chain.
 */
struct CallForwarder: private boost::noncopyable
{
  /** \brief ensure polymorphic deallocation.
   */
  virtual ~CallForwarder(void)
  {
  }
  /** \brief forwards to next caller.
   */
  virtual void processNext(void) = 0;
}; // struct CallForwarder


/** \brief proxy for updating LUT table entries.
 */
struct LUTUpdater: private boost::noncopyable
{
  /** \brief ensure polymorphic deallocation.
   */
  virtual ~LUTUpdater(void)
  {
  }
  /** \brief update entry in LUT table.
   *  \param from char to be translated.
   *  \param to   char to tranlsate to.
   */
  virtual void updateLUT(char from, char to) = 0;
}; // struct LUTupdater


/** \brief converts given char to most common leet-speak equivalents.
 */
template<char C, typename TVectorC>
class LeetSpeakChar: public CallForwarder
{
public:
  /** \brief create processor.
   *  \param next    forward to next element in chain.
   *  \param lutUpdt proxy object for LUT updating.
   */
  LeetSpeakChar(CallForwarder &next, LUTUpdater &lutUpdt):
    f_(next, lutUpdt)
  {
  }
  /** \brief entry point for processing.
   */
  virtual void processNext(void)
  {
    boost::mpl::for_each<TVectorC>(f_);
  }

private:
  // helpoer object to do work in each call
  struct FuncObj
  {
    FuncObj(CallForwarder &next, LUTUpdater &lutUpdt):
      next_(&next),
      lutUpdt_(&lutUpdt)
    {
    }

    void operator()(const char t)
    {
      assert(lutUpdt_!=NULL);
      assert(next_   !=NULL);
      lutUpdt_->updateLUT(C, t);    // overwite previous entry
      next_->processNext();         // continue execution
    }

    CallForwarder *next_;
    LUTUpdater    *lutUpdt_;
  }; // struct FuncObj

  FuncObj f_;
}; // class LeetSpeakChar

} // namespace Mangling
} // namespace PPMP

#endif
