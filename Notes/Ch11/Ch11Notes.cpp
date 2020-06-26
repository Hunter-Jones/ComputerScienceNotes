#include <iostream>
#include <string>
#include <fstream>  // Remember, includes istream & ostream
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::ostream;
using std::istream;

void print(auto text)
{
	std::cout << text << endl;
}

// WB-1
class DayOfYear
{
public:

	//Constructor 
	DayOfYear(int theMonth, int theDay);
	//Precondition: theMonth and theDay form a
	//possible date. Initializes the date according
	//to the arguments.

	// Default Constructor
	DayOfYear();
	//Initializes the date to January first.

	// destructor
	~DayOfYear();  // WB-8

	//Copy Constructor
	DayOfYear(const DayOfYear& dynamicDay);  // WB-9

 	void operator =(const DayOfYear& copyClass);  // WB-10

	friend bool operator ==(const DayOfYear& day1, const DayOfYear& day2);  // WB-4
	// Pre: Requires 2 DayOfYear classes with day and month filled
	// Post: Used to  things like easter == christmas
	// Returns a bool of if day1 and day2 share the same month and day var
	// Same as equal function

	friend bool operator >(const DayOfYear& day1, const DayOfYear& day2);  // ST-13
	// Pre: Requires 2 nonfilled DoY classes
	// Post returns a bool for whichever one is bigger

	friend DayOfYear operator +(const DayOfYear& day1, const DayOfYear& day2);
	// Pre: Requires 2 DayOfYear classes with month and day filled
	// Post: Used to add the of the values of day and month in the day1 and day2 classes
	// Returns a new DayOfYear class with the sum
	// So if day1's day is 11 and days is 25, it will become 11 + 25 which is 36, 
	// but then subtracted 31 (number of days in month) to get 5
	friend DayOfYear operator +(const DayOfYear& day1, auto number);  // WB-5
	// Pre: Requires a filled DayOfYear and any whole # (non-whole will be rounded down)
	// Post: Adds the number of days to day1 and returns a new DoY class

	friend void operator ++(DayOfYear& day1);  // WB-6
	// Pre: Requires a filled DayOfYear class
	// Post adds 1 to it, will add 1 to month and reset day to 1 if it is at 31 already

	void input();

	void output();

	int getMonth();

	//Returns the month, 1 for January, 2 for February, etc.
	int getDay();
	//Returns the day of the month.
	// WB-2.1
	// friend bool equal(DayOfYear date1, DayOfYear date2);  
	//WB-3
	friend bool equal(const DayOfYear& date1, const DayOfYear& date2); 
	//Precondition: date1 and date2 have values.WB-3
	//Returns true if date1 and d
private:
	void checkDate();
	int month;
	int day;
};

// WB-1.1
// bool equal(DayOfYear date1, DayOfYear date2)
// {
// 	return ( date1.getMonth( ) == date2.getMonth( ) && date1.getDay( ) == date2.getDay( ));
// }
//WB-2 
// bool equal(DayOfYear date1, DayOfYear date2) // Friend function 
// WB-3
bool equal(const DayOfYear& date1, const DayOfYear& date2)
{
	// This time it accesses the private member variables of DayOfYear
	// Remember it requires you to declare it as a friend function header (WB-2.1)
	return (date1.month == date2.month && date1.day == date2.day);
}

DayOfYear::DayOfYear(int theMonth, int theDay) : month(theMonth), day(theDay)
{
	// checkDate();
}
DayOfYear::DayOfYear()
{
	month = 1;
	day = 1;
}

DayOfYear::~DayOfYear()  // WB-8.1
{
	// delete [] dynamicArray;
	// delete dynamicVar;

	// Would be stuff here, but there is no dynamic memory used in DoY
}
DayOfYear::DayOfYear(const DayOfYear& dynamicDay) // WB-9
{
	// day = new int;
	// month& = new int;

	// day = dynamicDay.day;
	// *month = dynamicDay.month;

	// Again, all commented out because day/month aren't pointers,
	// SImilar to the destructor's issue	
}
int DayOfYear::getMonth( )
{
	return month;
}

int DayOfYear::getDay( )
{
	return day;
}

void DayOfYear::operator =(const DayOfYear& copyClass)  // WB-10.1
{
	 day = copyClass.day;
	month = copyClass.month;

	// Assuming day/month are pointers
	// *copyClass.day = *day;
	// *copyClass.month = *month;
	// Needs to set the VALUES not the memory location the same (to deep copy)
}

