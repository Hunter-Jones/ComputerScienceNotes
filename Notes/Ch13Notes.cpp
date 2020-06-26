#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct ListNode  // WB-1.1
{
	string item;
	int count;
	ListNode *link;
};

typedef ListNode* ListNodePtr;


// WB-5
struct DoubleNode 
{
	int data;
	DoubleNode* forwardLink;
	DoubleNode* backwardLink;
};
typedef DoubleNode* DoubleNodePtr;

void nodesAndLinkedLists();
void stacksAndQueus();

// Pre: Requires the head to a ListNode pointer Linked List and a new string value to be put in the node
// The linked list must have ListNode* named link to point to the next element
// It also needs a string called item which can be used to store data elements
// Post: Inserts newValue at the START of of the linked list
// Returns nothing
void headInsert(ListNode*& head, string newValue);  //WB-2.0
// Pre: Requires the head to a ListNode pointer Linked List and a string value to be searched for
// The linked list must have ListNode* named link to point to the next element
// It also needs a string called item which can be used to store data elements
ListNodePtr search(const ListNodePtr& head, const string& target);  //WB-3.0
// Pre: Requires a node of a ListNode pointer Linked List and a new string value to be put in the node
// The linked list must have ListNode* named link to point to the next element
// It also needs a string called item which can be used to store data elements
// Post: Inserts newValue at the START of of the linked list
// Returns nothing
void insert(ListNode*& node, string newValue);

