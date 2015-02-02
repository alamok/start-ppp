#include <iostream>
using namespace std;

const int mul(int a , int b)
{
  return a *b;
}

int main()
{
  int a = 0;
  const int b = a;
  if( b == mul(2,3) )
    cout << "hello" << endl;
  return 0;
}
