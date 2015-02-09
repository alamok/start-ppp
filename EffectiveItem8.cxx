#include <iostream>
#include <sstream>
using namespace std;

// Quite Intresting phenomenon
// If c++ code has met an exception It tries to perfrom stack unwinding
// which essentially means moving to a poing from where the outer most call was made and looking for a catch
// It closes and destroys all the objects while it tries to unwind
// If during this it the code comes accross any other expecption then this casues undefined behaviour for the program.
// it reaches a catch only when it has deleted all the objects reaming successfully if somebody throws exception form there

class centralDefenders
{
public:
	centralDefenders()
	{
		cout << "in ctor" << endl;
	}
	~centralDefenders()
	{
		cout << "in dtor" << endl;
		throw ( 5 );
	}
};

void test()
{
	centralDefenders arr[5];
}

int main()
{
	try
	{
	test();
	}
	catch( int a  )
	{
		cout << "found something" << endl;
	}
	return 0;
}