// Pre: Requires a node of a ListNode pointer Linked List
// The linked list must have ListNode* named link to point to the next element
// Post: Removes the node after beforeDiscard from the linked list
// Returns nothing
void removeBefore(ListNodePtr& beforeDiscard);
// Pre: Requires a node of a ListNode pointer double linked list
// The linked list must have DoubleNode* named forwardLink to point to the next node
// It also must include a DoubleNode* named backwardLink for the previous node
// Post: Removes the node discard from the list
// Returns nothing
void remove(DoubleNodePtr& discard);

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
	{
		struct ListNode
		{
			string item;
			int count = 3;
			ListNode *link;
		};
	}
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

	// EXAMPLE
	// head->link = NULL;
	head->link = new ListNode;
	head->link->item = "pizza";
	head->link->count = 5;
	head->link->link = new ListNode;
	head->link->link->item = "chicken tendies";
	head->link->link->count = 8;
	head->link->link->link = NULL;  // Specifies it goes no further

	struct ReportCard
	{
		string name;
		int gradeLevel;
		char class1Grade;
		char class2Grade;
		char class3Grade;
		ReportCard *link;
	};

	typedef ReportCard* ReportCardPtr;
	ReportCardPtr rchead;
	rchead = new ReportCard;

	(*rchead).name = "Hunter";
	(*rchead).gradeLevel = 13;
	(*rchead).class1Grade = 'A';
	(*rchead).class2Grade = 'B';
	(*rchead).class3Grade = 'A';
	(*rchead).link = new ReportCard;

	(*(*rchead).link).name = "Ron";  // Much more disgusting way of accessing LL
	(*(*rchead).link).gradeLevel = 11;
	(*(*rchead).link).class1Grade = 'C';
	(*(*rchead).link).class2Grade = 'B';
	(*(*rchead).link).class3Grade = 'F';
	(*(*rchead).link).link = nullptr;

	print("\nIt can be used just like regular variables: " + rchead->link->name);
	print("It can be used just like regular variables: " + (*(*rchead).link).name);
	// It works both ways, but the top way is much CLEANER

	print("\nnullptr- Same as NULL but can only be used for pointers");
	print("It should always be used with pointers to differentiate it from regular 0");

	// ---SELF TEST START---

	// 1. What is the output produced by the following code?
	{
		struct Box
		{
			string name;
			int number;
			Box *next;
		};

		typedef Box* BoxPtr;
		
		BoxPtr head;
		head = new Box;
		head->name = "Sally";
		head->number = 18;
		head->next = nullptr; // ST-2.1
		delete head;  // ST-3.1

		// cout << (*head).name << endl;
		// cout << head->name << endl;
		// cout << (*head).number << endl;
		// cout << head->number << endl;

		// Sally
		// Sally 
		// 18
		// 18
	}

	// 2. Suppose that your program contains the type definitions and code given
	// in Self-Test Exercise 1. That code creates a node that contains the string
	// "Sally" and the number 18 . What code would you add in order to set the
	// value of the member variable next of this node equal to NULL ?

	// Added at ST-2.1

	// 3. Suppose that your program contains the type definitions and code given
	// in Self-Test Exercise 1. Assuming that the value of the pointer variable
	// head has not been changed, how can you destroy the dynamic variable
	// pointed to by head and return the memory it uses to the freestore so that it
	// can be reused to create new dynamic variables?

	// Added at ST-3.1

	// 4. Write code to assign the string “Wilbur’s brother Orville” to the member
	// item of the node pointed to by head .

	{ 
		// Kept in own scope bc it was causing errors with //WB-2 because newLL was a ListNode 
		// from this function's scope, while the insertHead function used the global version 
		// of nodeList 
		struct ListNode
		{
			string item;
			int count;
			ListNode *link;
		};

		ListNode *head = new ListNode;
		head->item = "Wilbur's brother Orville";
	}
	// ---SELF TEST END---

	print("\nLinked List- list of nodes where each node has a member variable that is a pointer that points to the next node in the list");
	print("The last node should have NULL for its link");
	// LL were what I wrote before
	print("Head- first node in a LL");

	print("\nIt is a good idea to have a function to insert a new head at the end of a LL");
	// WB-1
	print("Because the LL is used as an argument, you need to have the LL defined at the top or in a seperate file");

	//Refer to WB-2 for this
	print("\nTo quickly use LL, you need to create functions to work with them");
	print("When using LL as arguments, pass the head, not just part of the list");
	
	ListNode* newLL = new ListNode;
	newLL->item = "Test";
	newLL->link = NULL;
	headInsert(newLL, "It works!");
	//WB-2.1

	print("\nEmpty list- LL with nothing in it");
	print("If you want to specify a empty list, make the head NULL");
	ListNodePtr emptyList;
	emptyList = NULL;
	print("You want to make sure functions work empty lists");
	// You should always test to make sure it works with ELs
	// If it doesn't work you might need to make a special case for them
	// Example WB-2 works with empty lists

	print("\nMake sure not to overwrite the head and lose nodes");
	// For example if you skip the line after WB-2.3 tempPtr->link = head;
	// and go to just WB-2.3.1 head = tempPtr;
	// you will be setting head to tempPtr before tempPtr includes all the 
	// previous nodes, essentially wiping head of all original nodes
	print("Losing nodes would be an example of memory leak");
	// This can cause issues like crashing

	//WB-3
	cout << "\nUsing functions, you can add to LL and serch them: " << search(newLL, "It works!") << " and " << search(newLL, "shouldn't exist");
	cout << "\nIt even works with empty lists " << search(emptyList, "nothing");

	print("\n\nIterator- constructor that allows you to cycle through data stored in a data structure");
	print("Allows you to perform an action on each item");
	// Basically just loops (itterates through a list of items) ex forEach

	for (ListNodePtr iter = head; iter != NULL; iter = iter->link)
	{
		cout << iter->item << " ";
	} cout << "\n";
	headInsert(head, "chips");
	insert(head->link, "soda");
	removeBefore(head->link->link->link);
	for (ListNodePtr iter = head; iter != NULL; iter = iter->link)
	{
		cout << iter->item << " ";
	} cout << "\n";

	print("\n To loop through a LL use:");
	print("for(NODE_TYPE* iter; iter != NULL; iter = iter->link");
	print("Within the loop you can access the item with iter->ITEM");
	// Basically just looping through an array but for LL

	print("\nSetting the head of a linked list to the head of another linked list soft copies");
	print("Modifying one will modify the other");

	//---SELF TEST START---
	{

		// 5. Write type definitions for the nodes and pointers in a linked list. Call the
		// node type NodeType and call the pointer type PointerType . The linked
		// lists will be lists of letters.
		
		struct NodeType
		{
			char data;
			NodeType* link;
		};

		typedef NodeType* PointerType;

		PointerType NTHead = new NodeType;
		NTHead->data = 'a';
		NTHead->link = new NodeType;
		NTHead->link->data = 'b';
		NTHead->link->link = NULL;

		// 6. A linked list is normally given by giving a pointer that points to the first
		// node in the list, but an empty list has no first node. What pointer value is
		// normally used to represent an empty list?
		
		// NULL

		// 7. Suppose your program contains the following type definitions and pointer
		// variable declarations:
		
		struct Node
		{
			double data;
			Node *next;
		};
		
		typedef Node* Pointer;
		Pointer p1, p2;

		p1 = p1->next;
		// Suppose p1 points to a node of this type that is on a linked list. Write
		// code that will make p1 point to the next node on this linked list. (The
		// pointer p2 is for the next exercise and has nothing to do with this
		// exercise.)
		
		// 8. Suppose your program contains type definitions and pointer variable
		// declarations as in Self-Test Exercise 7. Suppose further that p2 points to
		// a node of type Node that is on a linked list and is not the last node on
		// the list. Write code that will delete the node after the node pointed to by
		// p2 . After this code is executed, the linked list should be the same, except
		// that there will be one less node on the linked list. (Hint: You might want
		// to declare another pointer variable to use.)
		
		// Pointer discard = p2->next;
		// p2->next = discard->next;
		// delete discard;

		// Will give issue because nothing after p2 head

		// 9. Choose an answer and explain it.
		// For a large array and large list holding the same type objects, inserting a
		// new object at a known location into the middle of a linked list compared
		// with insertion in an array is
			// a. More efficient- linked lists allow you to only go forward, but you can insert anywhere in a list at O(1) 
			// For an array it would be O(n/2) because it needs to itterate half way through the array
		// b. Less efficient
		// c. About the same
		// d. Dependent on the size of the two list 
	}
	//---SELF TEST END---

	print("\nDoubly Linked List- Linked List that has two links");
	print("One link is the next node, and the additional link is the previous node");
	print("This allows a link list to be traversed both ways");
	{
		struct Node 
		{
			int data;
			Node* forwardLink;
			Node* backwardLink;
		};
		
		typedef DoubleNode* DoubleNodePtr;
	}

	print("Tree- data structure where you can reach any node from the top");
	print("The top of a tree is called the root, and if you follow it, you will reach an end");
	print("Binary tree- tree where each node has 2 links");
	// There are other types of trees which have more than 2 links
	{
		struct Tree
		{
			int data;
			Tree* leftLink;
			Tree* rightLink;
		};

		typedef Tree* TreePtr;
	}
	// Tree != Linked List
	print("\nRoot Node- (top node) Pointer to the first node");
	print("Similar to the head of a linked list");
	// CS trees should look upsidedown with the root at the bottom and it branching 
	// out the higher you go
	print("Leaf Nodes- Nodes at the end of the tree pointing to NULL");
	// Binary trees can be used to efficiently store and retrieve data

	{
		class Node
		{
		public:
			Node( );
			Node(int value, Node *next);
			//Constructors to initialize a node
		
			int getData( ) const;
			//Retrieve value for this node
		
			Node *getLink( ) const;
			//Retrieve next Node in the list
		
			void setData(int value);
			//Use to modify the value stored in the list
		
			void setLink(Node *next);
			//Use to change the reference to the next node
		
		private:
			int data;
			Node *link;
		};
	
	typedef Node* NodePtr;
	}

	print("When using linked lists, it is possible to make a class with needed functions");
	

}

