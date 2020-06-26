//Header file Ch12DayOfYe.h: This is the Interface for the class DayOfYear.
//Values of this type are day and month. The values are input and output in
//2 integers starting with month, so September 21st would be input as 9, 21.

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

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


namespace 
{
	// Descriptive comments for each function
	bool before(DayOfYear day1, DayOfYear day2);
	bool leadingZeros();
	void checkDate();
	bool equal(const DayOfYear& date1, const DayOfYear& date2);
}

namespace DoY
{
// DayOfYear::DayOfYear(int theMonth, int theDay) : month(theMonth), day(theDay);
// DayOfYear::DayOfYear();
// DayOfYear::~DayOfYear();
// DayOfYear::DayOfYear(const DayOfYear& dynamicDay);
// int DayOfYear::getMonth( );
// int DayOfYear::getDay( );
// void DayOfYear::operator =(const DayOfYear& copyClass);
bool operator ==(const DayOfYear& day1, const DayOfYear& day2);
DayOfYear operator +(const DayOfYear& day1, const DayOfYear& day2);
DayOfYear operator +(const DayOfYear& day1, auto number);
bool operator >(const DayOfYear& day1, const DayOfYear& day2);
void operator ++(DayOfYear& day1);
ostream& operator <<(ostream& output, DayOfYear& day1);

}
#endif//DAYOFYEAR_H