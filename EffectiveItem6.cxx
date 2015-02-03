#include <iostream>
#include <sstream>
using namespace std;

// If you dont want to compiler to add copy constructors and assignment operator
// Define a private copy constructor and assignment operator
// This scheme isn't full proof as member functions or friend funcitons may call this ctor
// A better scheme defined below.

class HomeForSale
{
public:
	HomeForSale()
	{
	}
private:
HomeForSale(const HomeForSale&); // declarations only
HomeForSale& operator=(const HomeForSale&);
};

// A more simple design can be achived by derving a class from a class which has
// copy ctor and = operator as private
class Uncopyable
{
protected: // allow construction
Uncopyable() {} // and destruction of
~Uncopyable() {} // derived objects...
private:
Uncopyable(const Uncopyable&); // ...but prevent copying
Uncopyable& operator=(const Uncopyable&);
};

class HomeForSaleAdv : private Uncopyable
{
public:
	HomeForSaleAdv()
	{
	}
private:
HomeForSaleAdv(const HomeForSale&); // declarations only
HomeForSaleAdv& operator=(const HomeForSale&);
};

int main()
{
	HomeForSale obj1;
	// uncomment to get errors
	// HomeForSale obj2(obj1);

	HomeForSaleAdv obj3;
	// uncomment to get errors
	//HomeForSaleAdv obj4(obj3);
	return 0;
}