// How the book copies an array:
// void StringVar::operator =(const StringVar& rightSide)
// {
	// int newLength = strlen(rightSide.value);
	// if (newLength > maxLength)
	// {
		// delete [] value;
		// maxLength = newLength;
		// value = new char[maxLength + 1];
	// }

	// for (int i = 0; i < newLength; i++)
		// value[i] = rightSide.value[i];
	// value[newLength] = '\0';
	// }

// ST-1
bool before(DayOfYear day1, DayOfYear day2)
{
	// If the first day's is month(s) earlier
	if (day1.getMonth() < day2.getMonth())
	{
		return true;
	}
	// If first day is less than a month earlier
	if (day1.getMonth() == day2.getMonth() && day1.getDay() < day2.getDay())
	{
		return true;
	}
	// If they are equal or first day is after
	return false;
}

// ST-2
// Checks if it works leading 0s work the same or it gets converted to base 8
bool leadingZeros()
{
	// The number being tested (9) has to be greater than 7
	// Otherwise it would be the same in b8 and b10
	// try
	// {
	// 	if (09 == 9)
	// 		return true;
	// }
	// catch (...){}
	// Apparently compiler gives a windows error
	return false;
}

bool operator ==(const DayOfYear& day1, const DayOfYear& day2)  // WB-4.1
{
	return day1.day == day2.day && day1.month == day2.month;
}

DayOfYear operator +(const DayOfYear& day1, const DayOfYear& day2)
{
	int newDay = day1.day + day2.day;
	int newMonth = day1.month + day2.month;

	if (newDay > 31)
		newDay -= 31;
	if (newMonth > 12)
		newMonth -= 12;

	return DayOfYear(newMonth, newDay);
}
DayOfYear operator +(const DayOfYear& day1, auto number)  // WB-5.1
{
	int newDay = day1.day + number % 31;
	int newMonth = (day1.month + (number / 31)) % 12;

	return DayOfYear(newMonth, newDay);
}
// void operator =(DayOfYear& day1, DayOfYear& day2)
// {
// 	day1.day = day2.day;
// 	day1.month = day2.month;
// 	return;
// }
// Cant modify + operator

bool operator >(const DayOfYear& day1, const DayOfYear& day2)  // ST-13
{
	// If month is greater
	if (day1.month > day2.month)
		return true;
	// If in same month and day is greater
	if (day1.month == day2.month && day1.day > day2.day)
		return true;
	return false;
}

void operator ++(DayOfYear& day1)  // WB-6.1
{
	if (day1.day = 31)
	{
		day1.day = 1;
		day1.month++;
	}
	else
	{
		day1.day++; 
	}
}

// Pre: Requires the ouput stream and a DayOfYear class with month and day filled
//Needs to be in a format of outStream << DoY
// Outputs month: #MONTH day: #DAY from day1 to the output ostream
ostream& operator <<(ostream& output, DayOfYear& day1)  // WB-7
{ // Could have been a friend function, but chose not to for demonstration purposes
	 output << "month: " << day1.getMonth() << ", day: " << day1.getDay();
	 return output;
}

struct Test 
{
	int number;
	string letters;
	int numbers[10];
	int* numPtr;
	int *dnum = new int;
};




class Pairs  // ST-17
{
public:
	// Pairs( );
	// Pairs(int first, int second);
//other members and friends
	friend istream& operator >>(istream& ins, Pairs& second);
	friend ostream& operator <<(ostream& outs, const Pairs& second);
private:
	int f;
	int s;
};

istream& operator >>(istream& ins, Pairs& second)
{
	ins >> second.f;
	ins >> second.s;
	return ins;
}

ostream& operator <<(ostream& outs, const Pairs& second)
{
	outs << "(" << second.f << ", " << second.s <<")";
	return outs;
}

class Percent  // ST-18
{
public:
	friend bool operator ==(const Percent& first, const Percent& second);
	friend bool operator <(const Percent& first, const Percent& second);
	// Percent();
	// Percent(int percentValue);

	friend istream& operator >>(istream& ins, Percent& theObject);
	//Overloads the >> operator to input values of type
	//Percent.
	//Precondition: If ins is a file input stream, then ins
	//has already been connected to a file.
	friend ostream& operator <<(ostream& outs, const Percent& aPercent);
	//Overloads the << operator for output values of type
	//Percent.
	//Precondition: If outs is a file output stream, then
	//outs has already been connected to a file.

private:
	int value;
};

istream& operator >>(istream& ins, Percent& theObject)
{
	ins >> theObject.value;
	return ins;
}

