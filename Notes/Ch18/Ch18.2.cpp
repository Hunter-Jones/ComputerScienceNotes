#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../courseNamespace.h"
#include <set>
#include <map>

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

int main(int argc, char const *argv[])
{
	print("Chapter 18: Standard Template Library and C++11");
	print("Ch 18.1- Containers\n");

	print("\nContainer class- data structures that hold data");
	print("Lists, queues and stacks are all examples");
	print("Each container template has a parameter for the type (int, char, etc)");
	print("Each can have its own special accessor/mutator functions to add/remove data");
	print("Each has different kinds of iterators (ex forward_iterators)");
	print("begin() and end() behaves the same for all STL container classes");	

	std::list<int> a;  // double linked list
	// has a pointer to the last element allowing it to go backwards
	// std::slist <int> b;  // single linked list
	// only goes forwards
	// not in g++

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	// b.push_back(5);

	auto p = a.begin();
	print("\nYou can use iterators with other container classes: ", *p);

	print("\nSingly liked lists- one link linked lists that can only go forwards");
	// slist
	print("Doubly linked list- 2 link linked list allowing it to go forwards and backwards");
	// list

	print("\nIterators allow you to use ++ and -- instead of -> to traverse a linked list");
	print("Lists use biderectional iterators (not random access)");
	// Means if you want to move from 1-5 you cant just go to 5 and have to take 5 steps
	print("Slists use forward iterators");

	print("\nDeque (pronounced d-queue or deck)- double ended queue");
	print("Decks are a type of superqueue");
	print("Unlike queues which have forward iterators, they use bidirectional iterators");
	print("You can add or remove elements at either end, "
		"instead of just removing front and adding to the back");

	print("\nWhen you remove an element from a container, it might affect any associated iterator");
	print("Some containers guarantee addition and deletion wont move a iterator "
		"unless it points the removed element");

	print("\nRememeber- iterators: iterator, const_iterator reverse_iterator, const_reverse_iterator");
	print("All template classes so far have value_type and size_type");

	// SELF TEST START

	// 7. What is a major difference between a vector and a list ?
	// // Lists are sequential and use bidirectional iterators, 
	// // vectors use random access iterators
	// 8. Which of the template classes slist , list , vector , and deque have the
	// member function push_back ?
	// // list, vector, deque
	// 9. Which of the template classes slist , list , vector , and deque have
	// random access iterators?
	// // vector, deque
	// 10. Which of the template classes slist , list , vector , and deque can have
	// mutable iterators?
	// all

	// SELF TEST END

	print("\nContainer adapters are template classes that can be implemented on other classes");
	print("For example the stack template class can is implemented on top of the deque template class");
	print("Other examples are queues and priority_queue");
	
	print("\nPriorety Queue- a queue where each item is given a priorety when added");
	print("If there are 2 different priorety, the higher priorety is removed first");
	print("Otherwise it functions like a regular queue");

	print("\nAny sequential container can be the underlying containerfor a queue");

	// SELF TEST START

	// 11. What kind of iterators (forward, bidirectional, or random access) does the
	// stack template adapter class have?
	// // no iterator

	// 12. What kind of iterators (forward, bidirectional, or random access) does the
	// queue template adapter class have?
	// // no iterator

	// 13. If s is a stack<char> , what is the type of the returned value of
	// s.pop()?
	// // void
	
	// SELF TEST END

	print("\nAssociative containers- simple databases");
	print("They store data types like structs or any other data type");
	print("Each piece of data has a key");
	print("For example, if the data is employees, the key may be social security numbers");
	print("Items are retrieved based on the key");
	print("The key type and the data type should have a relationship to each other");

	print("\nSets are associative containers to store data without repetition");
	print("If you try to insert an element already in a set, it will have no effect");
	print("Each element in a set is its own key");
	print("Sets also sort the elements while added");
	std::set<int> bestNumbers;

	bestNumbers.insert(4);
	bestNumbers.insert(8);  
	bestNumbers.insert(5);  // Will sort least to greatest
	bestNumbers.insert(4);  // Will not be added, since 4 was already added once

	for(auto i = bestNumbers.begin(); i != bestNumbers.end(); ++i)
	{
		print(*i);
	}

	print("\nAnother associative container is a map");
	print("Maps- function given to a set of order pairs");
	print("The first value in a pair is the key and the second is the value");
	print("LIke sets, maps are sorted based on the key");

	print("Associative array- a traditional array maps values to index, "
		"an associative array maps values to keys");
	print("Associative arrays let you choose the indices and their data type");
	print("Maps are an associative array");
	print("When you call arr[4] it takes the key for the 4th element and accesses the value");
	print("You can use a map like mapName[key] to access the value associated with the specific key");
	print("You can also use that to add elements");

	std::map<long, string> employees;
	//social security number, name

	employees[2335559034] = "Tim";
	employees[5532456432] =  "Rob";
	employees[5532456432] = "Chris"; // This would overwrite Rob
	employees[1889356643] = "Tim";
	// You can have 2 values the same, but not 2 keys


	for(auto i = employees.begin(); i != employees.end(); ++i)
	{
		print("Employee number: ", i->first, ", ", i->second);
	}

	print("\nWith maps, iterator->first accesses the key, and iterator->second accesses the value");
	print("Trying to print *iterator will give an error");

	for(auto i: employees)
	{
		print("Employee number: ", i.first, ", ", i.second);
	}
	for(auto i: bestNumbers)
	{
		print(i);
	}

	print("\nTo simplify looping through containers, you can use a range based for loop");
	print("Just type auto i: containerName");
	print("Ex: for(auto i: employees)");
	print("For maps you can access the key with i.first and value with i.second (not ->)");
	print("Otherwise, you can just access the value with i");

	print("The STL was designed to be efficient");
	print("Each template class has a guaranteed max running time in big-O notation");

	//SELF TEST START

	// 14. How many elements will be in the map mymap after the following code is
	// executed?
	// map<int, string> myMap;
	// myMap[5] = "c++";
	// cout << myMap[4] << endl;
	// // 2
	// // one maps mymap[5] to c++
	// // and on that maps mymap[4] to the default string (blank)

	// 15. Can a set have elements of a class type?
	// // yeah

	// 16. Suppose s is of the type set<char> . What value is returned by s.find('A')
	// if 'A' is in s ? What value is returned if 'A' is not in s ?
	// // iterator
	// // end()

	// SELF TEST END

	return 0;
}