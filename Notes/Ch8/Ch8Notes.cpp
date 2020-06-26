#include<iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

void anArrayTypeForStrings();
void theStandardStringClass();
void vectors();

int main() 
{
	cout << "Chapter 8- Strings and Vectors\n";
	// anArrayTypeForStrings();
	// theStandardStringClass();
	vectors();

	cout << endl;
	return 0;
}

void anArrayTypeForStrings() // THis is shit, just avoid just about the entire thing
{
	cout << "8.1: An Array Type for Strings\n\n";
	
	cout << "A string is just an array of chars\n";
	char charArray[5] = {'t','e','s','t'};   // (cstring)\0 is a null characters
		// C++ stores null characters at the end of a string to show when it ends
	string strings = "test";
		// C++ stores strings as arrays of chars
	// cout << charArray << "  " << strings << endl;

	cout << "C-String variable- just an array of characters \n";
		// They are only partially filled, allowing you to add on to the end of them ('\0') helps know where to add
		// The only difference from a normal partially filled array is they must have null character at the end
	strings += " part 2";
	cout << strings << " You can add to a string with +=\n";

	// Because a string has a null character at the end, they are not equivalent to an array of characters

	int index = 0;
	while (strings[index] != '\0')  // Without the check, it might change a large amount of memory unwantedly
	{
		strings[index] = 'X';
		++index;
	}
	cout << "Important: Make sure with while looping through a string not to loop on the '\\0'\n";

	strings = "test"; 
	string strings2 = "te1st";
	cout << !strings.compare(strings2) << " Way to compare without == but returns true when they DONT equal\n"; // Cant do

	// cout << compare(strings, strings2);

	char aString[10];  // Old C way
	strcpy(aString, "Hello");  // Old versions of C++ require you to do this to change an arrayString
	strncpy(aString, "Hello", 9); // This is a safe version that only puts up to 9 variables in
		// Without it, you can exceed the strings length and ruin other data
		// Leave one character for \0

	char aString2[10] = "Hello";
	if (strcmp(aString, aString2))  // Old  C way (strcmp and strcpy dont work with regular strins)
		cout << "The strings are NOT the same.\n";  // Both require the cstring library, NOT the string library
	else
		cout << "The strings are the same.\n";

	cout << "Lexographical Order is the relationship used to compare characters \n";
		// Just alphabetical if both characters are the same case (both are upper or lower)

	// Pg 493 has a chart of all the (awful) cstring functions and how to use them

	cout <<aString << endl;
	// cin >> aString;  // You can cin/cout cstrings  

	// char shortString[5];
	// cout << "Enter some input:\n";
	// cin.getline(shortString, 5);  // You should use getline to limit the amount of imput to fit the array
	// cout << shortString << "END OF OUTPUT\n";  // This reads 4 NOT 5 imputs (5 is '\0')

	// In C++ "'123" != 123

	int num = 123;
	string str = "123";
	if(atoi("123") == num)
		cout << "The string " << str << " is converted to a num with atoi\n" ;
	else 
		cout << "It is shit and didn't work\n";
}

void theStandardStringClass() 
{
	cout << "8.2: The Standard String Class\n\n";

	cout << "Make sure to include string\n";
	cout << "Using regular strings let you treat strings like a regular primative type\n";

	string test("testy");  // You can apparently assign to a string like this also (interesting I guess)
		// The string testy is originally cstring that is converted to a regular string and stored in test
	cout << test << endl;

	string noun = "C++";
	string adjective = "shitty";
	string phrase = "I love " + adjective + " " + noun + "!";
	cout << phrase << endl;
	// string phrase = "I love " + "concatonating" + " " + "strings" + "!"; // Doesn't work, cant concatonate string to a string without using vars
		// When concatonating cstring and string + is overloaded
		// Using 2 cstrings causes an error, because it isn't possible with overloading

	// cin/cout work with strings

	string sentence = "Cin is stupid";
	string newStr;
	// string >> newStr;  // Doesn't work sadly
	cout << newStr;
		// C++ strings are originally set to empty, so printing it will print nothing

	cout << "Remember, extraction (>>) stops at whitespace\n";
	// string line;
	// cout << "Enter a line of input:\n";
	// getline(cin, line);
	// cout << line << "END OF OUTPUT\n";  // remember: Best way to get line of input

	// int n;
	// string line;
	// cin >> n;
	// cin.clear();  // Remember: ADD IGNORE AND CLEAR WHILE MIXING CIN AND GETLINE
	// cin.ignore(1000, '\n');
	// getline(cin, line);

	cout << "Any operation that works on cstrings works on strings, but strings have added operations\n";
	cout << phrase.length() << " Length is one important addition\n";

	string lastName = "jones";
	cout << "Your last name is ";
	for (int i = lastName.length(); i > -1; --i) 
	{
		cout << lastName[i];
	}
	cout << " backwards\n";

	// Using length helps make sure everything remains inbounds from an illegal index

	string str1 = "ree"; string str2 = "ree";
	if (str1 == str2)
		cout << "Strings can be compared with ==" << endl;
	else 
		cout << false << endl;

	if ("a" >  "b")
		cout << true << endl;
	else 
		cout << "Strings can also use > < >+ <= and Lexographically be sorted (z > a)\n";

	// Pg 517 has a good chart on accessors assignments, comparisons, and find

	cout << "e occurs first at " << str1.find("e") << endl;
		// You can also add another parameter to start part way through the string
}