ostream& operator <<(ostream& outs, const Percent& aPercent)
{
	outs << aPercent.value << "%";
	return outs;
}
bool operator ==(const Percent& first, const Percent& second)
{
	if  (first.value == second.value)
		return true;
	return false;
}
bool operator <(const Percent& first, const Percent& second)
{
	if (first.value < second.value)
		return true;
	return false;
}

void friendFunctions();
void overloadedOperators();
void arraysAndClasses();
void classesAndDynamicArrays();



// ---- MAIN ----
int main()
{
	print ("---Chapter 11---");
	print("---Friends, Overloaded Operators, and Arrays in Classes---");

	friendFunctions();
	overloadedOperators();
	arraysAndClasses();
	classesAndDynamicArrays();

	// ---SUMMARY START---
	// A friend function of a class is an ordinary function except that it has access
	// to the private members of the class, just like the member functions do.
	
	// If your classes each have a full set of accessor and mutator functions, then
	// the only reason to make a function a friend is to make the definition of the
	// friend function simpler and more efficient, but that is often reason enough.
	
	// A parameter of a class type that is not changed by the function should nor-
	// mally be a constant parameter.
	
	// Operators, such as + and == , can be overloaded so they can be used with
	// objects of a class type that you define.
	
	// When overloading the >> or << operators, the type returned should be a
	// stream type and must be a reference, which is indicated by appending an &
	// to the name of the returned type.
	
	// The base type of an array can be a structure or class type. A structure or class
	// can have an array as a member variable.
	
	// A destructor is a special kind of member function for a class. A destruc-
	// tor is called automatically when an object of the class passes out of scope.
	// The main reason for destructors is to return memory to the freestore so the
	// memory can be reused.
	
	// A copy constructor is a constructor that has a single argument that is of the
	// same type as the class. If you define a copy constructor, it will be called au-
	// tomatically whenever a function returns a value of the class type and when-
	// ever an argument is “plugged in” for a call-by-value parameter of the class
	// type. Any class that uses pointers and the operator new should have a copy
	// constructor.
	
	// The assignment operator = can be overloaded for a class so that it behaves
	// as you wish for that class. However, it must be overloaded as a member of
	// the class; it cannot be overloaded as a friend. Any class that uses pointers
	// and the operator new should overload the assignment operator for use with
	// that class.
	// ---SUMMARY END---
}

