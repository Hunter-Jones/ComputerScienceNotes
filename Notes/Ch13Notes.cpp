#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void nodesAndLinkedLists();
void stacksAndQueus();

namespace
{
	void print(string str)
	{
		cout << str << "\n";
	}
}

int main()
{
	print("---Chapter 13- Pointers and Linked Lists---");
	nodesAndLinkedLists();
	stacksAndQueus();
	return 0;
}

void nodesAndLinkedLists()
{
	print("\n--13.1: Nodes and Linked Lists--\n\n");

	print("Most dynamic memory isn't a simple type like int or double but instead  complex datatypes");
	print("Oftentimes they are dynamic arrays, structs, and classes");

	print("Nodes and pointers are structures with items with boxes drawn around them");
	print("The arrows are pointers");
	print("Node- boxes, represented by structs or classes");
	print("Each node has variables and a pointer");
	// CANT REALLY BE EXPLAINED WITHOUT A NODE AND POINTER DIAGRAM
	// https://www.google.com/url?sa=i&url=https%3A%2F%2Fpeople.engr.ncsu.edu%2Fefg%2F210%2Fs99%2FNotes%2FLinkedList.1.html&psig=AOvVaw0Pchu5eJB8ETbtkX0RI6C8&ust=1591821910202000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCKDyhI7N9ekCFQAAAAAdAAAAABAD

	struct ListNode
	{
		string item;
		int count = 3;
		ListNode *link;
	};
	typedef ListNode* ListNodePtr;  // could be removed and just have next line be ListNode* head
	ListNodePtr head;
	head = new ListNode;
	print("The code above is needed to create a linked list");

	print("\nThe head is not a node, but rather just a pointer that points to a node");

	print("To change the variable in the node, use (*head).MEMBER_VARIABLE = VALUE");
	// (*head).item = "cheese borger";
	// (*head).count = 2;
	// The parentheses around *head arent optional
	// Without the parentheses it would do head.count and then apply the dereference operator (*) to head.count
	// Which would give an error, because head is a pointer
	print("C++ also lets you simplify it to head->MEMBER_VARIABLE = VALUE");
	head->item = "french fries";
	print("These changes will modify ONLY the first node's member variables");

	print("\nThe last node's pointer should point to NULL");
	print("This signals an end marker");
	// Uses of NULL
		// Make pointer point to nothing
			// Prevents inadvertant referencing
		// The second use is an end marker
	print("If you use null as an end marker, the program will step through all the nodes until it reaches a node with NULL");
	// When NULL is used as a constant, it means 0
	// It is much better to use the word NULL than the number 0 
		// Using 0 would still work teqniquely

	print("\nTo use NULL you must include iostream or cstddef");
	print("It doesn't require a using directive");

	print("The arrow operator (->) specifies that something is pointed to by a pointer");
	// POINTER_VARIABLE->MEMBER_VARIABLE

	// head->link = NULL;
	head->link = new ListNode;
	head->link->item = "pizza";
	head->link->count = 5;
	head->link->link = new ListNode;
	head->link->link->item = "chicken tendies";
	head->link->link->count = 8;
	
}

void stacksAndQueus()
{
	print("\n--13.2: Stacks and Queues--\n\n");
}