void vectors() 
{
	cout << "8.3: Vectors \n\n";

	vector<int> numbers; // This creates a vector vector<DATATYPE> NAME;
	numbers.push_back(4);
	numbers.push_back(8);
	numbers.push_back(12); // With vectors you use push_back to append
	numbers.push_back(1);
	numbers.pop_back(); // This removes the last element

	cout << "Template Class- A class that lets you plug in any basetype class";
		// Vectors are an example of this
		// Anything that uses DATATYPE> is a template class


	cout << "You can loop thorugh them like an array, except they use size() instead of length()";
	cout << "This vector includes: ";
	for (int i = 0; i < numbers.size(); ++i) 
	{
		cout << numbers[i] << " ";
	}
	cout << endl;


	cout << "You can also modify vectors like arrays with [] as long as there is an element already psuhed to the index";
	cout << "This vector now includes: ";
	for (int i = 0; i < numbers.size(); ++i) 
	{
		numbers[i] = (i + 1) * 31;
		cout << numbers[i] << " ";
	}
	cout << endl << "YOU CANNOT INITIALIZE AN ELEMENT WITH [], YOU MUST PUSH_BACK TO INITIALIZE THE NTH ELEMENT\n";

	vector<string> words = {"You", "can", "have", "vectors", "of"};
		// You can have strings as vector elements
		// You can also initialize a vector with {}
	words.push_back("strings");

	for (int i = 0; i < words.size(); ++i)
	{
		cout << words[i] << " ";
	} 
	cout << endl;

	cout << "Ranged based for loops work (Not on strings apparetly\n";
	for (int i : numbers)
	{
		cout << i << " ";
	} 
	cout << endl;

	vector<double> numbers2(24); 

	cout <<  "Adding (#) lets you preinitialize # elements\n";
	int c = 0; 
	for (int i :numbers2)
	{
		++c; // (YOu should use a regular floop if you have a counter, but just a demonstration)
		numbers2[i] = c/10.0;
		cout << numbers2[i] << " ";
	}
	cout << endl;


	// vector<long long>fibbonachi;
	// fibbonachi.push_back(1);
	// fibbonachi.push_back(1);
	// while(true)
	// {
	// 	long long newNum = fibbonachi[fibbonachi.size() - 2] + fibbonachi[fibbonachi.size() - 1];
	// 	cout << newNum << endl;
	// 	fibbonachi.push_back(newNum);
	// 	cin.get();
	// }

	// setting a vector v[i] where i is past v.size() may result in a segmentation error, or it might cause other problems without alerting you

	cout << "Capacity- Number of elements which memory allocated for a vector";

	cout << "The capacity of the vector numbers is" <<  numbers.capacity() << " but the size is " << numbers.size() << endl;
		// Capacity is always greater than size
		// Whenever size passes capacity, more memory is allocated and the capacity increases
		// If you constantly have to increase capacity of a vector, it will have efficiency issues but will run fine
	
	cout << "Not paying attention to vector capacity and constantly allocating more memory is inefficient\n";
	numbers.reserve(32); 
	cout << "After manually reserving space, the capacity of the vector numbers is " <<  numbers.capacity() << " but the size is " << numbers.size() << endl;
	numbers.reserve(numbers.size() * 10); // You can even do stuff like this
		// This reserves 10x the space instead of 2x
	numbers.reserve(numbers.size() + 10);
		// You can also do something like this to reserve a lot less space

	vector<int> numbers3(100);
	cout << "Declaring a vector with (100) sets the capacit " <<  numbers3.capacity() << " and the size is " << numbers3.size() << endl;
	numbers3.push_back(1);
	cout << "Pushing back one element to the previous array sets the capacity " <<  numbers3.capacity() << " and the size is " << numbers3.size() << endl;	
		// Shows that it automatically reserves 2x the amount of room each time
}