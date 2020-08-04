#include <iostream>
#include <string>
#include "../courseNamespace.h"

// namespace exceptionClasses
// {
// 	class NegativeNumber
// 	{
// 	public:
// 		NegativeNumber();
// 		NegativeNumber(string message);
// 		string getMessage();
// 	private:
// 		string message;
// 	};
// 		class DivideByZero{};

// }

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;
using namespace courseNamespace::exceptionClasses;

float divide(float n1, float n2);
float fixedDivide(float n1, float n2);

// double safeDivide(int top, int bottom) throw (DivideByZero);  // Wb-2.1

int main()
{
	print("Chapter 16: Exception Handling");
	print("Ch 16.1- Exception Handling Basics");

	print("Exception handling should only be used rarely only in advanced situations");
	// The examples in this chapter are much more simple than would need exception handling in the real world

	print("An example of error handling would be making sure that division by 0 doesn't happen");  // WB-1
	// cout << "Division " << divide(5, 2) << " " << divide(5, 0);
	cout << "Division " << fixedDivide(20, 2) <<  " " << fixedDivide(10, 0);
	// Dividing by 0 is not an error in g++ compiler, but it would return infinity (which would be an issue in code)

	print("\nTo error handle, you can put code in a try/catch code block");
	print("It can be used instead of regular if-else error handling");
	// (Just having if n2== 0 ){cout error and return 0}
	
	try
	{
		// Normal code
	}
	catch (int error)
	{
		// Code when error happens
	}

	print("\nThe code in the try statement is what should normally happen");
	// Its called a try block, because you aren't sure it will work right
	print("The code in the catch block is used for exceptions");

	try 
	{
		int number = 3;
		string s;

		if  (number == 5)
		{
			 s = "The number cant be 5";
			 throw s;
		}
		if (number == 3)
		{
			s =  "The number cant be 3";
			throw s;
			// The type of the exception can be anything
			// Good practice it should have thrown the int number
			// But used the string, just to test other data types
		}

	}
	catch (string error)
	{
		cout << endl << error;
	}

	print("\nException- name for the value that is thrown");
	// The exception in the example above is the string s
	print("Throwing an exception- name for a throw statement");
	print("\nWhen a value is thrown, it goes from one place to another");
	print("A throw statement throws the value AND  the control flow");
	print("When a throw statement is executed, C++ stops the try block and executes the catch block");
	print("This is catching/handling the exception");

	print("\nThrowing an exception is like calling a function");
	// Instead of calling a function, it runs a catch block

	print("\nException handler- another name for a catch block");
	print("Catch-block parameter- name for the parameter in the catch block");

	print("\nThe catch block parameter has 2 goals:");
	print("  The type name specifies what kind of value can be caught");
	// EX: In the division problem, you are checking if 2 floats can be divided by each other
	// The number that could cause an error if it is 0 (n2) is a float
	// This means that the value being thrown should be the float n2
	print("  Gives a name to the thrown value that is caught, so that you can write code that uses the value");
	// It can be useful to access whatever value caused an error
	// For example, if your program can only positive values, you can throw the erroneous value
	// In the catch block you can either make the value positive and retry the logic in the try statement
	// Or you could print out number can't be [value]

	print("\nThe main difference between a try-catch and if-else method of error handling is try-catch throws a value");	
	// In the real world, this difference can be very big, making a try-catch very useful

	print("\nIf no error is thrown in the try block, the catch block is skipped and the program continues after the try-catch");

	// SELF TEST START

		// 1. What output is produced by the following code?

		// int waitTime = 46;

		// try  
		// {  // ST-5
		// 	cout << "Try block entered.\n";
		// 	if (waitTime > 30)
		// 		throw waitTime;
		// 	cout << "Leaving try block.\n";
		// }  //  ST-5.1
		// catch(int thrownValue) 
		// { // ST-6
		// 	cout << "Exception thrown with\n"
		// 	<< "waitTime equal to " << thrownValue << endl;
		// }  // ST-6.1

		// cout << "After catch block." << endl;
		
		// // Try block entered
		// // Exception thrown with wait time equal to 46
		// // After catch block

		// 2. What would be the output produced by the code in Self-Test Exercise 1 if
		// we make the following change? Change the line
		// int waitTime = 46;
		// to
		// int waitTime = 12;

		// // Try block entered
		// // Leaving try block
		// // After catch block

		// 3. In the code given in Self-Test Exercise 1, what is the throw statement?
		// // if(wt > 30) {}

		// 4. What happens when a throw statement is executed? This is a general
		// question. Tell what happens in general, not simply what happens in the
		// code in Self-Test Question 1 or some other sample code.
		// // If a throw statement is executed, it redirects the flow from the try block to the catch statement
		// // It uses the variable thrown in the catch statement
		// // It then executes everything after the catch block like normal, avoiding the rest of the try statement code

		// 5. In the code given in Self-Test Exercise 1, what is the try block?
		// // ST-5

		// 6. In the code given in Self-Test Exercise 1, what is the catch block?
		// //ST-6

		// 7. In the code given in Self-Test Exercise 1, what is the catch -block parameter?
		// // thrownValue

	// SELF TEST END

	print("\nIt is possible to define a class to throw");
	print("The class should contain the information you want to be caught");
	print("These are generally called exception classes");
	// They are just regular classes, but they are defined to contain information for error handling
	// EX: throw NoMilk(donuts);
	// NoMilk is a class which takes an int and the constructor fills in the rest of the info

	print("\nAnother thing you can do is have multiple throw statements and catch blocks");
	print("Like overloading, each catch block can't use the same variable");
	// EX: You can't have 2 catch blocks that accept an int for the same try block
	print("Like returning, you can only throw and catch 1 variable");
	// If you need to throw multiple values, use an exception class

	try 
	{
		int number = 6;
		string s;

		if  (number == 5) // Triggers first catch
		{
			 s = "The number cant be 5";
			 throw s;
		}
		if (number == 3)  // Triggers first catch
		{
			s =  "The number cant be 3";
			throw s;
			
		}
		if (number < 0)  // Triggers second catch
		{
			throw number;
		}

		// if (true)  // Catch 3
		// {  // NOT ALLOWED, BECAUSE YOU CAN ONLY THROW 1 ITEM PER STATEMENT  
		// 	throw s, number;
		// }
	}
	catch (string error)
	{
		cout << endl << error;
	}
	catch (int error)
	{
		cout << "The number has to be positive ";
		cout << "\n" << error << " is not positive"; 
	}
	// catch(string errorString, int errorCode)
	// {
	// 	cout << "You should never use if(true) in an error message";
	// }
	// catch (string betterError)
	// {
	// 	cout << endl << "Better error: " << error;
	// }

	print("\nSince once 1 throw statement is run, the try block is left, you can only catch one thing");
	print("It is best to check for more specific errors first, then go to less specific errors");

	try 
	{
		if(true)
		{
			throw 0;
		}
	}
	catch(...)
	{
		print("catch(...) can be used as a default catch block");
		print("You still need to throw something though (could just be 0)");
		print("It should be after all other catch blocks");
		print("It only runs if no other catch block works");

	}
	using namespace exceptionClasses;
	try
	{
		int number = 5;
		if(number == 0)  // More specific
		{
			// throw DivideByZero(number);
		}

		if(number < 0)  // Less specific
		{
			// throw NegativeNumber(number);
		}
	}
	catch (DivideByZero e) // Specific
	{

	}
	catch (NegativeNumber e) // Less specific
	{

	}
	catch(...)  // Default
	{

	}
	// Its a lot easier to read with custom classes 
	// bc it says throw NegativeNumber instead of a generic int
	// Also if you only used primitive types,you cant have multiple catchs for the same type
	// ex: you couldnt have both db0 and nn errors throw an int

	// try  // NOT ALLOWED ANYMORE
	// {
	// 	safeDivide(4, 3);
	// }
	// catch(DivideByZero e)
	// {
	// 	cout << "Error: Division by zero!\n";
	// }
	print("\nAfter a function (in definition and declaration you can write throw ((exceptionClassName])");
	print("Then everytime you use it, have a catch block after it");
	print("This lets you define what happens if the error occursr each time you run the function");  
	// WB-2
	print("NOTE: DYNAMIC EXCEPTION SPECIFICATION NO LONGER WORKS AS OF C++11");

	print("\ndouble divide(int n1, int n2) throw(DivideByZero) is an exception specification");
	print("Throw list- Another name for the exception specification");
	print("Remember, no longer works");
}

// WB-1
float divide(float n1, float n2)
{
	return n1 / n2;
}
float fixedDivide(float n1, float n2)
{
	float number;
	try
	{
	 	if (n2 == 0)
	 	{
	 		throw n2;
	 	}

	 	number = n1 / n2;
	}
	catch (float e)
	{
		cout << "Division by 0 error";
		return 0.0;
	}
	return number;

}

// namespace exceptionClasses
// {
// 	NegativeNumber::NegativeNumber()
// 	{}

// 	NegativeNumber::NegativeNumber(string newMessage)
// 	: message(newMessage)
// 	{}

// 	string NegativeNumber::getMessage()
// 	{
// 		return message;
// 	}
// }


// double safeDivide(int top, int bottom) throw (DivideByZero)  // WB-2.2
// {
// 	if (bottom == 0)
// 	{
// 		throw DivideByZero();
// 	}

// 	return top/static_cast<double>(bottom);
// }