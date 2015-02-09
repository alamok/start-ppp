#include <iostream>
#include <sstream>
using namespace std;

// Polymorphic base classes should declare virtual destructors. If a
// class has any virtual functions, it should have a virtual destructor.
// Make the destructor of parent class vitual to allow child dtor to delete the objects deleted by it.
// Classes not designed to be base classes or not designed to be used
// polymorphically should not declare virtual destructors.
// Other wise I would be a classic case of memory leak.
// Prove it ..

class parent
{
public:
	int a;
	parent()
	{
		cout << "in parent c'tor" << endl;
	}
	virtual ~parent()
	{
		cout << "in parent d'tor" << endl;
	}
	virtual void hello()
	{
		cout << "in parent hello" << endl;
	}
};

class child: public parent
{
public:
	int b;
	child()
	{
		cout << "in child c'tor" << endl;
	}
	~child()
	{
		cout << "in child d'tor" << endl;
	}
	void hello()
	{
		cout << "in child" << endl;
	}

};


int main()
{
	int i = 0;
	parent* ptr = new child;
	ptr->hello();
	delete ptr;
	return 0;
}