void friendFunctions()
{
	print("\n\n--Ch 11.1: Friend Functions--");

	print("\nSometimes you need to not inside a class that aren't defined inside of the class");

	DayOfYear birthday(9, 15);
	DayOfYear graduation(5, 13);
	DayOfYear yesterday(5, 13);

	// WB 1.1 is a function used to compare two DayOfYear classes
	// It takes a class as a paramter
		// They get passed the same as regular variables
	// cout << equal(birthday, graduation) << " " << equal(graduation, yesterday);

	// ---SELF TEST START---

	// 1.Write a function definition for a function called before that takes two
	// arguments of the type DayOfYear, which is defined in Display 11.1. The
	// function returns a bool value and returns true if the first argument rep-
	// resents a date that comes before the date represented by the second ar-
	// gument; otherwise, the function returns false; for example, January 5
	// comes before February 2.

	//  ST-1
	// cout << before(birthday, graduation);

	// ---sSELF TEST END---

	// WB 2.1
	print("\nFreind function- not a member of a class, but has access to private member variables");
	print("To declare a friend header use friend keyword then declare the header like normal in the public section of the class");
	print("Ex: friend bool equal(DayOfYear date1, DayOfYear date2);");
	print("Friend functions are just ordinary functions that have access to private members of a function");

	print("\nIf you made all functions friend functions, then you wouldn't need accessor/mutator functions");
	print("You should NOT do this though");
	print("One reason you need accessors is mutators is if you declare a class inside a friend function, you can't access the values of private members without mutators or accessors");
	// Friend functions access private members on parameters
	// They dont access it on classes created within the friend function

	print("\nWhen to use friend functions vs member functions");
	print("     Use a member function if the task being performed by the function involves one object");
	print("     Use a nonmember function if the task being performed involves more than one object");
	// Equals is a friend function because it uses 2 DayOfYear obhects

	print("\n If you have enough mutator functions, you can do either nonmember functions (WB-1.1) or friend functions (WB-2)");

	print("\nBetter when to use friend functions rule:");
	print("If the task is intimately elated to a single object; use a nonmember function when the task involves more than one object and the objects are used symmetrically");

	// ---SELF TEST START---
	// 	2. What is the difference between a friend function for a class and a member
	// function for the class?

	// Friend functions get declared as friend functions in the class and can access private members of a friended class, 
	// but besides that, they operate like normal non-member functions

	// 3. Suppose you wish to add a friend function to the class DayOfYear
	 // This friend function will be named after and will take
	// two arguments of the type DayOfYear. The function returns true if the
	// first argument represents a date that comes after the date represented
	// by the second argument; otherwise, the function returns false . For
	// example, February 2 comes after January 5. What do you need to add to
	// the definition of the class DayOfYear 

	// friend bool dayOfYear(DayOfYear day1, DayOfYear day2);
	// Basically just ST-1 I think

	// 4. Suppose you wish to add a friend function for subtraction to the class
	// Money. What do you need to add to the description
	// of the class Money? The subtraction function
	// should take two arguments of type Money and return a value of type Money
	// whose value is the value of the first argument minus the value of the
	// second argument.

	// friend int subtraction(Money amount1, Money amount2);  // In money class public section

	// int subtraction(Money amount1, Money, amount2)  // At bottom 
	// {
	// 	return amount1.balance - amount2.balance
	// }

	// 5. Notice the member function output in the class definition of Money given
	// In order to write a value of type Money to the screen, you
	// call output with cout as an argument. For example, if purse is an object
	// of type Money , then to output the amount of money in purse to the
	// screen, you write the following in your program:
	// purse.output(cout);
	// It might be nicer not to have to list the stream cout when you send output
	// to the screen.
	// Rewrite the class definition for the type Money given in Display 11.3. The
	// only change is that this rewritten version overloads the function name
	// output so that there are two versions of output . One version is just like
	// the one shown; the other version of output takes no argu-
	// ments and sends its output to the screen. With this rewritten version of
	// the type Money , the following two calls are equivalent:
	// purse.output(cout);
	// and
	// purse.output();
	// but the second is simpler. Note that since there will be two versions of the
	// function output , you can still send output to a file. If outs is an output
	// file stream that is connected to a file, then the following will output the
	// money in the object purse to the file connected to outs :
	// purse.output(outs);

	// Original:
	//Uses cstdlib and iostream:
	// void Money::output(ostream& outs)
	// {
	// 	long positiveCents, dollars, cents;
	// 	positiveCents = labs(allCents);
	// 	dollars = positiveCents / 100;
	// 	cents = positiveCents % 100;

	// 	if (allCents < 0)
	// 		outs << "−$" << dollars << '.';
	// 	else
	// 		outs << "$" << dollars << '.';
	// 	if (cents < 10)
	// 		outs << '0';
	// 	outs << cents;
	// }
	// // Modified Overloaded version
	// void Money::output()
	// {
	// 	long positiveCents, dollars, cents;
	// 	positiveCents = labs(allCents);
	// 	dollars = positiveCents / 100;
	// 	cents = positiveCents % 100;
	// 	if (allCents < 0)
	// 		cout << "−$" << dollars << '.';
	// 	else
	// 		cout << "$" << dollars << '.';
	// 	if (cents < 10)
	// 		cout << '0';
	// 	cout << cents;
	// }

	// 6. Notice the definition of the member function input of the class Money
	// If the user enters certain kinds of incorrect input, the
	// function issues an error message and ends the program. For example, if the
	// user omits a dollar sign, the function issues an error message. However, the
	// checks given there do not catch all kinds of incorrect input. For example,
	// negative amounts of money are supposed to be entered in the form −$9.95,
	// but if the user mistakenly enters the amount in the form $−9.95, then the
	// input will not issue an error message and the value of the Money object will
	// be set to an incorrect value. What amount will the member function input
	// read if the user mistakenly enters $−9.95? How might you add additional
	// checks to catch most errors caused by such a misplaced minus sign?

	// void Money::input(istream& ins)
	// {
	// 	char oneChar, decimalPoint, digit1, digit2;
	// 	//digits for the amount of cents
	// 	long dollars;
	// 	int cents;
	// 	bool negative;//set to true if input is negative.

	// 	ins >> oneChar;
	// 	if (oneChar == ' ')
	// 	{
	// 		negative = true;
	// 		ins >> oneChar; //read '$'
	// 	}
	// 	else
	// 		negative = false;
		
	// 	//if input is legal, then oneChar == '$'
	// 	ins >> dollars >> decimalPoint >> digit1 >> digit2;
	// 	if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
	// 	{
	// 		cout << "Error illegal form for money input\n";
	// 		exit(1);
	// 	}
		
	// 	cents = digitToInt(digit1) * 10 + digitToInt(digit2);
		
	// 	allCents = dollars * 100 + cents;
	// 	if (negative)
	// 		allCents = −allCents;
	// }

	// Negative will never get set to true
	// onechar will be set to $
	// dollars will be set to -, decimalPoint will be set to 9, digit1 will be set to ., and digit2 will be set to 9 (each is shifted one off)
	// Before you have if (oneChar == ' ') you could  have:
		// if(oneChar == '-')
			// if true, cout error message 
			// othrwise just run like normal

	// 7. The Pitfall section entitled “Leading Zeros in Number Constants” suggests that
	// you write a short program to test whether a leading 0 will cause your compiler
	// to interpret input numbers as base-8 numerals. Write such a program.

	 // My compiler cant, had to comment it out because it gave an error
	// ST-2

	// ---SELF TEST END---

	print("\nRemember call by reference is more efficient then call by value");
	print("Remember, for most types like double and char it is an insignificant difference");

	print("\nConst paramter- Used to make it so CBR (or any) parameter is unchangable");
	print("It can be used like normal with classes");
	// Money add(const Money& amount1, const Money& amount2)
	// friend Money add(const Money& amount1, const Money& amount2);
	// Also check WB-3
	print("Like normal, const must be used in the header and declaration of the function");
	// IMP, will throw errors otherwise

	print("\n To make it so the class the member function is in remains constant, use the const keyword outside the paramter");
	// EX: void Money::output(ostream& outs) const
		// This makes it so member variables of money don't change inside the output function

	print("\nConst is an example of automatic error checking");
	print("This is because, whenever you modify a const var it will throw an error");

	print("Remember , const is all-or-nothing and you should use or not use const on all parameters of the same type");

	// SELF TEST STAER

	// 8. Give the complete definition of the member function getValue that you
	// would use with the definition of Money.
	
	// In private allCents is a long holding the money in terms sof cents
	// double getValue()
	// {
	// 	return (double)allCents / 100
	// }

	// 9. Why would it be incorrect to add the modifier const , as shown here, to
	// the function declaration for the member function input of the class Money
	// class Money
	// {
	// ...
	// public:
	// void input(istream& ins) const;

	// ...

	// Fixed version
	// void input(const istream& ins);
	// It would be incorrect because input modifies the class it is inside of 
	
	// 10. What are the differences and the similarities between a call-by-value
	// parameter and a call-by- const -reference parameter? Function declarations
	// that illustrate these are

	// Same: Both appear the same by making it impossible to modify the paramter
	// Different: CBR doesn't create a copy and only gives the function the location and is more efficient

	// 11. Given the following definitions 
	// Each of the three const keywords is a promise to the compiler that the com-
	// piler will enforce. What is the promise in each case?

	// const int x = 17;
	

	// class A
	// {
	// public:
		// A( );
		// A(int x);
		// int f( ) const;

		// int g(const A& x);
	// private:
		// int i;
	// };

	// This int will never change, ever
	//The A class f is calling's member variables wont change in the f function
	// The A class x's member variables won't change in the g function

}
void overloadedOperators()
{
	print("\n\n--Ch 11.2: Overloading Operators--");

	print("\n The + operator is really just a function");
	print("It is possible to overload the + function");
	print("You could have an add function with add(int1 + int2) instead of add(int1, int2");

	print("\nTo overload an operator you type the keyword operator then whatever operator you want (+)");
	print("After that, the definition is the same as the add defintion");

	print("\nIf dealing with classes, you will probably want to use a freind function");
	// You dont have to have a friend function

	DayOfYear graduation(5, 13);
	DayOfYear birthday(9, 15);
	DayOfYear bestDayOfWeek(5, 13);
	// bestDayOfWeek = bestDayOfWeek + birthday;
	bestDayOfWeek = graduation;
	// = is already overloaded
	// you cannot overload it yourself

	// print(birthday == bestDayOfWeek); // Now you can use them like normal
	// print(bestDayOfWeek.getMonth());
	//This is actually really cool

	print("\nBinary operators are like functions, but the main difference is they have a differeny syntax");

	// ---SELF TEST START---

	// 12. What is the difference between a (binary) operator and a function?

	// The syntax differs, but it acs like a regular function

	// 13. Suppose you wish to overload the operator < so that it applies to the type
	// Money. What do you need to add to the description
	// of Money?

	//ST-13
	// Might have used > instead of <, just switch > to < and it will work

	// 14. Suppose you wish to overload the operator <= so that it applies to the type
	// Money. What do you need to add to the description of MoneY?

	// Just imagine ST-13 with >= instead of >

	// 15. Is it possible using operator overloading to change the behavior of + on
	// integers? Why or why not?

	// Yes, becayse you define the operator to be whatever you want to work with your classes
	// You should try to make it work in a way that makes sense thougj
	// So, the + operator shouln't be used to do something random or something that you think the - operator should do

	// ---SELF TEST END---

	print("\nOverload rules:");
	print("     When overloading, 1 or more arguments needs to be a class");
	// To not confuse with the predefined operator
	print("     Overloaded operators can be, but don't have to be friend classes. It can be a member function or an ordinary class");
	print("     You can't create operators and can only use existing like + = * / %");
	print("     You can not change operator precedence (PEMDAS)");
	print("     . :: .* and ?: operators can't be overloaded");
	print("     = can be overeloaded, but it is done in a different way, [], -> can also be overloaded");


	birthday = birthday + 15;
	// This will cause an error, because + works for DayOfYearTypes only, not ints
	// The error was fixed in WB-5

	print("\n Using auto can be helpful to work with types like int, double, long, etc instead of defining each seperately");
	print("You will get an error though if you try to add a string when it calls for a number, and other similar type-conversion cases");
	print("To fix that, you can add alternative constructors for things like double or long");
		// I was too lazy to restructure it to do that

	print("\n++ -- and other unary operators can be overloaded");  // WB-6

	// Remember Binary Operator: = - / * % > < >= <=
	//  		Unary Operator ++ --

	print("\n>> and << can also be overloaded");

	cout << "Test: " << birthday;
	// Should just be able to copy and paste the output member function, but I dont have it
	// Works same as input
	// WB-7

	// SELF TEST START

	// 17. Here is a definition of a class called Pairs . Objects of type Pairs can
	// be used in any situation where ordered pairs are needed. Your task is to
	// write implementations of the overloaded operator >> and the overloaded
	// operator << so that objects of class Pairs are to be input and output in
	// the form (5,6)(5,−4)(−5,4) or (−5,−6) . You need not implement any
	// constructor or other member, and you need not do any input format
	// checking.

	// cout << endl;
	// Pairs ree;
	// cout << "Enter 2 numbers: ";
	// cin >> ree;
	// cout << ree;
	// ST-17
	// Uncomment to try out

	// 18. Following is the definition for a class called Percent . Objects of type
	// Percent represent percentages such as 10% or 99%. Give the definitions
	// of the overloaded operators >> and << so that they can be used for
	// input and output with objects of the class Percent . Assume that input
	// always consists of an integer followed by the character ‘ % ’, such as 25% . All
	// percentages are whole numbers and are stored in the int member variable
	// named value . You do not need to define the other overloaded operators
	// and do not need to define the constructor. You only have to define the
	// overloaded operators >> and <<

	// ST-18
	// Percent firstP;
	// Percent secondP;
	// cout << "Enter a percent: ";
	// cin >> firstP;
	// cout << "Enter another percent: ";
	// cin >> secondP; 
	// cout << "You entered: " << firstP << " and " << secondP << endl; 
	// cout << "Do they equal? " << (firstP == secondP) << endl;
	// cout << "Is the second greater? " << (firstP < secondP) << endl;
	// Uncomment to to try out
	// SELF TEST END
} 

