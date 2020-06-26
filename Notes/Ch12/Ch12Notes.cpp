#include <iostream>
#include <string>

#include "Ch12DayOfYear.h"  // WB-1

using std::endl;
using std::cin;
using std::cout;
using std::string;

void  seperateCompilation();
void namespaces();
namespace easyCode  // WB-2
{
	void print(string str)
	{
		cout << str << endl;
	}
}

using namespace easyCode; // WB-2.1


namespace  //WB-3
{
	int digitToInt()
	{

	}
}


int main()
{
	print("---Chapter 12: Seperate Compilation and Namespace---\n");
	seperateCompilation();
	namespaces();
}

void seperateCompilation()
{
	print("--12.1- Seperate Compilation--\n\n");

	print("C++ allows you to break a program into multiple files then link them together when you run the program");
	print("You can compile a clas once, and then use it in many programs");
	print("It is also possible to define a class in 2 files");

	print("\nThe goal is to make classes ADTs, so it should:");
	print("Make all member variables private");
	print("(Interface)Make each basic operation of the class a public member function, a friend function, an ordianry function, or an overloaded operator");
	print("The interface should be properly commented");
	print("(Implementation)Function definitions and overloaded operators (+helpers) which are basic operations should be private (Stuff other programmers don't need to know");

	print("\nIt is a good idea to have seperate files for the interface and implementation");
	print("This helps you follow ADT guidelines");
	print("Implementation file/Interface file- file for each specific part of the class");
	print("With this, you put all private members in the inplementation and all public members in the interface");

	print("\nC++ Will not let you split the class definition into 2 files");
	print("Remember the class definition is the top part which creates each function, but doesn't include the actual code");
	print("YOU SHOULD PUT THE ENTIRE CLASS DEFINITION IN THE INTERFACE FILE");
	print("The reason for this is that the user doesn't need to see the definition nor do they need to see the implementation");

	print("\nTo include an interface file, use #include \"FILENAME.h\"");  // WB-1
	print(".h filetype is used to denote a header file");
	
	print("\nC++ Standards says that Interface and implementation files should have the same name");
	print("The difference is the file type");
	print("Interface should  be a header file (.h) while  the implementation should be a cpp file");

	print("\nApplication/ Driver File- The actual program, not the ADT class");
	print("Both the Driver file and the implementation file need the #include \"file.h\"");

	print("\nRules for implementation file: (.cpp)");
	print("     Has a comment at top explaining what class it is for and what the interface file is name");
	print("     Has all include statements for anything header file or library it needs to run");
	print("     (Including an include statement for the interface file");
	print("     Has the functions for all of the private member functions");

	print("\nRules for interface file: (.cpp)");
	print("     Has a comment at top explaining what class it is for, how the class is called/what each value does");
	print("     Has all include statements for anything header file or library it needs to run");
	print("     Has the functions for all of the public member functions");

	print("\nRules for the header file: (.h)");
	print("     Includes a prototype for the class");

	print("\nLinker- both files need a linker to allow them to work together");
	print("Otherwise it will give errors when the implementation accesses private members from the interface");
	print("The process for linking differs between systems (same as the file ending for the implementation file)");

	print("\nCh12DayOfYear.h and Ch12DayOfYear.cpp can be used as examples of how to use seperate files");

	print("\nWhy use seperate files:");
	print("     You can avoid copying and pasting classes between programs that you want to use the same class");
	print("     You can easily change interface or implementation without modifying the other");

	print("\nYou can use hpp instead of h for the interface, which is better because it denotes it is for C++ code");
	print(".h was originally used in C");
	print("Some programmers also put implementation in the hpp file (mainly for working with templates");

	//  Print How to link in g++ (shitty way):
	// g++ -c Ch12DayOfYear.cpp -o Ch12DayOfYear.o
	// g++ -c Ch12Notes.cpp -o Ch12Notes.o
	// g++ Ch12DayOfYear.o Ch12Notes.o -o Ch12Notes

	// This will compile both files (longer way)

	// To just complile the main file use

	DayOfYear birthday(9, 15);
	cout << "\nTest to make sure it works (should be 15): " << birthday.getDay() << endl;

	print("\nIMPORTANT LINKER NOTES FOR WHEN COMPILING:");
	print("Simple method to link: g++ Ch12DayOfYear.cpp Ch12Notes.cpp -o Ch12Notes");
	print("Generic version copied from SO: g++ class.cpp main.cpp -o class");
	// Also make sure to include the .h interface in the main file
	// g++ Ch12DayOfYear.cpp Ch12Notes.cpp -o Ch12Notes

	print("\nIn the example I used, 1 header file (interface) and a file for interface and implementation");
	print("It is possible to have a header file, a cpp file for the implementation, and a cpp file for the interface");

	print("\nC++ doesn't allow you to define a class more than once");
	print("This can be an issue of accidentally happening when you use many classes with many files");
	print("An example can be seen in Ch12DayOfYear.h");

	// Sometimes instead of ifndef, #pragma once   is used
	// It makes the source file only be included once
	// It is not standard in most C++ compilers

	// ---SELF TEST START---
	// 1. Suppose that you are defining an ADT class and that you then use this class
	// in a program. You want to separate the class and program parts into separate
	// files as described in this chapter. Specify whether each of the following
	// should be placed in the interface file, implementation file, or application file:
	// a. The class definition
		// Interface header file
	// b. The declaration for a function that is to serve as an ADT operation, but
	// that is neither a member nor a friend of the class
		// Interface
	// c. The declaration for an overloaded operator that is to serve as an ADT
	// operation, but that is neither a member nor a friend of the class
		// Interface
	// d. The definition for a function that is to serve as an ADT operation, but
	// that is neither a member nor a friend of the class\
		Implementation
	// e. The definition for a friend function that is to serve as an ADT operation
		// Implementation
	// f. The definition for a member function
		// Implementation
	// g. The definition for an overloaded operator that is to serve as an ADT
	// operation, but that is neither a member nor a friend of the class
		// Implementation
	// h. The definition for an overloaded operator that is to serve as an ADT
	// operation and that is a friend of the class
		// Implementation
	// i. The main part of your program
		// Main

	// 2. Which of the following files has a name that ends in .h : the interface file
	// for a class, the implementation file for the class, or the application file that
	// uses the class?
		// Interface
	// 3. When you define a class in separate files, there is an interface file and an
	// implementation file. Which of these files needs to be compiled? (Both?
	// Neither? Only one? If so, which one?)
		// Implementation
		// Header file needs no compilator
	// 4. Suppose you define a class in separate files and use the class in a program.
	// Now suppose you change the class implementation file. Which of the
	// following files, if any, need to be recompiled: the interface file, the
	// implementation file, or the application file?
		// Implementation file
	// 5. Suppose you want to change the implementation of the class DigitalTime
	// given in Displays 12.1 and 12.2. Specifically, you want to change the way
	// the time is recorded. Instead of using the two private variables hour and
	// minute , you want to use a single (private) int variable, which will be
	// called minutes . In this new implementation, the private variable minutes
	// will record the time as the number of minutes since the time 0:00 (that
	// is, since midnight). So 1:30 is recorded as 90 minutes, since it is 90
	// minutes past midnight. Describe how you need to change the interface
	// and implementation files shown in Displays 12.1 and 12.2. You need not
	// write out the files in their entirety; just indicate what items you need to
	// change and how, in a very general way, you would change them.
		//Too much work
	// 6. What is the difference between an ADT you define in C++ and a class you
	// define in C++?
		// ADT has operations and is documented in a way for a programmer to understand with good practices
}

