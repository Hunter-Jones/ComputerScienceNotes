#include <iostream>
#include <string>
#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

// WB-1
template<class T>
class Pair
{
public:
	Pair() {};
	Pair(T v1, T v2);
	T getElement(int position) {if (position == 1){return firstElement;} if (position==2){return secondElement;}};
	void setElements(T v1, T v2){firstElement = v1; secondElement = v2;}
private:
	T firstElement;
	T secondElement;
};

//ST-9
template<class T1, class T2>
class HeterogeneousPair
{
public:
	HeterogeneousPair() {};
	HeterogeneousPair(T1 v1, T2 v2);
	T1 getFirstElement(int position) {return firstElement;};
	T2 getSecondElement(int position) {return secondElement;};
	void setElements(T1 v1, T2 v2){firstElement = v1; secondElement = v2;}
	void setFirstElement(T1 v1){firstElement = v1;}
	void setSecondElement(T2 v1){secondElement = v1;}
private:
	T1 firstElement;
	T2 secondElement;
};

int main(int argc, char const *argv[])
{
	print("Chapter 17: Templates");
	print("Ch 17.3 Templates for Abstraction\n");

	print("\nFor ", "template<class T> ", "T is just like any other type ");
	print("Templates can also be used for classes!");

	Pair<string> letters;
	Pair<int> numbers;
	Pair<char> characters('a', 'b');
	characters.setElements('c', 'd');
	print("\nIt acts just like a regular class now: ", characters.getElement(1));

	// Pair doubles;  // NOT ALLOWED
	// Pair doubles(1.4, 1.2);
	print("\nWhen you make template classes the syntax to instantiate one is ",
		"ClassName<templateVariableType> ", "optionally you can have (parameters) after");
	// Template classes use same syntax as template functions
	print("The <> is mandatory");
	print("The syntax for defining member functions is a little different");
	// WB-1.1 for example

	print("\nYou can create template member functions in template functions");
	
	print("\nFriend functions are often used with template classes");
	print("When defining templates in multiple files, put the friend function with");

	// SELF TEST START

	// 7. Give the definition for the member function getElement for the class
	// template Pair discussed in the section “Syntax for Class Templates.”

	// 8. Give the definition for the constructor with zero arguments for the class
	// template Pair discussed in the section “Syntax for Class Templates.”

	// 9. Give the definition of a template class called HeterogeneousPair that
	// is like the class template Pair discussed in the section “Syntax for Class
	// Templates,” except that with HeterogeneousPair the first and second
	// positions may store values of different types. Use two type parameters
	// T1 and T2 ; all items in the first position will be of type T1 , and all items
	// in the second position will be of type T2 . The single mutator function
	// setElement in the template class Pair should be replaced by two
	// mutator functions called setFirst and setSecond in the template class
	// HeterogeneousPair . Similarly, the single accessor function getElement
	// in the template class Pair should be replaced by two accessor functions
	// called getFirst and getSecond in the template class HeterogeneousPair .
	// //ST-9
	// 10. Is the following true or false?
	// True
	// SELF TEST END

	print("Chapter Summary:");
	print("  Template functions can be created to use any parameter type");
	print("  Template classes allows you to define a class with any parameter "
		"for subparts of the class");
	return 0;
}

// WB-1.1
template<class T>
Pair<T>::Pair(T v1, T v2) : firstElement(v1), secondElement(v2) 
{  // Difference is requires template<class T> and has <T> before ::

}

//ST-9.1
template<class T1, class T2>
HeterogeneousPair<T1, T2>::HeterogeneousPair(T1 v1, T2 v2) : firstElement(v1), secondElement(v2) 
{  // Difference is requires template<class T> and has <T> before ::

}