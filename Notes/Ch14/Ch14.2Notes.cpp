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
//WB-1.0
// Pre: Requires a base number and a power
// the power must be an integer greater than or equal to 0
// the base can be any int
// Post: calculates and returns base^power recursively
// int pow(int base, int power);

//ST-14.0
// Pre: Requires a base number and a power
// the base and power can be any int
// Post: calculates and returns base^power recursively
double pow(int base, int power);

int main()
{
	print("+++Chapter 14+++");
	print("\n--Recursice Functions For Tasks--\n\n");

	print("\nRecursive functions can return something");
	// countDigits in 14.1 returned int instead of void

	print("\nA recursive function that doesnt return void needs");
	print("1+ cases that return a smaller value to be recursively used");
	// Generally the returned value will be smaller than the original
	print("1+ base/stopping cases which return the final value");
	// You can't have any cases that don't return something

	print("Use WB-1.2 comment for more  information");

	cout << "\n\n2^0: " << pow(2, 0);
	cout << "\n2^1: "   << pow(2, 1);
	cout << "\n^10: "  << pow(2, 10);
	cout << "\n2^100: " << pow(2, 100);
	cout << "\n2^-1: " << pow(2, -1);
	cout << "\n2^-10: " << pow(2, -10);
	// Custom power function can be better than prebuilt 
	// because it returns int not double
	// Although for power functions, this approach is nonoptimal

	// ---SELF TEST START---
	// 12. What is the output of the following program?


	// int mystery(int n)
	// {
	// 	if (n < = 1)
	// 		return 1;
	// 	else
	// 		return ( mystery(n − 1) + n );
	// }

	// ex 5
	// 5 + 4 + 3 + 2 + 1 = 15

	// if 3 = returns 3 + 2 + 1 (6)

	// 13. What is the output of the following program? What well-known mathematical
	// function is rose ?
	
	// cout << rose(4);

	// int rose(int n)
	// {
	// 	if (n <= 0)
	// 		return 1;
	// 	else
	// 		return ( rose(n − 1) * n );
	// }

	// ex 5
	// 5 * 4 * 3 * 2 * 1 = 120

	// if 4 = returns 4 * 3 * 2 * 1 (24)	

	// 14. Redefine the function power so that it also works for negative exponents.
	// In order to do this, you will also have to change the type of the value
	// returned to double .

	//---SELF TEST END---

}

// WB-1.1
// int pow(int base, int power)
// {
// 	if (power < 0)
// 	{
// 		cout << "Illegal argument to power";
// 		exit(1);
// 	}

// 	if (power > 0)
// 	{
// 		return ( pow(base, power - 1) * base);
// 	}
// 	else // if x^0
// 	{
// 		return 1;
// 	}

// WB-1.2

// 	// Ex:
// 	// pow(5, 3)

// 	// Loop 0  
// 	// power is not less than 0, 1st block doesnt run
// 	// it is greter than 0, second block runs
// 	// (pow(5, 3) * 25)

// 	// Loop 1
// 	// power is not less than 0, 1st block doesnt run
// 	// it is greter than 0, second block runs
// 	// return (pow(25, 2) * 5)
// 	// creates new recursive function call adding to stack

// 	// Loop 2
// 	// power is not less than 0, 1st block doesnt run
// 	// it is greter than 0, second block runs
// 	// return (pow(5, 1) * 5)
// 	// creates new recursive function call adding to stack

// 	// Loop 3
// 	// power is not less than 0, 1st block doesnt run
// 	// it is not greter than 0
// 	// 3rd block runs
// 	// 1
// 	// stops adding to stack and begins going through each stack 
// 	// element and removing it

// 	// Loop 3 returns 1
// 	// Loop 2 returns pow(5, 1) * 5), 5*5 (25)
// 	// Loop 1 returns pow(25, 1) * 5), 25*5 (125)
// 	// 125 is returned

// 	// The larger the power is, create larger chains of recursive chains
// 	// if it is equal to 5, 5 chains, 10 it produces 11 chains, etc
// }

//ST-14.1
double pow(int base, int power)
{
	if (power < 0)
	{
		return ( pow(base, power + 1) / base);
	}

	if (power > 0)
	{
		return ( pow(base, power - 1) * base);
	}
	else // if x^0
	{
		return 1;
	}
}