void namespaces()
{
	print("\n\n--12.1- Seperate Compilation--\n\n");

	print("Namespaces are used to prevent issues where programmers use the same name for different things");
	// Happens on big projects where there are multipl programmers

	print("\nSTD is the namespace used by beginning programmers");
	print("The standard library includes names for everything declared in standard library");
	print("Without using std namespace, you can assign anything (ex cin) to work however you want");
	print("Basically unless you have a using cin, your code wont know the precreated version of cin allowing you to make your own");

	print("\nAll code is in some namespace");
	print("Global namespace- Any code not placed in a specific namespace");
	print("Basically everything written until now has been in global namespace");

	print("You can use more than one namespace at one timem");
	print("You are always using global namespace, so when you use std, you are using global and std namespaces");

	// {
	// 	using namespace ns1;
	// 	func();
	// }
	// {
	// 	using namespace ns2;
	// 	func();
	// }
	// Remember { } denote that area has its own nested scope
	print("\nUsing is only effective within it's own scope");
	print("This means you can use blocks {} or have different namespaces for each function");
	print("Using should be put at the start of a file (to affect everything) or the start of the block (to affect a specific block)");

	print("\nYou can do namespace myNamespaceName{} and within the block define any functions you want in your own namespace");
		// Example WB-2.1

	// namespace testNamespace; 
	// {
	// 	function testFunc() {}

	// }
	// Only possible in global scope

	print("\nMultiple namespaces can use the keywork ex cin) names, but they both cant be used in the same scope");
	// ((ex you cant use std and another namespace that uses cin)

	// ---SELF TEST START---
	// 9. Can a namespace have more than one namespace grouping

	// No
	// ---SELF TEST END--- (Good work everybody)

	print("\nIf you just want to use parts of a namespace, just type using NAMESPACE_NAME::FUNCTION_NAME");
	print("EX: using nsl::func1");

	print("\nUsing Declaration- Whenever you use the using keyword");
	// using namespace std and using std::cout are both considered using delcarations

	// The :: in using is the scope recognition operator
	// Remember, they were also usedfor CLASS_NAME::FUNCTION_NAME when writing member functions

	print("\nWhen adding an entire namespace with using directives, it only adds if the name doesn't already exist");

	//using namespace ns1;
	//using namespace ns2;
	// If both of these contain myFunction(), then this will cause no errors
	// C++ adds the myFunction from ns1, but doesnt include the myFuncttion from ns2

	// using ns1::myFunction;
	// using ns2::myFunction;
	// This will cause an error beccause it tries to add myFunction() from both

	// ---SELF TEST START---

	// 10. Write the function declaration for a void function named wow . The
	// function wow has two parameters, the first of type speed as defined in
	// the speedway namespace and the second of type speed as defined in the
	// indy500 namespace.

	// void wow(speedway::speed speed1, indy500::speed speed2);

	// 11. Consider the following function declarations from the definition of the
	// class Money in Display 11.4.
	// void input(istream& ins);
	// void output(ostream& outs) const;
	// Rewrite these function declarations so that they do not need to be pre-
	// ceded by
	// using namespace std;

	//	// void input(std::istream& ins);
	// void output(std::ostream& outs) const;

	// ---SELF TEST END---

	print("\nCompilation Unit- Any file and all the files that are included with #include");
	// EX: The class implementation file

	print("\nUnnamed namespace- Namespace written like any other, but no name is given");
	print("Every Compilation unit has one");
	print("Everything defined in an unnamed namespace is local to the compilation unit");

	print("\nWhen creating classes, helper functions cause a problem");
	print("They are in the implementation, but can be used inside the main code");
	print("This defeats the point of abstraction");
	// Also can cause a problem if you want to create a function called digetToInt
	// Which is already defined in the ADT, but can only be logically used as a helper function that the user cant use
	print("Unnamed namespaces can be used to hide them from everywhere but the implementation");
	// Will allow you to use your own function called digitToInt in your main code
	// You can have an unlimited amount of unnamed namespace groupings
	//WB-3
	print("Good to put unnamed namespace with all helper functions in the header interface file");
	print("Good to have another namespace for other stuff in the class");

	print("\nIt is a good idea when working with multiple programmers to have your namespaces include your own name");
	print("This is to avoid multiple programmers using the same namespace name");

	print("\nIt is possible for a file to be in multiple compilation units");
	print("The header file is in the implementation and main code compilation unit");

	print("\nGlobal namespace vs unnamed namespace");
	print("     Both can be accessed without qualifiers");
	print("     Names in global scope have global scope");
	print("     Names in unnamed namespace can ONLY be used in the compilation unit");
		// Basically just useful when you dont wont them being used by other files

	// ---SELF TEST START---

	// 12. Would the program in Display 12.8 behave any differently if you replaced
	// the using directive
	// using namespace dtimesavitch;
	// with the following using declaration?
	// using dtimesavitch::DigitalTime;

	// Because DigitalTime DigitalTime included everything needed, it will behave the same


	// 13. What is the output produced by the following program?
	
	// #include <iostream>
	// using namespace std;
	
	// namespace sally
	// {
	// 	void message( );
	// }

	// namespace
	// {
	// 	void message( );
	// }

	// int main( )
	// {
	// 	{
	// 		message( );
	// 	}

	// 	{
	//		using sally::message;
	// 		message( );
	// 	}

	// 	message( );
	// 	return 0;
	// } 

	// namespace sally
	// {
	// 	void message( )
	// 	{
	// 		cout << "Hello from Sally.\n";
	// 	}
	// } 

	// Unnamed sally unnamed
	// Even though

	// namespace
	// {
	// 	void message( )
	// 	{
	// 		cout << "Hello from unnamed.\n";
	// 	}
	// }

	// 14. In Display 12.7 there are two groupings for the unnamed namespace: one
	// for the helping function declarations and one for the helping function
	// definitions. Can we eliminate the grouping for the helping function
	// declarations? If so, how can we do it?

	// namespace
	// {
	// 	//These function declarations are for use in the definition of
	// 	//the overloaded input operator >>:
	// 	void readHour(istream& ins, int& theHour);
	// 	//Precondition: Next input in the stream ins is a time in 24-hour notation,
	// 	//like 9:45 or 14:45.
	// 	//Postcondition: theHour has been set to the hour part of the time.
	// 	//The colon has been discarded and the next input to be read is the minute.
	// 	void readMinute(istream& ins, int& theMinute);
	// 	//Reads the minute from the stream ins after readHour has read the hour.
	// 	int digitToInt(char c);
	// 	//Precondition: c is one of the digits '0' through '9'.
	// 	//Returns the integer for the digit; for example, digitToInt('3')
	// 	//returns 3.
	// }//unnamed namespace

	// namespace dtimesavitch
	// {
	// 	bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
	// 	{
	// 		// Assume there is code in any blank { }
	// 	}
	// 	DigitalTime::DigitalTime( )
	// 	{

	// 	}
	// 	DigitalTime::DigitalTime(int theHour, int theMinute)
	// 	{

	// 	}
	// 	void DigitalTime::advance(int minutesAdded)
	// 	{

	// 	}
	// 	void DigitalTime::advance(int hoursAdded, int minutesAdded)
	// 	{

	// 	}
	// 	ostream& operator <<(ostream& outs, const DigitalTime& theObject)
	// 	{

	// 	}
	// 	//Uses iostream and functions in the unnamed namespace:
	// 	istream& operator >>(istream& ins, DigitalTime& theObject)
	// 	{
	// 		readHour(ins, theObject.hour);
	// 		readMinute(ins, theObject.minute);
	// 		return ins;
	// 	}
	// } //dtimesavitch

	// namespace
	// {
	// 	int digitToInt(char c)
	// 	{

	// 	}
	// 	void readMinute(istream& ins, int& theMinute)
	// 	{

	// 	}
	// 	void readHour(istream& ins, int& theHour)
	// 	{

	// 	}
	// }//unnamed namespace

	// No it is optional, but seperating the prototype and the decalration makes it look neat

	print("ST-14 has an example of a proper implementation file");

	// ---SELF TEST END---

	print("For use:");
	print("     int max(int a, int b); function declaration/prototype");
	print("     int max)int, int); function definition/prototype");
	// Both methods are the same
		// The first method forces you to use the same name in the function declation
		// This is good because it makes overloading easier and helps prevent mistakes
		// The second method is good because it allows you to choose the paramter names later
	print("    int max(int a, int b){/*code*/} function declaration");
		// The function itself
		// Includes all the code

	// IMP

}
bool before(){}
// If there wasnt an unnamed namespace, this would cause an error