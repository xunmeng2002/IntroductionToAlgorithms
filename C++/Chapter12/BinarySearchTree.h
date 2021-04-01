#pragma once


struct Node
{
	Node(int key, int value) :Parent(nullptr), Left(nullptr), Right(nullptr), Key(key) { }
	Node* Parent;
	Node* Left;
	Node* Right;

	int Key;
	void Print();
};
class BinarySearchTree
{
public:
	void InorderTreeWalk(Node* x);
	void PreorderTreeWalk(Node* x);
	void PostorderTreeWalk(Node* x);

	Node* TreeMinimum(Node* x);
	Node* TreeMaximum(Node* x);

	Node* TreeSearch(Node* x, int key);
	Node* IterativeTreeSearch(Node* x, int key);

	Node* TreeSuccessor(Node* x);
	Node* TreePredecessor(Node* x);

	void TreeInsert(Node* z);
	void TreeDelete(Node* z);

private:
	void TreeTransplant(Node* u, Node* v);
public:
	Node* Root;
};



void PrintNode(Node* node);
void TestBinarySearchTree();
