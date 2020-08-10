#include <iostream>
#include <string>
#include <vector>
#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

int main(int argc, char const *argv[])
{
	print("Chapter 18: Standard Library and C++11");
	print("Ch 18.1- Iterators\n");
	
	// using courseNamespace::print; 
	// print("");
	// courseNamespace::print("");
	print("\nAfter a using statement, 	adding the namespaceName::functionName does the same as "
		"just typing functionName");

	// using std::vector<int>::iterator;
	// Not working in G++
	// Apparently declaration changes between compilers 

	using std::vector;
	// using std::iterator;

	print("\nAfter you include it and add the using directive, you can create an iterator like "
		"any primative type");
	print("Iterators are defined in vector<int> which is defined in std");

	print("Iterator- generalized pointer");
	// Normally implemented as a pointer
	print("Like how each data type has its own pointer but they behave the same as dynamic variables");
	print("Each iterator behaves the same, but is only used in its own container class");

	print("\nIterators aren't pointers, but you can use it like a pointer");
	print("Like pointers, they point to a data entry in a container");

	print("Pointers can be manapulated with:");
	print("  prefix/postfix incrament operator (++) to advance to the next item");
	print("  prefix/postfix decrament operator (--) to move to the previous item");
	print("  equal and unequal operators (== !=) to test if 2 iterators point to the same value");
	//Not all have begin/end
	// Vector<int> does though
	print("  dereference operator (*) to access the value being pointed to");
	print("    depending on the container class it might be read or write locked");
	// *p
	print("  .begin() will return an iterator that points to the first item.data");
	// container.begin()
	print("  .end() tests if an iterator has gone passed its end");
	print("    like NULL for pointers");
	print("    .end() has no data and is used as an ending sentinel");

	std::vector<int> container;

	for(int i = 0; i < 3; ++i)  // Fill with meaningless data
	{
		container.push_back(i);
	}

	vector<int>::iterator p;  // Make iterator

	print();
	// Used to loop through the vector
	for(p = container.begin(); p != container.end(); p++)
	{
		print("Element: ", *p, " at ", &(*p), " from iterator at ", &p, " pointing to ", &container); 
	}
	// &p 			address of pointer
	// &(*p) 		address of value being pointed to 
	// &container 	address of container

	print("\nAn iterator is something that can located at an element in a vector");
	print("To loop through one:", "for(p = container.begin(); p != container.end(); ++p");

	std::vector<int>::iterator p1;
	std::vector<int>::iterator p2;
	p1 = container.begin();
	p2 = container.begin();
	print("\n==/!= can be used to compare iterators: ", p1 == p2);

	print("\nInstead of running until container.end, "
		"you can do any boolean expression with iterators");
	print("p != c.end() waits until p has passed the end to change the sentinel value");

	auto p3 = container.begin();
	// vs std::vector<int>::iterator p3; p3 = container.begin();
	print("\nAuto is much easier to use when declaring iterators");

	// Sets every value equal to 10x its original value
	for (p = container.begin(); p != container.end(); ++p)
	{
		*p *=10;
	}

	// SELF TEST START

	// 1. If v is a vector, what does v.begin() return? What does v.end() return?
	// v.begin- the address of the first value in the vector
	// v.end- a flag which checks if the iterator has passed the last value
		// like NULL

	// 2. If p is an iterator for a vector object v , what is *p ?
	// It represents the value of whatever address is being iterated on by p

	// 3. Suppose v is a vector of int s. Write a for loop that outputs all the
	// elements of v , except for the first element.
	// std::vector<int> s;
	// for(auto p7 = s.begin() + 1; p7 != s.end(); ++p7)
	// {
	// 	cout << *p7 << " ";
	// }

	// SELF TEST END

	print("\nAlthough iterators behave similarly, each container has its own iterator");
	print("Iterators are classified by what operations work with them");
	print("Vector iterators aree the most general form, so all operations work with them");

	print("\nDecrament operator (--)- behaves the same as the incrament operator, "
		"but backwards");
	// Dont know why the book felt like mentioning this but okay

	print("\nRandom Access- you can go to any element in one step");
	// to get to 10 from 1 with incramenting would take 9 steps
	// to use p[10] it would be one step, because it bypasses 2-9
	// and direcctly accesses 10 (random access)


	p = container.begin();
	print("\nYou can use [x] to access any element in a iterator");
	print("You can also use *(p + x)");
	print("All work the same: ", p[2], " ", *(p + 2), " ", container[2]);
	// p[2] is the same as container[2]
	print("All of these are examples of random access");

	print("\nUse incrament/decrament when you want to use the iterator forward");
	print("Use p[x] when you want to return a value without moving the iterator");

	print("\nIterators are classified by:");
	print("  Forward iterators0- only ++ works on them");
	print("  Bidirectional iterators- both ++ and -- work on them");
	print("  Random access iterators- ++, --, and random access ");

	print("\nRandom access  are the strongest iterators while forward are the weakest");
	print("The 3 classifications are not the same as type names");
	print("2 forward iterators for different containers would not work together for example");
	// ONLY SAME TYPE WORK TOGETHER

	// SELF TEST START

	// 4. Suppose the vector v contains the letters 'A' , 'B' , 'C' , and 'D' in that
	// order. What is the output of the following code?
	// vector<char>::iterator i = v.begin();
	// i++;
	// cout << *(i + 2) << " ";
	// i−−;
	// cout << i[2] << " ";
	// cout << *(i + 2) << " ";

	//D C C

	// SELF TEST END

	print("\nForward, biderectional, and random access iterators can be divided to 2 subcategories: ");
	print("  Constant iterators- dereferencing makes it read only");
	print("    This means you can't change the value being referenced");
	print("  Mutable iterator- can modify the asigned value");

	print("\nYou can't make a constant iterator mutable but you can make a mutable iterator constant");
	print("Make it a const_iterator not a iterator");

	// const auto p4 = container.begin(); // WRONG
	std::vector<int>::const_iterator cp;  // Right

	print("\nIf you want an iterator to go in reverse, setting it to container.end() wont work");
	print("It might work on some systems, "
		"but because container.end() isnt a regular iterator value it may cause problems");
	print("Instead of iterator use reverse_iterator");
	print("Then make the loop like normal but use rbegin instead of begin "
		"and rend instead of end");

	std::vector<int>::reverse_iterator rp;
	for(rp = container.rbegin(); rp != container.rend(); ++rp)
	{}

	print("\nRbegin returns the iterator at the last element");
	print("Rend returns a sentinel for the end of the reverse order array");
	print("In a reverse array, ++ goes backwards and -- goes forwards");
	print("  So when looping through a reverse array use ++ to go through");

	print("\nYou can even use const_reverse_array to make a constant reverse array");

	print("There are other random iterators you may encounter");
	// 2 examples of iterators not covered in the book
	print("Input iterator- forward iterator that can be used for input streams");
	print("Output iterator- forward iterator that can be used for output strems");

	// SELF TEST START

	// 5. Suppose the vector v contains the letters 'A' , 'B' , 'C' , and 'D' in that
	// order. What is the output of the following code?
	// vector<char>::reverse_iterator i = v.rbegin();
	// i++;
	// i++;
	// cout << *i << " ";
	// i−−;
	// cout << *i << " ";

	// // B C

	// 6. Suppose you want to run the following code, where v is a vector of int s:
	// for (p = v.begin(); p != v.end(); p++)
	// cout << *p << " ";
	// Which of the following are possible ways to declare p ?
	// std::vector<int>::iterator p;
	// std::vector<int>::const_iterator p;
	// Both work since a value inst changed

	// SELF TEST END

	
	return 0;	
}