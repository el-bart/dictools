#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

typedef vector<char> Cassette;

class Series
{
private:
  typedef Cassette::const_iterator Iterator;
  typedef vector<int>              Rotations;

public:
  Series(const Cassette *cas, int size):
    cas_(cas),
    size_(size),
    noMore_(false)
  {
    assert(cas_!=NULL);
    assert(size_>0);
    assert( size_<(int)sizeof(out_)-1 );

    for(int i=0; i<size_; ++i)
      rot_.push_back(0);
  }

  const char *next(void)
  {
    if(noMore_)
      return NULL;

    int   mov        =1;
    int   overflows  =0;
    char *out        =out_;

    assert( (int)rot_.size()==size_ );
    for(Rotations::iterator it=rot_.begin(); it!=rot_.end(); ++it)
    {
      *out=cas_->at(*it);
      *it+=mov;

      if( *it==(int)cas_->size() )
      {
        assert(mov==1);
        *it=0;
        ++overflows;
      }
      else
        mov=0;

      ++out;
    }

    // null-terminate
    *out=0;

    if(overflows==size_)
      noMore_=true;
    return out_;
  }

private:
  char            out_[20];
  Rotations       rot_;
  const Cassette *cas_;
  int             size_;
  bool            noMore_;
}; // class Series

int main(int argc, char **argv)
{
  if(argc<2)
  {
    cerr<<argv[0]<<" <len1> <len2> ... <lenN>"<<endl;
    return 1;
  }

  Cassette cas;
  for(char c='a'; c<='z'; ++c)
    cas.push_back(c);

  for(int i=1; i<argc; ++i)
  {
    Series s(&cas, atoi(argv[i]) );
    const char *out;
    while( ( out=s.next() )!=NULL )
    {
      assert( strlen(out)<10 );
      cout<<out<<endl;
    } // while( permut() )
  }

  return 0;
}
