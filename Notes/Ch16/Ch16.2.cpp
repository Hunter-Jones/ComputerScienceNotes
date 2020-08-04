#include <iostream>
#include <string>
#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

int main(int argc, char const *argv[])
{
	print("Chapter 16: Exception Handling");
	print("Ch 16.2- Programming Techniques for Exception Handling\n");

	print("\nIn the real world, you should seperate throwing and catching errors to seperate functions");
	print("Every throw statement should be in a function definition and the catch in a seperate function");
	//WB-1
	// Outdated

	print("\nOnly throw when needed");
	print("Only throw when the way the exception is handled depends on how and where the function is");
	// (If you want to divert the flow of code)

	print("\nIf you throw an error but cant catch it, the program will terminate");

	print("\nYou can nest try-catch blocks");
	print("Normally, you should never actually do it");
	print("If there isn't a catch block for the inner try block, C++ will check if it can be "
		"caught in a catch block for the outter try block\n");

	// Before try-catch, programmers controlled flow with goto

	bool returned = false;
	goto SkipContent;

	print("Anything between here and skip content is skipped");
	print("So, hows it going?");
	print("Sad these lines will never be seen, right?");

	Returning:
	returned = true;
	print("Goto statements can make the flow of control extremely hard to read");

	print("\nNever use goto");
	print("You should also limit the amount of error handling you use");
	print("Using it too much can get confusing");
	goto SkipContent;

	SkipContent: print("Goto example");

	if (!returned) // prevents infinite loop
		goto Returning;

	print("\nIt might be a good idea to make an exception class hierarchy");
	print("For example, you can have the superclass ArithmeticError with the subclass DivideByZero error");


	print("\nRemember- if you define a dynamic variable with new and there isnt enough memory, it will crash");
	print("This is because C++ will give off a bad_alloc error");
	print("Because there isn't a catch block, it will end up crashing");

	{
		using namespace courseNamespace::nodes;
		try
		{
			NodePtr np = new Node;
		}
		catch(std::bad_alloc &error)
		{
			print("NO MORE MEMORY");
			cout << error.what();
		}
	}

	print("\n It is possible to throw an exception in a catch block");
	print("You can then decide to throw the same exception or a "
		"different exception further up the exception-handling chain");

	// SELF TEST

	// 10. What happens when an exception is never caught?

	// // Program terminates

	// 11. Can you nest a try block inside another try block?	

	// // Yes but dont, please 

	// SELF TEST END

	print("\n\nChapter Summary:");
	print("  Exception handling lets you create a normal case and a seperate case for errors");
	print("  An exception is thrown in a try block");
	print("  An exception is caught in a catch block");
	print("  A try block is followed by 1+ catch block, and the least specific catch blocks "
		"should be last, while the most specific catch blocks are first");
	print("  Your code will be confusing if you overuse exceptions");

	return 0;
}

// No longer works
// void functionA() throw (CustomException)  // WB-1
// {
// 	if (true)
// 	{
// 		throw exception;
// 	}
// }
// void functionB()
// {
// 	try 
// 	{
// 		functionA();
// 	}
// 	catch(CustomException error)
// 	{
			
// 	}
// }