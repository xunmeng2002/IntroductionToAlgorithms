#pragma once


struct Node
{
	Node(int key) :Parent(nullptr), Left(nullptr), Right(nullptr), Key(key) { }
	Node* Parent;
	Node* Left;
	Node* Right;

	int Key;
	void Print();
};
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Report();
	void InorderTreeWalk(Node* x);
	void PreorderTreeWalk(Node* x);
	void PostorderTreeWalk(Node* x);

	Node* Minimum(Node* x);
	Node* Maximum(Node* x);

	Node* Search(Node* x, int key);
	Node* IterativeSearch(Node* x, int key);

	Node* Successor(Node* x);
	Node* Predecessor(Node* x);

	void Insert(Node* z);
	void Delete(Node* z);

private:
	void Release(Node* x);
	void Transplant(Node* u, Node* v);
public:
	Node* Root;
};



void PrintNode(Node* node);
void TestBinarySearchTree();
