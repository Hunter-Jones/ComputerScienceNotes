#include <iostream>
#include <string>
#include "../courseNamespace.h"

using namespace courseNamespace;
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	print("---Chapter 15: Inheritance---");
	print("--Ch 15.2- Inheritance Details--\n");

	print("Some special functions are not inherited from the base class");
	print("  1. Deconstructors are one example");
	print("  2. Copy constructors also aren't inherited");
	print("  If you don't include one, C++ automatically gives you one");
	print("  But it doesn't work with pointers and dynamic data member variables");
	print("  3. The assignment operator (=) is not inherited");
	print("  If you do not define one in the derieved class, C++ will give you an auto one");
	print("  But it doesn't have anything to do with one defined in the base class");

	print("\n Overloaded assignment operator and constructors aren't inherited, but can all"
		" be copied");

	// Derived& Derived::operator =(const Derived& rightSide)
	// {
	// 	Base::operator =(rightSide);
	// }
	// Example of how to inherit the base operator

	// Derived::Derived(const Derived& object): Base(object), <probably more initializations>
	// {

	// }
	// Example of how to inherit the copy constructor
	// The parameter object can be of the derieved or base class
	// (Base you can substitute a derieved class for a base c;ass already)

	print("\nWhen the deconstructor for the derieved class is invoked, it automatically "
		"invokes the version for the base class");
	// This means you only have to delete new dynamic data when defining the deconstructor 
	// for the derieved class
	// It is the job of the base class to delete inherited member variables

	// SELF TEST

	// 7. You know that an overloaded assignment operator and a copy constructor
	// are not inherited. Does this mean that if you do not define an overloaded
	// assignment operator or a copy constructor for a derived class, then that
	// derived class will have no assignment operator and no copy constructor?

	// C++ Provides a default one
	// It wont work correctly if you have dynamic variables 
	// or want it to something besides what the default C++ assignment/copy constructor does

	// 8. Suppose Child is a class derived from the class Parent , and the class
	// Grandchild is a class derived from the class Child . This question is con-
	// cerned with the constructors and destructors for the three classes Parent ,
	// Child , and Grandchild . When a constructor for the class Grandchild is
	// invoked, what constructors are invoked and in what order? When the
	// destructor for the class Grandchild is invoked, what destructors are invoked
	// and in what order?

	// When constructors are invoked it goes grandparent, parent, child
	// When deconstructors are invoked it goes child, parent, grandparent
	
	// 9. Give the definitions for the member function addValue , the copy con-
	// structor, the overloaded assignment operator, and the destructor for the
	// following class. This class is intended to be a class for a partially filled
	// array. The member variable numberUsed contains the number of array
	// positions currently filled. The other constructor definition is given to help
	// you get started.

	// #include <iostream>
	// #include <cstdlib>

	// using namespace std;

	// class PartFilledArray
	// {
	// public:
	// 	PartFilledArray(int arraySize);
	// 	PartFilledArray(const PartFilledArray& object);
	// 	~PartFilledArray();
	// 	void operator =(const PartFilledArray& rightSide);
	// 	void addValue(double newEntry);
	// 	//There would probably be more member functions
	// 	//but they are irrelevant to this exercise.
	// protected:
	// 	double *a;
	// 	int maxNumber;
	// 	int numberUsed;
	// };

	// PartFilledArray::PartFilledArray(int arraySize): maxNumber(arraySize), numberUsed(0)
	// {
	// 	a = new double[maxNumber];
	// }

	// void PartFilledArray::addValue(double newEntry)
	// {
	// 	++numberUsed;
	// 	if(numberUsed >= maxNumber)
	// 	{
	// 		maxNumber *= 2;
	// 		double tempArr = new double[maxNumber];

	// 		for (int i = 0; i < numberUsed; ++i)
	// 		{
	// 			temp[i] = a[i];

	// 		}
	// 		a = temp;
	// 	}

	// 	a[numberUsed] = newEntry;
	// }

	// PartFilledArray::PartFilledArray(const PartFilledArray& object)
	// {
	// 	*a = *object.a;
	// 	maxNumber = object.maxNumber;
	// 	numberUsed = object.numberUsed;
	// }

	// PartFilledArray::~PartFilledArray();
	// {
	// 	delete[] a;
	// }
	// void PartFilledArray::operator= (PartFilledArray& rightSide)
	// {
	// 	*rightSide.a = a;
	// 	rightSide.maxNumber = maxNumber;
	// 	rightSide.numberUsed = numberUsed;
	// }

	// // (Many authorities would say that the member variables should be private
	// // rather than protected. We tend to agree. However, using protected makes
	// // for a better practice assignment, and you should have some experience
	// // with protected variables because some programmers do use them.)
	
	// // 10. Define a class called PartFilledArrayWMax that is a derived class of
	// // the class PartFilledArray . The class PartFilledArrayWMax has one
	// // additional member variable named maxValue that holds the maximum
	// // value stored in the array. Define a member accessor function named
	// // getMax that returns the maximum value stored in the array. Redefine the
	// // member function addValue and define two constructors, one of which
	// // has an int argument for the maximum number of entries in the array.
	// // Also define a copy constructor, an overloaded assignment operator, and
	// // a destructor. (A real class would have more member functions, but these
	// // will do for an exercise.)

	// class PartFilledArrayWMax : public PartFilledArray
	// {
	// public:
	// 	double getMax();
	// 	addValue
	// private:
	// 	double maxValue;
	// }

	// PartFilledArrayWMax::PartFilledArrayWMax(int arraySize): PartFilledArray(arraySize), maxNumber(arraySize), numberUsed(0)
	// {

	// }

	// PartFilledArrayWMax::PartFilledArrayWMax(const PartFilledArray& object): PartFilledArray(object)
	// {
	
	// }
	// PartFilledArrayWMax::~PartFilledArrayWMax()
	// {

	// }
	// void PartFilledArrayWMax::operator=(PartFilledArray& rightSide): PartFilledArray::operator=(rightSide)
	// {

	// }

	// double PartFilledArrayWMax::getMax() {return maxValue;}

	// void PartFilledArrayWMax::addValue(double newEntry)
	// {
	// 	maxValue = newEntry;
	// 	++numberUsed;
	// 	if(numberUsed >= maxNumber)
	// 	{
	// 		maxNumber *= 2;
	// 		double tempArr = new double[maxNumber];

	// 		for (int i = 0; i < numberUsed; ++i)
	// 		{
	// 			temp[i] = a[i];

	// 		}
	// 		a = temp;
	// 	}

	// 	a[numberUsed] = newEntry;
	// }

	// SELF TEST END
}