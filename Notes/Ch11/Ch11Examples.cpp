#include <iostream>
#include <string>
#include <fstream>

using std::endl;
using std::cin;
using std::cout;
using std::string;

class VectorDouble
{
public:
	// Pre: Requires Nothing
	// Post: Sets equal to a vector of 50 elements with maxCount double that
	VectorDouble();
	// Pre: Requires the array size
	// Post: Sets size equal to the int and capacity to double size
	VectorDouble(int size);
	// Pre: Used as a copy constructor
	// Post: Copies the constructor to the copy version
	VectorDouble(VectorDouble& copy);
	// Pre: Used as destructor
	// Post, deletes dynamic memory
	~VectorDouble();

	// Pre: Requires a prefilled VD
	// Post: Sets this equal to the parameter
	void operator =(VectorDouble& right);
	// Pre: Requires a prefilled VD
	// Post: Checks if size / capacity is the for both arrays
	// Loops through both arrays to check if they are equal
	bool operator ==(const VectorDouble& right);

	// Gets count
	int size();
	// Gets mazCount
	int capacity();

	// Pre: Requires numbers to be filled with values
	// Post: Prints out each value with a space between each entry and an endl at the end
	void print();

	// Pre: Requires a number which is less than count for the index in the array
	// Post: Returns the double for the element at index
	double valueAt(int index);
	// Pre:Requires an index, which is less than count, and a new double value to insert at index
	// Post: Sets the array value at index equal to newValue
	// NOTE: Will delete the original value
	void changeValue(int index, double newValue);
	// Pre: Requires a double for an element to search for
	// Post: Loops through the array and finds the first occurence of searchValue and return the int of the index
	// NOTE: Will return -1 if searchValue does not exist
	int find(double searchValue);
	// Pre: Requires 2 ints less than count for the indexes in the array to swap
	// Post: Swaps the values of val1 and val2 in the numbers array
	void swap(int value1, int value2);

	// Pre: Requires any double
	// Post: Adds a new element to the array
	// Will increase size by 1, and double capacity once it's limit has been reached
	void pushback(double element);
	// Pre: Requires nothing;
	// Post: Reduces size by 1, clears the elemet
	void popback();

private:
	int maxCount;  // Capacity
	int count = 0; // Size
	double* numbers;
};

int main()
{
	VectorDouble vector;
	VectorDouble otherVector(2);

	vector.pushback(5);
	vector.pushback(10);
	vector.pushback(15);
	vector.print();
	cout << vector.size() << " " << vector.capacity() << endl;

	vector.popback();
	vector.print();

	otherVector.pushback(3);
	otherVector.pushback(6);
	otherVector.pushback(9);
	otherVector.pushback(12);

	cout << (vector == otherVector) << endl;

	vector = otherVector;
	vector.print();

	cout << (vector == otherVector) << endl;

	otherVector.pushback(7);
	vector.print();
	otherVector.print();

	cout << vector.size() << " " << vector.capacity() << endl;

	cout << vector.find(9) << " " << vector.find(35) << endl;
	cout << vector.valueAt(vector.find(9)) << " " << vector.valueAt(0) << endl;
	vector.changeValue(0, 1.5); vector.changeValue(1, 2.25);
	vector.print();
	vector.swap(0, 1);
	vector.print();


}

VectorDouble::VectorDouble()
{
	numbers = new double[50] {0};
	maxCount = 50;
}
VectorDouble::VectorDouble(int size)
{
	maxCount = size;
	numbers = new double[maxCount] {0};
}
VectorDouble::VectorDouble(VectorDouble& copy)
{
	copy.numbers = new double[maxCount] {0};
	copy.maxCount = maxCount;
	copy.count = count;

	for (int i = 0; i < count; ++i)
	{
		copy.numbers[i] = numbers[i];
	}
}
VectorDouble::~VectorDouble()
{
	delete [] numbers;
}

void VectorDouble::operator =(VectorDouble& right)
{
	count = right.count;
	maxCount = right.maxCount;

	delete [] numbers;
	numbers = new double[maxCount];
	for (int i = 0; i < count; ++i)
	{
		numbers[i] = right.numbers[i];
	}
}
bool VectorDouble::operator ==(const VectorDouble& right)
{
	// First makes sure size/capacity are the same
	if (count != right.count && maxCount != right.maxCount)
		return false;

	// Just need 1 loop, because would return false if both don't have the same size
	// Now loops through to find element mismatches
	for (int i = 0; i < count; ++i)
	{
		if (numbers[i] != right.numbers[i])
			return false;
	}

	return true;
}

int VectorDouble::size()
{
	return count;
}
int VectorDouble::capacity()
{
	return maxCount;
}
void VectorDouble::print()
{
	for (int i = 0; i < count; ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

double VectorDouble::valueAt(int index)
{
	return numbers[index];
}
void VectorDouble::changeValue(int index, double newValue)
{
	numbers[index] = newValue;
}
int VectorDouble::find(double searchValue)
{
	for (int i = 0; i < count; ++i)
	{
		if (numbers[i] == searchValue)
		{
			return i;
		}
	}
	return -1;
}
void VectorDouble::swap(int value1, int value2)
{
	double temp;

	temp = numbers[value2];
	numbers[value2] = numbers[value1];
	numbers[value1] = temp;
}

void VectorDouble::pushback(double element)
{
	numbers[count] = element;
	++count;

	// If the size is equal to the capacity
	if (count >= maxCount)
	{
		// Doubles the capacity
		maxCount *= 2;
		// Creates a new d-array that is 2x as big
		double* newNumbers = new double[maxCount];

		// Sets  the new d-array to the old one (with double the capacity)
		for (int i = 0; i < count; ++i)
		{
			newNumbers[i] = numbers[i];
		}

		// Deletes the old d-array and sets the old d-array equal to the new one (doubling its size)
		delete [] numbers;
		numbers = newNumbers;
	}
}
void VectorDouble::popback()
{
	// Makes sure element exists
	if (count != 0)
	{
		numbers[count] = 0;
		--count;

	}
	else 
	{
		cout << "ERR: Cant push_back item that doesn't exitst";
	}
}