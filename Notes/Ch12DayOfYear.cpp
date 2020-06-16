//Header file Ch12DayOfYear.h: This is the Implementation for the ADT DayOfYear.
//Values of this type are day and month. The values are input and output in
// The interface is located in "DayOfYear.h"\

#include <iostream>
#include <string>

#include "Ch12DayOfYear.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;

using namespace DoY;
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

void checkDate()
{
// Assume there was actual code here to make it work
}

DayOfYear::DayOfYear(int theMonth, int theDay) : month(theMonth), day(theDay)
{
	// checkDate();void checkDate()
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

