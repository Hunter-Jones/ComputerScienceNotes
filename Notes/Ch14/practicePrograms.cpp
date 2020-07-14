#include <iostream>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;

namespace
{
	void print(string str)
	{
		cout << str << "\n";
	}

	struct Node
	{
		int data;
		Node* link;
	}; typedef Node* NodePtr;

	struct Tree
	{
		int data;
		Tree* leftLink;
		Tree* rightLink;
	}; typedef Tree* TreePtr;
}

// Practice Program 1
int largestDivisor(int number);
// Pre: requires number, a whole number
// Post: Returns the largest divisor 
int largestDivisor(int number, int prev);
// Pre requires number, a positive whole number 
// and previous, a number starting at number and decramenting each itteration
// Post: (Only should be run within largestDivisor(int)) 
// Helper function to go through and return 
// so user can type ld(15) instead of ld(15, 15)

//Practice Program 3
bool isPrime(int number);
// Pre: requires number, a whole number
// Post: Returns the largest divisor 
bool isPrime(int number, int prev);

// Practice Project 1
// Pre: Requires a Node linked list pointer
// Post: Returns how many nodes there are in the linked list
int nodeLength(const NodePtr& head);

//Practice Program 2
void headInsert(TreePtr& root, int  newData);
// Pre: Requires a binary tree 
// and an integer for data to be added to the binary tree
// Post modifies the binary tree by adding newData to the appropriate branch
// to create a binary search tree
void setData(TreePtr currentNode, int newData);
// Helper function for headInsert
// Pre: Requires a binary tree 
// and an integer for data to be added to the binary tree
// Adds the newData to the current node in the tree

//Practice Program 3
void printTree(const TreePtr& root);
// Pre: Requires the root of a Tree
// Post: Recursively prints out the tree, starting with the elements on the left 
// then moving to the elements on the right

int main()
{
	print("largestDivisor: ");
	cout << "15: " << largestDivisor(15) << endl;
	cout << "5: " << largestDivisor(5) << endl;
	cout << "90: " << largestDivisor(90) << endl;



	print("\nPrime: ");
	cout << "15: " << isPrime(15) << endl;
	cout << "5: " << isPrime(5) << endl;
	cout << "90: " << isPrime(90) << endl;



	NodePtr head = new Node;
	head->data = 4;
	head->link = new Node;
	head->link->data = 5;
	head->link->link = new Node;
	head->link->link->data = 2;
	head->link->link->link = new Node;  // Specifies it goes no further
	head->link->link->link->data = 55;
	head->link->link->link->link = new Node;
	head->link->link->link->link->data = 11;
	head->link->link->link->link->link = new Node;
	head->link->link->link->link->link->data = 0;
	head->link->link->link->link->link->link = NULL;

	cout << "\nLinked List Length: ";
	cout << nodeLength(head) << endl;



	TreePtr treeHead = NULL;

	cout << "\nTree Insert: ";
	headInsert(treeHead, 5);  // head 
	headInsert(treeHead, 3); // l
	headInsert(treeHead, 7); // r
	headInsert(treeHead, 6); // rl
	headInsert(treeHead, 7); // rr (if data = newData, it goes to right branch)
	headInsert(treeHead, 1); // ll
	headInsert(treeHead, 4); // lr
	headInsert(treeHead, 9); // rrr
	// cout << treeHead->rightLink->data << " " << treeHead->rightLink->rightLink->data << " ";
	cout << treeHead->data;
	cout << treeHead->leftLink->data;
	cout << treeHead->rightLink->data;
	cout << treeHead->rightLink->leftLink->data;
	cout << treeHead->rightLink->rightLink->data;
	cout << treeHead->leftLink->leftLink->data;
	cout << treeHead->leftLink->rightLink->data;
	cout << treeHead->rightLink->rightLink->rightLink->data;

	cout << "\n\nPrint Tree: ";
	printTree(treeHead);
}

int largestDivisor(int number)
{
	return largestDivisor(number, number);
}

int largestDivisor(int number, int prev)
{
	prev -= 1;
	if (number % prev != 0)
	{
		return largestDivisor(number, prev);
	}
	else
	{
		return prev;
	}
}
bool isPrime(int number)
{
	return isPrime(number, number);
}


bool isPrime(int number, int prev)
{
	prev -= 1;
	if (prev == 1)
	{
		return false;
	}
	if (number % prev == 0)
	{
		return true;
	}
	else
	{	
		return isPrime(number, prev);
	}
}

int nodeLength(const NodePtr& head)
{
	// Prevents segmentation fault if it is empty
	if (head != NULL){
		if (head->link == NULL)
		{
			return 1;
		}
		else 
		{
			return nodeLength(head->link) + 1;
		}
	}
}

// Original 
// void headInsert(TreePtr& head, int newData)
// {
// 	if (head == NULL)
// 	{
// 		cout << "middle ";
// 		head = new Tree;
// 		head->leftLink = NULL;
// 		head->rightLink = NULL;
// 		head->data = newData;
// 		return;
// 	}
// 	else if (head->data > newData)
// 	{
// 		if (head->leftLink == NULL)
// 		{
// 			head->leftLink = new Tree;

// 			head->leftLink->data = newData;
// 			head->leftLink->leftLink = NULL;
// 			head->leftLink->rightLink = NULL;
// 		}
// 		else
// 		{
// 			headInsert(head->leftLink, newData);
// 	} 
// 	else 
// 	{
// 		if (head->rightLink == NULL)
// 		{
// 			head->rightLink = new Tree;

// 			head->rightLink->data = newData;
// 			head->rightLink->leftLink = NULL;
// 			head->rightLink->rightLink = NULL;
// 		}
// 		else
// 		{
// 			headInsert(head->rightLink, newData);
// 		}
// 	}
// }

void headInsert(TreePtr& root, int newData)
{
	if (root == NULL)
	{
		// Adds the first element
		root = new Tree;
		setData(root, newData);
		return;
	}

	if (root->data > newData)
	{
		//If the new element is smaller, add to left side
		if (root->leftLink == NULL)
		{
			root->leftLink = new Tree;
			setData(root->leftLink, newData);
		}
		else
		{
			// If an element is already on the left side, go another branch deeper
			headInsert(root->leftLink, newData);
		}
	} 
	else 
	{
		// If new element is larger, add to right side
		if (root->rightLink == NULL)
		{
			// If no element exists on right side, add here
			root->rightLink = new Tree;
			setData(root->rightLink, newData);
		}
		else
		{
			// If an element is already on the right side, go another branch deeper
			headInsert(root->rightLink, newData);
		}
	}
}
void setData(TreePtr currentNode, int newData)
{
	currentNode->data = newData;
	currentNode->leftLink = NULL;
	currentNode->rightLink = NULL;
}

void printTree(const TreePtr& root)
{
	cout << root->data;

	if(root->leftLink != NULL)
	{	
		printTree(root->leftLink);
	}
	if(root->rightLink != NULL)
	{
		printTree(root->rightLink);
	}
}