void stacksAndQueus()
{
	print("\n--13.2: Stacks and Queues--\n\n");
}

//WB-2.0
// Interesting, up top 2.0.1, it was declared with ListNodePtr, but 
// since it means the same as ListNode*, you can use them interchangably
// even if it is inconsistent (not good but interesting)
void headInsert(ListNodePtr& head, string newValue)
{
	// Creates a new pointer to a linked list
	ListNodePtr tempPtr;
	tempPtr = new ListNode;

	// Sets the item in the new pointer to the value requested
	tempPtr->item = newValue;

	//WB-2.3
	// Sets the entirety of the old LL to the next value of tempPtr
	tempPtr->link = head;

	//WB-2.3.1
	// Sets head equal to tempPtr
	head = tempPtr;

	// This essentially appends newValue at the beginning of the LL
}

//WB-3.1
ListNodePtr search(const ListNodePtr& head, const string& target)
{
	ListNodePtr currentNode = head;

	// currentNode->item/link would be undefined and cause an error in an empty list
	// this is used to let the function work with empty lists
	if (currentNode == NULL)
	{
		return NULL;
	}

	// Checks if the head includes target, then goes to the next element (head's )
	// link until it either reaches NULL or finds the target
	while(currentNode->item != target && currentNode->link != NULL)
	{
		currentNode = currentNode->link;
	}

	// Returns the link to the node with the target if found
	// otherwise returns NULL
	if(currentNode->item == target)
	{
		return currentNode;
	}
	else
	{
		return NULL;
	}
}

//WB-4
void insert(ListNode*& elem, string newValue)
{
// Creates a new pointer to a linked list
	ListNodePtr tempPtr;
	tempPtr = new ListNode;

	// Sets the item in the temp pointer to the new value
	tempPtr->item = newValue;

	// Sets the temp LL to the next link after node
	tempPtr->link = elem->link;

	// Sets the node equal to the temp pointer
	elem->link = tempPtr;

	// This essentially adds the newly created node after the node the user requested
	
	// This works by creating a link between temp and anything after elem 
	// elem then stops linking with anything after itself and links with temp
	// Poorly drawn diagram 13.4 in notes 
}

//WB-4
void removeBefore(ListNodePtr& beforeDiscard)
{
	// Creates a new LL set to discard
	ListNodePtr discard = beforeDiscard->link;

	// Links before discard to the element after discard
	// Essentially removing discard from the chain
	beforeDiscard->link = discard->link;

	// Deletes discard to free up the space
	delete discard;
}

void remove(DoubleNodePtr& discard)
{
	// Links the link before discard to the link after discard
	// This removes it from the node chain
	discard->backwardLink = discard->forwardLink;

	// Deletes discard to free up the space
	delete discard;
}