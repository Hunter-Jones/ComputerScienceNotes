#include <iostream>
#include <string>

using std::cout;
using std::string;

// Namespace for basic functions that should be avaliable in each course notes chapter
namespace courseNamespace
{
	void print(string str)
	{
		cout << str << "\n";
	}

	// Namespace for basic linked list types
	namespace nodes
	{
		struct ListNode
		{
			string item;
			ListNode *link;
		};
		typedef ListNode* ListNodePtr;
		// Basic node for a linked list
		// stores data as string

		struct Node
		{
			string item;
			Node *link;
		};
		typedef Node* NodePtr;
		// Basic node for a linked list
		// stores data as int

		struct TreeListNode  // WB-1.1
		{
			string item;
			TreeListNode *leftLink;
			TreeListNode *rightLink;
		};
		typedef TreeListNode* TreeListNodePtr;
		// Basic node for a binary tree
		// stores data as string

		struct TreeNode  // WB-1.1
		{
			int item;
			TreeNode *leftLink;
			TreeNode *rightLink;
		};
		typedef TreeNode* TreeNodePtr;
		// Basic node for a binary tree
		// stores data as int
	}
}