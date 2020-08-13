#include <iostream>
#include <string>
#include <array>
#include <regex>
#include <thread>

#include "../courseNamespace.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;      
using std::regex;
using std::thread;	         

using namespace courseNamespace;

using std::shared_ptr;
class Node
{
private:
	int num;
	shared_ptr<Node> next;  //WB-1.1
public:
	Node();
	~Node();
	Node(int num, shared_ptr<Node> nextPtr);
	// Shared pointers can be used as parameters0
	int getNum();
	shared_ptr<Node> getNext(); 
	// Shared pointers can be returned
	void setNext(shared_ptr<Node> nextPtr);
};


void helloWorld(int a);

int main(int argc, char const *argv[])
{
	print("Chapter 18: Standard Template Library and C++11");
	print("Ch18.4- C++ is evolving\n");

	print("\nYou can go to ", "https://isocpp.org/", " to see C++ changes");
	//https://isocpp.org/
	print("Changes are proposed by the international organization of standards (ISO)");


	//-STANDARD ARRAY-

	int arr[4] = {4, 3, 2, 1};
	// Does not require #include array and using std::array

	array<int, 4> stdArr = {4, 3, 2, 1};
	// Requires #include array and using std::array

	print("\nIt is possible to make std::arrays");
	print("Declaring them is like declaring a vector or other container, "
		"but after the data type you add , arraySize");

	print("\nNormal array: char[10] charArray");
	print("\nSTD Array: array<char, 10> stdCharArray");
	print("The STD arr also requires you to include array and using std::array "
		"(Like other containers)");

	for (int i = 0; i < 4; ++i)
	{
		// cout << arr[i];
		// cout << stdArr[i];

		arr[i] = 0;
		stdArr[i] = 0;
	}

	int arraySize;
	// arraySize = arr.size();  // Regular arrays don't have access to size
	arraySize = stdArr.size();

	print("\nRegular arrays can't use .size()");
	print("Like vectors, std::arrays have access to .size()");

	// array<int, 6> halfInitializedSTD = {1, 2, 3};
	// This initializes to 1, 2, 3, 0, 0, 0
	int halfInitialized[6] = {1, 2, 3};
	// This initializes to 1, 2, 3, unknown, unknown, unknown

	print("\nWhen half filling an array with elements,"
		" the unfilled values will be 0: ", halfInitialized[3]);
	// print("When half filling an std::array with elements,"
		// " the unfilled values will be 0: ", halfInitializedSTD[3]);

	for (int element : arr)
	{

	}
	for (int element : stdArr)
	{

	}

	// for(auto i = stdArr.begin(); i < stdArr.end(); ++i)
	// {

	// }
	for(auto i = stdArr.begin(); i < stdArr.end(); ++i)
	{

	}

	print("\nBoth arrays can do range based for loops"
		"for(auto element : arr)");
	print("Only std::arrays can do iterator for loops"
		"for(auto i = arr.begin(); i < arr.end(); ++i");


	// -REGULAR EXPRESSION-
	print("\nC++11 also added regex (regular expression)");
	print("Make sure to include <regex> and using std::regex");
	// NOT SUPPORTED BY ALL COMPLILERS

	print("Regular expression meaning:");
	print("  letter/digit- must be same letter or digit");
	//abc123 must be abc123
	print("  .- matches any single character");
	print("  |- union or logical or");
	print("  R?- regular expression R appears 0 or 1 time");
	// aA? matches aA and a
	print("  R+- regular expression R appears 1 or more times consecutively");
	// aA+ matches aA and aAAAAAAA...
	print("  R*- regular expression R appears 0 or more times consecutively");
	// aA* matches a aA and aAAAAAA...
	print("  R{n}- regular expression R appears N times consecutively");
	// aA{4} matches aAAAA
	print("  R{n,m}- Regular expression R appears N to M times consecutively");
	// aA{2,4} matches aAA aAAA and aAAAA
	print("  ^- beginning of text");
	print("  $- end of text");
	print("  [list of elements]- matches any of the listed elements");
	//a[AB1] matches aA aB and a1
	print("  [startElement-endElement]- matches elements between start and end");
	//[a-zA-Z] matches any upper or lower case letter
	//[0-9] matches any number
	print(" ()- precedence/expression grouping");
	// Like regular parentheses

	//EX: a{3}b{3} aaaBBB
	//[a-z]+[a-zA-Z0-9_]* 1 or more undercase letters and 0 or more letter,number, or underscore abc, abc1, aBC1111

	// ignore the second backslash \d isnt allowed but \\d is in strings
	print("  \\d- any digit");
	print("  \\D- any nondigit");
	print("  \\s- any whitespace");
	//tab, newline, space
	print("  \\w- any word character");

	// R"(\(?\d{3}\)?[- ]\d{3}[- ]\d{4})"
	// phone number
	// works with (555) 555 5555
	//			  (555)-555-5555
	//			   555-555-5555
	//             555 555 5555

	string phonePattern = R"(\(?\d{3}\)?[- ]\d{3}[- ]\d{4})";
	//Much more complex phone number regex

	// string phonePattern = R"(\d{3}-\d{3}-\d{4})";
	// simple regex given by the book that only works with 555-555-5555 format
	regex regexPhone(phonePattern);

	std::array<string, 4> phoneTests = {"(555) 555 5555", "(555)-555-5555", "555-555-5555", "555 555 5555"};
	
	for(int i = 0; i < phoneTests.size(); ++i)
	{
		if(regex_match(phoneTests[i], regexPhone))
		{
			cout << "Match " << i + 1 << "   ";
		}
	}

	print("\nTo create a regular expression check, create a string");
	print("The string should have R\"()\" where whatever is in () is the regex");
	// This means the R will be outside of the string's parentheses
	print("Then have regex regexName(stringName), this creates the regex");
	print("To check it, you can use regex_match(testString, regexName)");
	print("It regex_match returns a boolean if they match");

	// Simpler example than above

	string regexString = R"([A-Z][a-z]*)";
	// 1 uppercase letter followed by 0-inf lowercase letters
	regex regexPattern(regexString);
	if (regex_match("Hunter", regexPattern))
	{
		print("\nRegex can be simple");
	}

	// -THREADS-

	print("\nThreads are sperate computation processes");
	print("C++ allows multithreads");
	print("This means programs can compute in parallel");
	print("In some situations with computers without enough processors, "
		 "the computer might switch between threads using each a little, appearing to be parallel");

	print("\nOperating systems use multiple threads letting you multitask");
	//For example, running a virus scan while checking an email
	// Oftentimes though, they just take turns sharing resources appearing to be parallel but not actually
	// It will slow down the computer if too many resources are used

	print("You can use multi threads by computing something else while waiting for imput");
	print("Also useful when you need extra speed");
	print("When GPU programming, you can have hundreds of thousands of threads");

	print("\nWhen doing threaded programming make sure to include <thread> and using std::thread");

	// Uncomment to view multithreaded version (Linux users must follow note when compiling)
	// thread t1(helloWorld, 5);
	// thread t2(helloWorld, 10);

	// t1.join();
	// t2.join();
	// Uncomment up to here
	print("\nIn this example, 2 different threads run the helloWorld function");
	print("Each thread has its own unique ID");
	print("When a thread starts, there is no control over when it runs");
	
	print("\nThe join makes the the program wait for the thread to finish");
	print("Mutex- mutual exclusion- another function that can be used with threads "
		"to prevent them from overwriting each other");
	print("It locks the thread so only one can enter a region  of code at a time");

	print("\nIts also possible to make an array of threads");

	// thread tArr[10];
	// for (int i = 0; i < 10; ++i)
	// {
	// 	tArr[i] = thread(helloWorld, i);
	// }
	// for (int i = 0; i < 10; ++i)
	// {
	// 	tArr[i].join();
	// }

	print("You can even run a calss in a thread");

	// Employee tim(10);
	// Employee kyle(20);

	// thread t1(tim);
	// thread t2(kyle);

	// t1.join();
	// t2.join();

	print("\nNOTE FOR LINUX USERS");
	print("If you use g++ you must type -pthread after the g++ when multithreading");
	print("So to compile this, you would have to type g++ -pthread Ch18.4.cpp -o Ch18.4");
	print("The reason you need to do this is the thread library may not be linked by default");


	// -SMART POINTERS-
	
	print("\nC++11 also adds pointers that simplify memory management");
	print("Before you could have dangling pointrs or memory leaks");

	std::shared_ptr<int> sp;
	// No include or using requied

	print("\nReference Counting- tracks how many other pointers reference the object");
	print("It is used by the shared_ptr wrapper");
	print("Each time a new variable references the object it incraments "
		"and whenever it is no longer referenced it decrements");
	print("If the counter is at 0, the object can be deleted");


	print("Chapter Summary:");
	print("  An iterator is a generalized pointer and can use ++ and -- to move "
		"and * to dereference");
	print("Container classes with iterators have .begin() to access the first element "
		"and .end() to access a flag for the last element");
	print("The main iterator types are forward (++), bidirectional(++, --), "
		"and random access (++, --, [x])");
	print("const_iterator can make read only iterators");
	print("Bidirectional iterators have reverse iterators, that let you cycle through backwards");
	print("The main container template classes in STL are list (mutable bidirectional iterators), "
		"vector, and deque (mutable random access iterators)");
	print("Stacke and queue are container adaptor classes, and are built on other container classes,"
		" stacks are FILO and queues are FIFO");
	print("Set, map, multiset, and multimap container template classes store in sorted order" 
		" which allow more efficient search algorithms");
	// Maps allow storing and retrieving by key values, each key can only appear once
	// Sets are just simple collections of elements, each value can only appear once
	// Multimaps and multisets allow you to have repeats of the same key
	print("STL includes template functions to implement generic algorithms "
		"with guaranteed maximum running times");
	print("std::array, regular expressions, multithreading, and smart pointers "
		"are all tools added to C++11");
	
	return 0;
}
// Threads

void helloWorld(int a)
{
	cout << "Hello World " << a << " " << std::this_thread::get_id() << endl;
}


// Shared Ptr

Node::Node() : num(0), next(nullptr)
{

}
Node::~Node()
{
	cout << "Deleting " << num << endl;
}
Node::Node(int numVal, shared_ptr<Node> nextPtr) : num(numVal), next(nextPtr)
{ 

}
int Node::getNum()
{
	return num;
}

shared_ptr<Node> Node::getNext()
{
	return next;
}
void Node::setNext(shared_ptr<Node> nextPtr)
{
	next = nextPtr;
}
void listTest()  //WB-1.
{
	shared_ptr<Node> root(new Node(10, nullptr));
	shared_ptr<Node> next1(new Node(20, nullptr));
	shared_ptr<Node> next2;
	// After a shared_ptr is declared we can set it using the reset function

	next2.reset(new Node(30, nullptr));
	// Link the nodes together

	root->setNext(next1);
	next1->setNext(next2);
	// Output the list

	shared_ptr<Node> temp;
	temp = root;

	while (temp != nullptr)
	{
		cout << temp->getNum() << endl;
		temp = temp->getNext();
	}
}
