#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

int main(int argc, char const *argv[])
{
	print("Chapter 18: Standard  Template Library and C++11");
	print("Ch 18.3- Generic Algorithms\n");

	print("\nGeneric algorithms- basic templates in the STL");
	print("Remember, algorithms are just sets of instructions to perform a task");
	//IMPORTANT
	print("STL Algorithms are called generic algorithms becuse the STL provides some details "
		"but abstracts unimportant information");
	print("The interface tells programmers running conditions and worst runtime (O(n))");
	print("Sometimes the interface will mention the specific algorithm used");
	print("Generic algorithm, generic function, and STL function template "
		"all mean the same thing");

	print("\nBig-O Notation is used to measure program speed");
	print("Is useful because some algorithms are faster with less data than more");

	print("\nFunction- table with how many data points and how long the program takes to run");
	// EX method 1:
	// 10 numbers: 		2 seconds
	// 100 numbers: 	2.1 seconds
	// 1000 numbers:	10 seconds
	// 10000 numbers: 	2.5 minutes
	// EX method 2:
	print("Can be written as EX: T(10) = 2sec, T(100) = 2.1sec, T(1,000) = 10sec, T(10,000) = 2.5min");
	print("T(N) = x where T is running time, and N is the number of values");

	print("\nSometimes an algorithm will have a shortest and worst running time");
	print("For example, in a indexOf function, if the key is the first element in an array, "
		"it only runs through 1 element (best case), but if the key is the last element, "
		"or the element doesn't exist it will run through the entire array (worst case)");
	print("Programmers mainly just care about worst time");

	print("\nIt is much less quantifiable to count the number of steps a program uses, "
		"but it is possible to measure operations");
	print("Operation- =, <, &&, !, [], ==, ++");
	// Things other than these don't take much time at all

	print("\nBecause calculating operations is time consuming, "
		"programmers use Big-O Notation to generalize it");
	print("If a program takes 6N + 5 steps, big-O would just be O(N)");
	print("N is the number of elements");
	print("Big-O always measures the worst case upper bound");
	print("Only the multiplier 1, constant, squared, cubed, etc is necessary");
	// N^2 + 2N + 1, 	3N^2 + 7, 	100N^2 + N 		all equal O(N^2) 
	// N^3 + 5N^2 + N + 1,	 8N^3 + 7,	100N^3 + 4N + 1		all equal O(N^3)

	print("\nLinear running time- O(N)");
	print("Quadratic running time- O(N^2)");
	print("Its also possible to have logs in running time");
	print("Logs are in base 2 and may be written like O(logN) or O(lgN)");
	print("Logs grow very slow, so O(lgN) is very fast");

	print("\npushing to the back of a vector, pushing to the front or back of a deque, "
		"and inserting anywhere in a list is O(N)");
	print("Inserting or deletion in a vector or deque is O(N)");
	print("Find in a set or map i s O(lgN)");

	// SELF TEST START

	// 17. Show that a running time T(N) = aN + b is an O(N) running time. (Hint:
	// The only issue is the + b. Assume N is always at least 1.)

	// In Big-O Notation, aN + b, 
	// you remove the coefficients: N + b
	// you only keep the highest degree: N
	// O(N)

	// 18. Show that for any two bases a and b for logarithms, if a and b are both
	// greater than 1, then there is a constant c such that log a N ≤ c(log b N). Thus,
	// there is no need to specify a base in O(log N) that is, O(log a N) and O(log b
	// N) mean the same thing.

	// log a(N) = T equals   a^T = N
	// Big-O simplifies it and doesn't care about coefficients
	// so a^T = N is the same as b^T = N

	// SELF TEST END

	print("\nThere are nonmodifying sequence algorithms");
	print("These are generic template functions that operate on containers but don't modify "
		"what is inside of them");
	print("One example is the generic find function");
	print("It is similar to the find member function of sets, but takes more arguments");

	// need to include vector and algorithm
	{
		using std::vector;
		using std::find;

		vector<int> v;
		for (int i = 10; i > 0; i -= 2)
		{
			v.push_back(i);
		}

		vector<int>::iterator itt = find(v.begin(), v.end(), 6);

		print("\nThe generic find function takes "
			"the first element to search, the last element to search, and the key");
		print("It returns an itterator for the key's location: ", &itt, " ", *itt);
		print("You can use container.begin() and container.end() if you want to search "
			"the entire array");

		for(auto i = v.begin(); i != v.end(); ++i)
		{
			itt = find(v.begin(), i, 10);
		}

		print("\nYou can also have an itterator set to a value to not search the entire array");
		print("The ranges must be in the same container");

		print("\nFind doesn't work with every container type");
		print("The container must have a forward itterator (or a stronger bidirectional/ RA)");
	}

	print("Range[first, last)- goes from ( [ )container.begin "
		"to but not including ( ) ) container.end ");
	print("(Loops throught the entire array)");

	// Other generic algorithms found below

	print("\nThere are 3 generic search functions: find, search, and binary search");
	print("Find can be for subsequences, while search and bsearch are only for individual values");
	print("Search and bsearch return bools while search returns an iterator");
	print("Binary search is more efficient than search but requires a sorted array");
	
	// SELF TEST START

	// 20 Suppose v is an object of the class vector<int> . Use the search generic
	// function (Display 18.18) to write some code to determine whether or
	// not v contains the number 42 immediately followed by 43 . You need not
	// give a complete program, but do give all necessary include and using
	// directives. (Hint: It may help to use a second vector.)

	{
		using std::vector;
		using std::find;

		vector<int> v;
		for (int i = 0; i < 50; ++i)
		{
			v.push_back(i);
		}

		vector<int>::iterator index42 = find(v.begin(), v.end(), 42);
		vector<int>::iterator index43 = find(v.begin(), v.end(), 43);
		std::vector<int>::iterator pattern = search(v.begin(), v.end(), index42, index43);

		if(pattern == v.end())
		{
			print("false");
		}
		else
		{
			print("true");
		}
	}

	// SELF TEST END

	print("\nThere are also generic algorithms used to modify the container's data");
	print("Some of them can't guarantee that any iterators will point to the correct place after");

	// SELF TEST START

	// 21. Can you use the random_shuffle template function with a list container?
	// No because it only has a bidirectional iterator
		
	// 22. Can you use the copy template function with vector containers, even
	// though copy requires forward iterators and vector has random access
	// iterators?

	// Yes, because RA iterators can do anything a bidirectional iterator or forward iterator
	// can do 

	// SELF TEST END

	print("\nThere are also algorithms which apply only to set containers with sorted order");
	print("These are set algorithms");
	print("They only work on sets, maps, multisets, and multimaps");

	// SELF TEST START

	// 23. The mathematics course version of a set does not keep its elements in
	// sorted order and it has a union operator. Why does the set_union template
	// function require that the containers keep their elements in sorted order?
	// It needs to be sorted so the algorithm is efficient

	// SELF TEST END

	print("\nThere are also 2 sorting algorithms");
	print("It is impossible for a comparison-based sort algorithm to be faster than O(N logN)");


	return 0;
}
// ---GENERIC ALGORITHMS---


