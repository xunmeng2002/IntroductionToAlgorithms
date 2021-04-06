#include "BinarySearchTree.h"
#include <iostream>
#include <vector>

using namespace std;

void Node::Print()
{
	cout << Key << "  ";
}

BinarySearchTree::BinarySearchTree()
	:Root(nullptr)
{

}
BinarySearchTree::~BinarySearchTree()
{
	if (Root != nullptr)
	{
		Release(Root);
	}
	Root = nullptr;
}

void BinarySearchTree::Report()
{
	cout << "PreorderTreeWalk:\t";
	PreorderTreeWalk(Root);
	cout << endl << "InorderTreeWalk:\t";
	InorderTreeWalk(Root);
	cout << endl << "PostorderTreeWalk:\t";
	PostorderTreeWalk(Root);
	cout << endl;
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

Node* BinarySearchTree::Minimum(Node* x)
{
	while (x->Left != nullptr)
	{
		x = x->Left;
	}
	return x;
}
Node* BinarySearchTree::Maximum(Node* x)
{
	while (x->Right != nullptr)
	{
		x = x->Right;
	}
	return x;
}

Node* BinarySearchTree::Search(Node* x, int key)
{
	if (x == nullptr || key == x->Key)
	{
		return x;
	}
	if (key < x->Key)
	{
		return Search(x->Left, key);
	}
	else
	{
		return Search(x->Right, key);
	}
}
Node* BinarySearchTree::IterativeSearch(Node* x, int key)
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

Node* BinarySearchTree::Successor(Node* x)
{
	if (x->Right != nullptr)
	{
		return Minimum(x->Right);
	}
	auto y = x->Parent;
	while (y != nullptr && x == y->Right)
	{
		x = y;
		y = y->Parent;
	}
	return y;
}
Node* BinarySearchTree::Predecessor(Node* x)
{
	if (x->Left != nullptr)
	{
		return Maximum(x->Left);
	}
	auto y = x->Parent;
	while (y != nullptr && x == y->Left)
	{
		x = y;
		y = y->Parent;
	}
	return y;
}

void BinarySearchTree::Insert(Node* z)
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
void BinarySearchTree::Delete(Node* z)
{
	if (z->Left == nullptr)
	{
		Transplant(z, z->Right);
	}
	else if (z->Right == nullptr)
	{
		Transplant(z, z->Left);
	}
	else
	{
		Node* y = Minimum(z->Right);
		if (y->Parent != z)
		{
			Transplant(y, y->Right);
			y->Right = z->Right;
			y->Right->Parent = y;
		}
		Transplant(z, y);
		y->Left = z->Left;
		y->Left->Parent = y;
	}
}

void BinarySearchTree::Release(Node* x)
{
	if (x != nullptr)
	{
		Release(x->Left);
		Release(x->Right);
		delete x;
	}
}
void BinarySearchTree::Transplant(Node* u, Node* v)
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
	vector<Node*> nodes;
	nodes.push_back(new Node(4));
	nodes.push_back(new Node(5));
	nodes.push_back(new Node(7));
	nodes.push_back(new Node(6));
	nodes.push_back(new Node(3));
	nodes.push_back(new Node(1));
	nodes.push_back(new Node(2));
	

	BinarySearchTree* tree = new BinarySearchTree();
	for (auto node : nodes)
	{
		tree->Insert(node);
		tree->Report();
	}
	cout << endl << "Root:\t";
	PrintNode(tree->Root);
	cout << endl << "Minimum:\t";
	PrintNode(tree->Minimum(tree->Root));
	cout << endl << "Maximum:\t";
	PrintNode(tree->Maximum(tree->Root));

	cout << endl << "Search:\t";
	PrintNode(tree->Search(tree->Root, 6));

	cout << endl << "Successor:\t";
	PrintNode(tree->Successor(tree->Root));
	cout << endl << "Predecessor:\t";
	PrintNode(tree->Predecessor(tree->Root));
	
	cout << endl << endl;
	for (auto node : nodes)
	{
		tree->Report();
		tree->Delete(node);
	}
}
