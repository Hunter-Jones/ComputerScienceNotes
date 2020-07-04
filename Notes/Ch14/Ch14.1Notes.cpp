#include <iostream>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::to_string;
using std::stoi;

//WB-1.11
// Pre: Requires a number
// Post: Returns the number of digits in the number
int countDigits(int number);

//WB-1.21
// Pre: Requires a number
// Post: couts the number 1 digit per line
void writeVertically(int number);

//ST-2.1;
// Pre: Requires a number greater than 0
// Couts number amount of astericks
void writeAsteriks(int number);

//ST-3.1
// Pre: Requires a number
// Post: Couts it in reverse
void writeReverse(int number);

// ST-4.1
// Pre requires a number greater than 0
// Post: Writes out  each number until it reaches it incramenting by 1
void writeCount(int number);

//ST-5.1
// Pre requires a positive number
// Post: same as 4.1 but in reverse
void writeCountReverse(int number);

namespace
{
	void print(string str)
	{
		cout << str << "\n";
	}
}

int main()
{
	print("+++Chapter 14+++");

	print("\n--Recursice Functions For Tasks--\n\n");

	// Sometimes when breaking a task into small subtasks, 
	// the subtasks are small versions of the main task
	// Ex: When searching an array:
	// 1st subtask is searching the  1st half of the array
	// the 2nd is the second half
	// Both of these are small version of a main task (searching an array)

	print("Recursion- a function which calls itself");

	// Recursion examples WB-1.1 and WB-1.2
	cout << "\nCount Digits: " <<  countDigits(2434344344);
	// cout << "\nwrite Vertically:\n";
	// writeVertically(534);

	// When a function recursively calls itself, it halts the original (outter) call to compute the new recursive call
	// (FILO style)
	
	print("\nRecursice programs must eventually terminate");
	print("This is generally done with an if-else call where "
		"1 branch stops creating new recursive calls");
	print("Base/stopping case- case in function which has no recursive calls");
	// C++ does not limit the amount of recursion allowed
	print("If the program never reaches a stopping case, it will stop abnormally");
	// Some languages it will go on forever, but C++ forcefully stops it

	print("\nOne way to ensure recursion ends is to have a"
		"positive number get smaller each run until it reaches 0");
	print("Once it reaches 0, the recursion ends");
	// In both WB-1.1 and WB-1.2 they had number which is divided by 10 each run

	print("In a good recursion function, each call should solve a smaller"
		"version of the main task");

	// Ex: WB-1.23
	print("Infinite recursion- when every recursion call creates another recursion call");

	// ---SELF TEST START---

	// 1. What is the output of the following program?

	// #include <iostream>
	// using namespace std;

	// void cheers(int n);

	// int main()
	// {
		// cheers(3);
		// return 0;
	// }

	// void cheers(int n)
	// {
		// if (n == 1)
		// {
			// cout << "Hurray\n";
		// }
		// else
		// {
			// cout << "Hip ";
			// cheers(n − 1);
		// }
	// }

	// Hip Hip Hurray
	//

	// 2. Write a recursive void function that has one parameter which is a positive
	// integer and that writes out that number of asterisks '*' to the screen all
	// on one line.

	// writeAsteriks(5);

	// 3. Write a recursive void function that has one parameter, which is a positive
	// integer. When called, the function writes its argument to the screen
	// backward. That is, if the argument is 1234 , it outputs the following to the
	// screen:
	// 4321

	// writeReverse(1234);

	// 4. Write a recursive void function that takes a single int argument n and
	// writes the integers 1, 2, ..., n .

	// writeCount(10);

	// 5. Write a recursive void function that takes a single int argument n and
	// writes integers n, n–1, ..., 3, 2, 1 . (Hint: Notice that you can get
	// from the code for Self-Test Exercise 4 to that for Self-Test Exercise 5, or vice
	// versa, by an exchange of as little as two lines.)

	// writeCountReverse(10);

	//---END SELF TEST---

	print("\nStack- memory structure like a stack of paper");
	// It has an unlimited amount of blank sheets
	// To place information on a stack it is written on a new piece and placed on the top
	// You can keep putting new pieces of paper on the stack making it bigger
	// The top piece of paper can be read and thrown away to access the piece below
	// (FILO)
	print("\nC++ uses a stack to keep track of recursion");
	print("It writes information to the stack each recursive function call");
	print("It stops writing to the stack when there are no more recursive calls");

	print("After the function ends, it is discarded when done");
	print("It discards until the bottom 'sheet' is discarded");
	// Works in FILO fashion
	print("Because how recursion works, it continuously adds a 'sheet' to the stack until it reaches a stopping case");

	print("\nActivation frame- content of each stack node");
	// (What is on each piece of paper added to the stack)
	print("Activation frames don't contain a complete function, but a reference to a copy of a function");
	
	print("\nStack Overflow- When you try to exceed the stack size");
	// The stack is finite
	// If you have infinite recursion, it will most likely give a stack overflow error

	print("Iterative Version- nonrecursive way of solving a problem");
	// Any problem that can be solved recursively can also be solved itteratively
	// Ex: ST-4.2 is the recursive and ST-4.3 is the itterative
	// In this example, the itterative is much more efficient, takes less code, and is easier to understand
	// EX: WB-1.23 the recursive solution is much simpler, but not as efficient
	print("Iterative versions generally use a loop");
	print("-Recursive functions usually are less efficient and use more storage-");
	print("This is because stack manipulation takes a lot of computing power");
	// Even if it is less efficient, in problems like the writeVertical one, it is easier to understand
	// It also is easier to write, and can be worth the tradeoff

	// Not all languages even allow recursion

	// ---SELF TEST START

	// 6. If your program produces an error message that says stack overflow,
	// what is a likely source of the error?

	// The stack has too many 'sheets' added from too many function calls within function calls
	// It most likely is from an infinite recursion

	// 7. Write an iterative version of the function cheers defined in Self-Test
	// Exercise 1.

	// void cheers(int n)
	// {
			// if (n < 1)
			// {
			// 	return;
			// }
			// for (int i = 1; i < n; --i)
			// {
			// 	cout << "Hip ";
			// }
			// if (n >= 1)
			// {
			// 	cout << "Hooray!";
			// }
	// }

	// 8. Write an iterative version of the function defined in Self-Test Exercise 2.
		
	// ST-2.3	

	// 9. Write an iterative version of the function defined in Self-Test Exercise 3.
	
	//St-3.3

	// 10. Trace the recursive solution you made to Self-Test Exercise 4.
	
	// ST-4.4
	// writeCount(10);

	// 11. Trace the recursive solution you made to Self-Test Exercise 5.
	
	//ST-5.3
	// writeCountReverse(10);
}	

