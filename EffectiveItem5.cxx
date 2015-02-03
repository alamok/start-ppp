#include <iostream>
#include <sstream>
using namespace std;


// A compiler sliently adds four things to a program if we dont define them
// Default Constructor, copy constructor, assignment operator, default destructor
// Everything is non virtual in nature
// But if you declared a constructor in a class, compiler won't do anyting.
// The behaviour also changes if you have const/ref/constref datament

// A class with no const/ref/constref data member.
template<typename T>
class NamedObject
{
public:
NamedObject(const char *name, const T& value)
{
	nameValue = name; // std::string has a constructor with char* as parameter
	objectValue = value;
}
NamedObject(const std::string& name, const T& value)
{
	nameValue = name;
	objectValue = value;
}
private:
std::string nameValue;
T objectValue;
};

// A class with const/ref/constref data member.
template<typename T>
class NamedObjectWithRef
{
public:
	NamedObjectWithRef( std::string& name, const T& value) : nameValue( name ), objectValue( value ) {}// ctor with initializer list wont do.
private:
std::string & nameValue;
T objectValue;
};

int main()
{
	NamedObject<int> no1("Smallest Prime Number", 2);
	NamedObject<int> no2(no1);
	// copy constructor called which in trun calls the copy constructor of
	// std::string with no1.nameValue as param which is absolutely fine.

	std::string newDog("Persephone");
    std::string oldDog("Satch");

	// Independent point to note
	// If you have a const/ref/constref datatype in your class and you dont use
	// initializer list compiler won't complain until unless you create a object
	// of that class.

	NamedObjectWithRef<int> p(newDog, 2);
	NamedObjectWithRef<int> q(oldDog, 32);

	// uncomment this line of code will give you compile errors
	// If you have const/ref/constref datatype in your class automatic copy constructors are not generated.
	//p = q;
	return 0;
}