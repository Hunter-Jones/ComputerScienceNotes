#include <iostream>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;

namespace
{
	void print(string str)
	{
		cout << str << "\n";
	}
}

void binarySearch(const int array[], int firstElement, int lastElement, int target, int& location);
// Pre: Requires an array of ints sorted incrementally 
// The first element in the array and the last element in the array
// The target, which is the int to look for
// And location, which is an int to place the location of target
// Post:Uses a binary search to set the int location equal to the location
// of the target or -1 if it doesnt appear 

//ST-15.0
int squares(int n);
//Precondition: n >= 1
//Returns the sum of the squares of numbers 1 through n.

int main()
{
	print("===Chapter 14===");
	print("--Thinking Recursively--\n\n");

	print("\n+Recursive Design Techniques+\n");
	
	// Be aware of stack usage when making recursive functions
	// Recursive functions are useful because it lets the computer worry 
	//about details

	print("\nWhen creating recursive functions, you should mentally trace"
		"the function calls");

	//CS-1
	print("\nConditions needed to be satisfied when tracing recursive funcs");
	   print("   Every function call leads to a stopping case");
	// No infinite recursion
	   print("   Each stopping case returns the correct value for the case");
	   print("   All recursion cases return the right value and "
	   	"the final value should be correct");

	print("\n+Case Study: Binary Search+\n");

	//WB-2
	print("\nOnly on some systems is binary search faster itteratively than recursively");
	print("Sometimes you should make a recursive version of an algorithm, even if you plan to convert to itterative");

	print("\n+Programming Example+\n");

	print("\nMember functions can be recursive");

	// WB-1 demonstrates a member function of a bank class that is recursive
	// It also shows overloading used effectively with recursive programming
		// Kind of a bad example, because update() is only a one line program
	print("\nOverloading creates 2 functions with the same name");
	print("Calling the other overloaded function within the original is NOT overloading");
	// Calling update() in update(int year) is not recursion
	// Calling update(int year) in update(int year) is overloading


	// SELF TEST
	// 15. Write a recursive function definition for the following function:
	// int squares(int n);
	// //Precondition: n >= 1
	// //Returns the sum of the squares of numbers 1 through n.
	// For example, squares(3 ) returns 14 because 1 2 + 2 2 + 3 2 is 14.
	
	//ST-15
	cout << squares(5); 

	// 16. Write an iterative version of the one-argument member function Bank-
	// Account::update(int years) that is described in Display 14.9.

	// ST-16

	print("\n+Chapter Summary+");	

	print("   If a problem can be broken to smaller versions of same "
		"problem, recursive solutions can work");
	print("   Recursion has 1+ stopping cases (no recursion) "
		"and 1+ recursive cases");
	print("   Always make sure recursive function can't go on forever");
	print("   Use 3 recursive function tracing techniques to make sure"
		"the function works");
	// CS-1
	print("   Like in binary search, the smaller problem each run might not"
		"be the same as the larger task being solved");
}

// WB-2
void binarySearch(const int array[], int firstElement, int lastElement, int target, int& location)
{
	int mid;

	if (firstElement > lastElement)
	{
		location = -1;
	}
	else
	{
		mid = (firstElement + lastElement)/2;
	}

	if (target == array[mid])
	{
		location = mid;
	}
	else if (target < array[mid])
	{
		binarySearch(array, firstElement, mid -1, target, location);
	}
	else if (target > array[mid])
	{
		binarySearch(array, mid + 1, lastElement, target, location);
	}
}

// WB-1
// void BankAccount::update()
// {
// 	balance = balance + fraction(interestRate)*balance;
// }

// void BankAccount::update(int years)
// {
// 	if (years == 1)
// 	{
// 		update();
// 	}
// 	else if (years > 1)
// 	{
// 		update(years - 1);  // Recursion
// 		update();  			// Not recursion
// 	}
// }

// ST-16
// void BankAccount::update(int years)
// {
// 	for (int i = year; i < 0; --i)
// 	{
// 		balance = balance + fraction(interestRate)*balance;
// 	}
// }

// ST-15.1
int squares(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else 
	{
		
		return n*n + squares(n - 1);
	}
}