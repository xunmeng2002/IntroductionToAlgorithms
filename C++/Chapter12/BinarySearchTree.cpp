#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

void Node::Print()
{
	cout << "(" << Key << ":" << Value << ")  ";
}


void BinarySearchTree::InorderTreeWalk(Node* x)
{
	if (x != nullptr)
	{
		InorderTreeWalk(x->Left);
		x->Print();
		InorderTreeWalk(x->Right);
	}
}
void BinarySearchTree::PreorderTreeWalk(Node* x)
{
	if (x != nullptr)
	{
		x->Print();
		PreorderTreeWalk(x->Left);
		PreorderTreeWalk(x->Right);
	}
}
void BinarySearchTree::PostorderTreeWalk(Node* x)
{
	if (x != nullptr)
	{
		PostorderTreeWalk(x->Left);
		PostorderTreeWalk(x->Right);
		x->Print();
	}
}

Node* BinarySearchTree::TreeMinimum(Node* x)
{
	while (x->Left != nullptr)
	{
		x = x->Left;
	}
	return x;
}
Node* BinarySearchTree::TreeMaximum(Node* x)
{
	while (x->Right != nullptr)
	{
		x = x->Right;
	}
	return x;
}

Node* BinarySearchTree::TreeSearch(Node* x, int key)
{
	if (x == nullptr || key == x->Key)
	{
		return x;
	}
	if (key < x->Key)
	{
		return TreeSearch(x->Left, key);
	}
	else
	{
		return TreeSearch(x->Right, key);
	}
}
Node* BinarySearchTree::IterativeTreeSearch(Node* x, int key)
{
	while (x != nullptr && key != x->Key)
	{
		if (key < x->Key)
		{
			x = x->Left;
		}
		else
		{
			x = x->Right;
		}
	}
	return x;
}

Node* BinarySearchTree::TreeSuccessor(Node* x)
{
	if (x->Right != nullptr)
	{
		return TreeMinimum(x->Right);
	}
	auto y = x->Parent;
	while (y != nullptr && x == y->Right)
	{
		x = y;
		y = y->Parent;
	}
	return y;
}
Node* BinarySearchTree::TreePredecessor(Node* x)
{
	if (x->Left != nullptr)
	{
		return TreeMaximum(x->Left);
	}
	auto y = x->Parent;
	while (y != nullptr && x == y->Left)
	{
		x = y;
		y = y->Parent;
	}
	return y;
}

void BinarySearchTree::TreeInsert(Node* z)
{
	Node* x = Root;
	Node* y = nullptr;
	while (x != nullptr)
	{
		y = x;
		if (z->Key < x->Key)
		{
			x = x->Left;
		}
		else
		{
			x = x->Right;
		}
	}
	z->Parent = y;
	if (y == nullptr)
	{
		Root = z;
	}
	else if (z->Key < y->Key)
	{
		y->Left = z;
	}
	else
	{
		y->Right = z;
	}
}
void BinarySearchTree::TreeDelete(Node* z)
{
	if (z->Left == nullptr)
	{
		TreeTransplant(z, z->Right);
	}
	else if (z->Right == nullptr)
	{
		TreeTransplant(z, z->Left);
	}
	else
	{
		Node* y = TreeMinimum(z->Right);
		if (y->Parent != z)
		{
			TreeTransplant(y, y->Right);
			y->Right = z->Right;
			y->Right->Parent = y;
		}
		TreeTransplant(z, y);
		y->Left = z->Left;
		y->Left->Parent = y;
	}
}

void BinarySearchTree::TreeTransplant(Node* u, Node* v)
{
	if (u->Parent == nullptr)
	{
		Root = v;
	}
	else if (u == u->Parent->Left)
	{
		u->Parent->Left = v;
	}
	else
	{
		u->Parent->Right = v;
	}
	if (v != nullptr)
	{
		v->Parent = u->Parent;
	}
}


void PrintNode(Node* node)
{
	if (node)
	{
		node->Print();
	}
	else
	{
		cout << "Empty Node." << endl;
	}
}
void TestBinarySearchTree()
{
	BinarySearchTree* tree = new BinarySearchTree();
	tree->Root = new Node(5, 0);

	tree->TreeInsert(new Node(3, 0));
	tree->TreeInsert(new Node(4, 0));
	tree->TreeInsert(new Node(5, 1));
	tree->TreeInsert(new Node(6, 0));
	tree->TreeInsert(new Node(7, 0));
	tree->TreeInsert(new Node(8, 0));
	tree->TreeInsert(new Node(3, 1));
	tree->TreeInsert(new Node(4, 1));
	tree->TreeInsert(new Node(5, 2));
	tree->TreeInsert(new Node(6, 1));
	tree->TreeInsert(new Node(7, 1));
	tree->TreeInsert(new Node(8, 1));

	cout << endl << "PreorderTreeWalk:" << endl;
	tree->PreorderTreeWalk(tree->Root);
	cout << endl << "InorderTreeWalk:" << endl;
	tree->InorderTreeWalk(tree->Root);
	cout << endl << "PostorderTreeWalk:" << endl;
	tree->PostorderTreeWalk(tree->Root);

	cout << endl << "TreeMinimum:" << endl;
	PrintNode(tree->TreeMinimum(tree->Root));
	cout << endl << "TreeMaximum:" << endl;
	PrintNode(tree->TreeMaximum(tree->Root));

	cout << endl << "TreeSearch:" << endl;
	PrintNode(tree->TreeSearch(tree->Root, 6));

	cout << endl << "TreeSuccessor:" << endl;
	PrintNode(tree->TreeSuccessor(tree->Root->Right));
	
	cout << endl << "TreePredecessor:" << endl;
	PrintNode(tree->TreePredecessor(tree->Root->Right));
	
	cout << endl << "TreeDelete:" << endl;
	tree->Root->Print();
	tree->TreeDelete(tree->Root);

	cout << endl << "PreorderTreeWalk:" << endl;
	tree->PreorderTreeWalk(tree->Root);
	cout << endl << "InorderTreeWalk:" << endl;
	tree->InorderTreeWalk(tree->Root);
	cout << endl << "PostorderTreeWalk:" << endl;
	tree->PostorderTreeWalk(tree->Root);
}