void arraysAndClasses()
{
	print("\n\n--Ch 11.3: Arrays and Classes--");
	
	print("\nAny type, including structures and classes can be be an array");

	Pairs testPair[3];
	DayOfYear week [7];
	// Must have the default constructor or a constructor that can be called without ()

	week[6].getDay();  // Didn't input anything, so all will be set to the default day of Jan 1st
	// Would use setDay/Month for a few, but hasn't been defined

	int today[2] = {5, 17};
	for(int i = 0; i < 7; ++i)
	{
		today[1] += i;  // Sets day + 1

		if(today[1] <= 31)  
		// If the end of the month
		// Set day = 1 and add 1 to month
		{
			today[0] += 1;
			today[1] = 1;
			if(today[0] < 12)
			// If month is past 12
			// Set month back to 1
			// If 
			{
				today[0] = 1;
			}
		}

		// Sets month/day, would be uncommented if setDay/setMonth existed
		// week[i].setMonth(today[0]);
		// week[i].setDay(today[1]);
	}

	print("\nLooping through them works well");
	print("The array uses the default constructor to create each class");

	// ---SELF TEST START---
	// 19. Give a type definition for a structure called Score that has two member
	// variables called homeTeam and opponent . Both member variables are
	// of type int . Declare an array called game that is an array with ten elements of
	// type Score . The array game might be used to record the scores of each of
	// ten games for a sports team.

	// Score game[10];

	// 20. Write a program that reads in five amounts of money, doubles each
	// amount, and then writes out the doubled values to the screen. Use one
	// array with Money as the base type. (Hint: Use Display 11.9 as a guide, but
	// this program will be simpler than the one in Display 11.9.)

	// SKIP

	// It should be pretty easy, just feeling lazy. All you need to do is create a 5-element money array
	// Then run a for loop with a cin statement and saving the amount entered to a variable
	// Within the for loop, use the variable as the input argument for the money class' input memberfunction
	// EZ
	// ---SELF TEST END---

	print("\nYou can have arrays as members of an object"); //WB-7
	Test newTest;
	newTest.numbers[3] = 5;  // Accessed just like normal with the . operator
	print("They are called like and can be looped through like normal arrays");
	print("They  can be used in structures and classes (any object)");
	print("With classes, try to make arrays private member variables and only accessed with public member functions");

	// ---SELF TEST START---
	// 21. Change the class TemperatureList given in by adding a
	// member function called getSize , which takes no arguments and returns
	// the number of temperatures on the list.

	// Pre: Requires nothing
	// Post: Getter function to return the size variable
	// Returns the number of elements in the TemperatureList class
	// int TemperatureList::getSize()
	// {
	// 	return size;
	// }

	// 22. Change the type TemperatureList given in Display 11.10 by adding a
	// member function called getTemperature , which takes one int argument
	// that is an integer greater than or equal to 0 and strictly less than
	// MAX_LIST_SIZE . The function returns a value of type double , which is
	// the temperature in that position on the list. So, with an argument of 0 ,
	// getTemperature returns the first temperature; with an argument of 1 , it
	// returns the second temperature, and so forth. Assume that getTemperature
	// will not be called with an argument that specifies a location on the list
	// that does not currently contain a temperature.

	// Pre: Requires number, a variable for the desired index between 0 and 49
	// Post: Returns the value indexed at number in the array list
	// Will print an error if the user doesn't enter a number within the range
	// double TemperatureList::getTemperature(int number)
	// {
	// 	if (number <= 0 && number < MAX_LIST_SIZE)
	// 	{
	// 		return list[number];
	// 	}
	// 	else
	// 	{
	// 		cout<< "ERROR: Number must be between 0-49, returning 0.0";
	// 	}
	// }

	//
}

