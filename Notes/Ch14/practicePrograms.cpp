#include <iostream>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;

int largestDivisor(int number);
// Pre: requires number, a whole number
// Post: Returns the largest divisor 
int largestDivisor(int number, int prev);
// Pre requires number, a positive whole number 
// and previous, a number starting at number and decramenting each itteration
// Post: (Only should be run within largestDivisor(int)) 
// Helper function to go through and return 
// so user can type ld(15) instead of ld(15, 15)

bool isPrime(int number);
// Pre: requires number, a whole number
// Post: Returns the largest divisor 
bool isPrime(int number, int prev);
namespace
{
	void print(string str)
	{
		cout << str << "\n";
	}
}

int main()
{
	print("largestDivisor: ");
	cout << "15: " << largestDivisor(15) << endl;
	cout << "5: " << largestDivisor(5) << endl;
	cout << "90: " << largestDivisor(90) << endl;

	print("\nPrime: ");
	cout << "15: " << isPrime(15) << endl;
	cout << "5: " << isPrime(5) << endl;
	cout << "90: " << isPrime(90) << endl;
}

int largestDivisor(int number)
{
	return largestDivisor(number, number);
}

int largestDivisor(int number, int prev)
{
	prev -= 1;
	if (number % prev != 0)
	{
		return largestDivisor(number, prev);
	}
	else
	{
		return prev;
	}
}
bool isPrime(int number)
{
	return isPrime(number, number);
}


bool isPrime(int number, int prev)
{
	prev -= 1;
	if (prev == 1)
	{
		return false;
	}
	if (number % prev == 0)
	{
		return true;
	}
	else
	{	
		return isPrime(number, prev);
	}
}