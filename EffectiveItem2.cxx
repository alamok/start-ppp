// Effective C++::Third Edition::Item 2:p16
// Avoid macro nonsense and use Template for inline function
// Here we will demonstrate how #defines can mess up with things
// and how using templates for inline can avoid all that trouble

#include <iostream>
using namespace std;

#define COMPARE(a,b) cout<< ( (a) > (b) ? (a) : (b))<< endl;

template<typename T>
inline void Max( const T& a, const T& b )
{
  ( a > b ? ( cout << a << endl ): ( cout << b << endl ));
}

int main()
{
  int a = 5;
  int b = 0;

  COMPARE(++a,b);
  cout << "a = " << a << " b = " << b << endl;

  a = 5;
  b = 0;

  COMPARE(++a,b+10);
  cout << "a = " << a << " b = " << b << endl;

  // Can be fixed by using templates for inline function
  Max( a, b );
  return 0;
}