void classesAndDynamicArrays()
{
	print("\n\n--Ch 11.4: Dynamic Arrays And Classes--");

	print("\nA dynamic array's base type can be a class");
	print("Classes can also have dynamic arrays as member variables");
	print("They can also have pointers");

	DayOfYear *dynamicDate = new DayOfYear(9, 15);

	//delete dynamicDate; // Delete doesn't work w/o destructor
	// Normally delete is used to destroy dynamic memory, because they don't automatically delete

	// If you have dynamic variables in the class, they won't be deleted when the class is out of scope and need manually deleted
		// Wastes memory if you have left over d-mem and it can crash program
	print("\ndestructor- Member function that is called automatically when the Class is out of scope");
	print("destructors can be created to delete all dynamic memory");
	print("destructors syntax: The definition is ~ClassName(); and the header is ClassName::~ClassName(){}");
	//WB-8

	print("\nBasically the destructor just goes through and calls delete for each member variable in the class");
	print("It can do anything else to \"clean up\", when the class is deleted if needed");

	// Pitfall:

	// // Inside global (Top)
	// typedef int* IntPointer;
	// void sneaky(IntPointer temp);

	// // Inside main
	// IntPointer p;
	// p = new int;
	// *p = 77;
	// sneaky(p);

	// // Inside global
	// void sneaky(IntPointer temp)
	// {
	// *temp = 99;
	// }

	// Because sneaky asks for a call by value for the argument temp
	// It only passes the value associated with the pointer
	// This means, when you modify it inside the function sneaky
	// No changes were made outside of it 
	// (Remember: No value changes outside of CBV)

	// Can be fixed with copy constructors
	print("\nCopy Constructor- constructor that has one parameter that is of the same type of class");  // WB-9
	print("The parameter must be CBR");
	print("Other than that, it is defined the same whay a normal constructor is");

	print("\nWhen you call a copy constructor, it creates an independent copy (Dynamic) of its argument");
	print("Any changes to the dynamic copy don't affect the original");

	print("\nDeep Copy- When you completely copy a dynamic structure");
	print("Shallow Copy- Only copying a reference to the same dynamically allocated array");
	print("Copy Constructors make deep copies");
	// If they were'nt deep copies, then changing the copy WOULD affect the original

	print("\nC++ automaticall calls the copy constructor when it needs to make a duplicate of a constructor");
	print("The 3 situations are:");
	print("     When a class object is declared and initialized by another object of the same type");
	print("     When a function returns a value of a class type");
	print("     Whenever you use a class as the CBV parameter in a function");

	// -Example when Copy Constructor is needed:-

	// showString is a function that takes a theString, a StringVar class as an argument then prints it out
	// theString has a dynamic variable called value

	// StringVar greeting("Hello");
	// showString(greeting);  // Will show string normally
	// cout << "After call: " << greeting << endl;  // Will print undefined

	// IF there wasn't a copy constructor the greeting.value and the now copied theString.value
		//Just to clarify greeting is the global scope StringVar class
		// theString is the shallow copy made when you called showString
	// both point to the same memory address (In this case the string hello)
	// When the destructor is called for theString (the copy), it deletes theString.value, which also points to greet.value
	// This means that after calling showString, greeting has no value
		// Whenever greeting.value is called it will be emppty
		// When the 

	// If there was a copy constructor that made a deep copy instead of a shallow copy, 
	// then theString.value and greeting.value would both point to their own instances of value ("Hello")
	// This would allow you to be able to delete theString.value without affecting greeting.value

	//-END- (This kind of makes sense, but I still barely understand this)

	// Shown in text above
	print("\nWithout a default constructor, dynamic memory may be deleted after CBV leaves scope");
	// Spook

	print("\nwhenever you use new keyword, you should have a copy constructor that deep copies it");

	print("\nWhen you set an object equal to another, the copy constructor is NOT used");
	print("You can redefine the assignment operator though");

	print("\nBig 3: Copy constructor, assignment operator, and destructor");
	print("If redefine any of them, you MUST redefine all 3 or the compiler will give errors");

	// ---SELF TEST START---
	// 23. If a class is named MyClass and it has a constructor, what is the constructor
	// named? If MyClass has a destructor, what is the destructor named?

	// MyClass(); 				// Constructor
	// ~MyClass();  			// destructor
	// MyClass(MyClass obj);  	// Copy Constructor

	// MyClass::MyClass(){} // Definition [Same for all 3 but with ~ and the MyClass parameter]

	// 24. Suppose you change the definition of the destructor in 
	// the following. How would the sample dialogue change?
	// StringVar::~StringVar()
	// {
	// 	cout << endl  
	// 	<< "Good-bye cruel world! The short life of\n"
	// 	<< "this dynamic array is about to end.\n";
	// // The only change was the addition of the cout
	// 	delete [] value;
	// }

	// Whenever a StringVar goes out of scope, then the message will be displayed

	// 25. The following is the first line of the copy constructor definition for the
	// class StringVar . The identifier StringVar occurs three times and means
	// something slightly different each time. What does it mean in each of the
	// three cases?
	// StringVar::StringVar(const StringVar& stringObject)

	// 1st is to specify that it is referring to the function in the class stringvar
		// This allows you to have functions named StringVar that aren't associated with the class
	// 2nd reffers to the function named StringVar (a copy constructer member function in the class Stringvar)
	// 3rd refers to the argument, a StringVar called stringObject
		// This is used to crete a dynamic copy of the class whenever the user deep copies the class

	// 26. Answer these questions about destructors.
	// a. What is a destructor and what must the name of a destructor be?
		// It specifies what must happen when a class leaves scope
		// Name: ~ClassName();
	// b. When is a destructor called?
		// When the class instance is deleted or leaves scope
	// c. What does a destructor actually do?
		// It specifies what happens when the class is deleted
		// This usually is deleting dynamic memory and anything else to clean up the class
	// d. What should a destructor do?
		// To be honest, I have no idea what the difference from this the first half of A is and C. This was a stupid question
	// ---SELF TEST END---

	print("\n  The predefined assignment statement for classes goes through each assignment and copies the member variables");
	print("For pointers, both the original & the copy point to the same location");
	print("This will cause issues when the destructor for one is called because it deletes it for both the original and copy");
	print("It also causes issues because if you change the value of one, it changes the value of the other");

	print("\n Assignment operator has it's own unique way to be overloaded");
	print("For = operator, it has to be a member function and can't be a friend function");  // WB-10

	// 27. a.Explain carefully why no overloaded assignment operator is needed
	// when the only data consists of built-in types.
	// b. Same as part (a) for a copy constructor.
	// c. Same as part (a) for a destructor.

	// A. The operators are already overloaded to work with all built-in types
	// B/C. Without dynamic memory, the default constructor and default constructor should be fine
		// New Copy Constructors/destructors are only used to deal with issue of when to free up dynamic memory and to deep copy 
}