//WB-1.12
int countDigits(int number)
{
	// Edge case for 0
	if (number == 0)
	{
		return 0;
	}

	// Ex 345
	// 345 != 0 so count 1 + 345/10 (34) runs
	// 34 != 0 so count 1 + 34/10 (3) runs
	// 3 != 0 so count 1 + 3/10 (0) runs
	// 0 == 0 so it returns 0 to count(3)
	// count(3) returns 1 + 0 (1)
	// count(34) returns 1 + 1 (2) 
	// count(345) returns 1 + (1 + 1) (3)
	// the program returns 3
	return 1 + countDigits(number / 10);
}

//WB-1.22
void writeVertically(int number)
{
	if (number / 10 == 0)
	{
		cout << number << endl;
	}
	else 
	{
		writeVertically(number / 10);
		cout << (number % 10) << endl;
	}

	// Ex: 345
	// 345 / 10 != 0, so it calls writeVertically 345 / 10 (34)
	// 34 / 10 != 0 so it calls writeVertically  34 / 10 (3)
	// 3 / 10 == 0 so it finishes and prints 3
	// It returns to the 34 / 10 writeVertically and prints 34 % 10 (4)
	// It returns to the original 345 / 10 and prints 345 / 10 (5)
}

//WB-1.23
// void writeVertically(int number)
// {
// 		writeVertical(number / 10);
// 		cout << (number % 10) << endl;
//
//	// There is no stopping case, which would cause this to go on forever
//	// Even once number = 0, it will still keep going
// }

// WB-1.24
// void writeVertical(int number)
// {
// 	int tensInN = 1;
// 	int leftEndPiece = number;

// 	while (leftEndPiece> 9)
// 	{
// 		leftEndPiece = leftEndPiece/10;
// 		tensInN = tensInN * 10;
// 	}
// 	//tensInN is a power of ten that has the same number
// 	//of digits as n. For example, if n is 2345, then
// 	//tensInN is 1000.
// 	for (int powerOf10 = tensInN; powerOf10 > 0; powerOf10 = powerOf10/10)
// 	{
// 		cout << (n/powerOf10) <<endl;
// 		number = number % powerOf10;
// 	}
// }

// ST-2.2
void writeAsteriks(int number)
{
	if (number <= 0)
	{
		return;
	}
	else 
	{
		writeAsteriks(--number);
		cout << '*';
	}
	
}

// //ST-2.3
// void writeAsteriks(int number)
// {
// 	for (int i = 0; i < number; ++i)
// 	{
// 		cout "*";
// 	}	
// }

//St-3.2
void writeReverse(int number)
{
	if (number / 10 == 0)
	{
		cout << number;
	}
	else
	{
		cout << number % 10;
		writeReverse(number / 10);
	}
}

// //ST-3.3
// void writeReverse(int number)
// {
// 	for (int i = number; i < 0; --i)
// 	{
// 		cout << i << " ";
// 	}
// }

//ST-4.2
// void writeCount(int number)
// {
// 	if (number < 1)
// 	{
// 		return;
// 	}
// 	else
// 	{
// 		writeCount(number - 1);
// 		// --number will skip when n = n
// 		// ex if n goes to 5 it would do 1 2 3 4
// 		cout << number << " " ;
// 	}
// }

//ST-4.4
// Same as 4.2, but with tracing when running
void writeCount(int number)
{
	if (number < 1)
	{
		print("Return");
		return;
	}
	else
	{
		cout << "Run writeCount with " << number << " - 1\n";
		writeCount(number - 1);
		cout << "writeCount with " << number << " - 1 ended\n";
		// --number will skip when n = n
		// ex if n goes to 5 it would do 1 2 3 4

		cout << "Prints result ";
		cout << number << "\n";
	}
}

// ST-4.3
// void writeCount(int number)
// {
// 	for (int i = 1; i <= number; ++i)
// 	{
// 		cout << i << " ";
// 	}
// }

// ST-5.2
// void writeCountReverse(int number)
// {
// 	if (number < 1)
// 	{
// 		return;
// 	}
// 	else
// 	{
// 		cout << number << " " ;
// 		writeCountReverse(number - 1);

// 		// swapping the 2 lines causes it to go reverse
// 		// because 1 prints before calculating and the other does the reverse
// 	}
// }

// ST-5.3
void writeCountReverse(int number)
{
	if (number < 1)
	{
		print("Return");
		return;
	}
	else
	{
		cout << "Prints result ";
		cout << number << "\n" ;

		cout << "Run writeCount with " << number << " - 1\n";
		writeCountReverse(number - 1);
		cout << "writeCount with " << number << " - 1 ended\n";

		// swapping the 2 lines causes it to go reverse
		// because 1 prints before calculating and the other does the reverse
	}
}