//-NONMODIFYING SEQUENCE ALGORITHMS-

template<class ForwardIterator, class T>
ForwardIterator find(ForwardIterator first, ForwardIterator last, const T& target);
//Traverses the range [first, last) and returns an iterator located at
//the first occurrence of target. Returns second if target is not found.
//Time complexity: linear in the size of the range [first, last).

 template<class ForwardIterator, class T>
int count(ForwardIterator first, ForwardIterator last, const T& target);
//Traverses the range [first, last) and returns the number
//of elements equal to target.
//Time complexity: linear in the size of the range [first, last).

template<class ForwardIterator1, class ForwardIterator2>
bool equal(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);
//Returns true if [first1, last1) contains the same elements in the same order as
//the first last1-first1 elements starting at first2. Otherwise, returns false.
//Time complexity: linear in the size of the range [first, last).

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
//Checks to see if [first2, last2) is a subrange of [first1, last1).
//If so, it returns an iterator located in [first1, last1) at the start of
//the first match. Returns last1 if a match is not found.
//Time complexity: quadratic in the size of the range [first1, last1).

template<class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& target);
//Precondition: The range [first, last) is sorted into ascending order using <.
//Uses the binary search algorithm to determine if target is in the range
//[first, last).
//Time complexity: For random access iterators O(log N). For non-random-access
//iterators
//linear is N, where N is the size of the range [first, last).



// -CONTAINTER MODIFYING ALGORITHMS-

template<class T>
void swap(T& variable1, T& variable2);
//Interchanges the values of variable1 and variable2

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 copy(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
//Precondition: The ranges [first1, last1) and [first2, last2) are the same size.
//Action: Copies the elements at locations [first1, last1) to locations
//[first2, last2).
//Returns last2.
//Time complexity: linear in the size of the range [first1, last1).

template<class ForwardIterator, class T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last,
const T& target);
//Removes those elements equal to target from the range [first, last).
//The size of
//the container is not changed. The removed values equal to target are
//moved to the
//end of the range [first, last). There is then an iterator i in this
//range such that
//all the values not equal to target are in [first, i). This i is returned.
//Time complexity: linear in the size of the range [first, last).

template<class BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last);
//Reverses the order of the elements in the range [first, last).
//Time complexity: linear in the size of the range [first, last).

template<class RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);
//Uses a pseudorandom number generator to randomly reorder the elements
//in the range [first, last).
//Time complexity: linear in the size of the range [first, last).

// -SET ALGORITHMS- 

template<class ForwardIterator1, class ForwardIterator2>
bool includes(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
//Returns true if every element in the range [first2, last2) also occurs in the
//range [first1, last1). Otherwise, returns false.
//Time complexity: linear in the size of [first1, last1) plus [first2, last2).

template<class ForwardIterator1, class ForwardIterator2, class ForwardIterator3>
void set_union(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, ForwardIterator3 result);
//Creates a sorted union of the two ranges [first1, last1) and [first2, last2).
//The union is stored starting at result.
//Time complexity: linear in the size of [first1, last1) plus [first2, last2).

template<class ForwardIterator1, class ForwardIterator2,
class ForwardIterator3>
void set_intersection(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, ForwardIterator3 result);
//Creates a sorted intersection of the two ranges [first1, last1) and
//[first2, last2).
//The intersection is stored starting at result.
//Time complexity: linear in the size of [first1, last1) plus [first2, last2).

template<class ForwardIterator1, class ForwardIterator2, class ForwardIterator3>
void set_difference(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, ForwardIterator3 result);
//Creates a sorted set difference of the two ranges [first1, last1) and
//[first2, last2).
//The difference consists of the elements in the first range that are not in the
//second.
//The result is stored starting at result.
//Time complexity: linear in the size of [first1, last1) plus [first2, last2).

// -SORTING ALGORITHMS-

template<class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);
//Sorts the elements in the range [first, last) into ascending order.
//Time complexity: O(N log N), where N is the size of the range [first, last).

template<class ForwardIterator1,class ForwardIterator2, class ForwardIterator3>
void merge(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, ForwardIterator3 result);
//Precondition: The ranges [first1, last1) and [first2, last2) are sorted.
//Action: Merges the two ranges into a sorted range [result, last3), where
//last3 = result + (last1 − first1) + (last2 − first2).
//Time complexity: linear in the size of the range [first1, last1)
//plus the size of [first2, last2).