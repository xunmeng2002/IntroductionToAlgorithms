#pragma once


struct BinarySearchTreeNode
{
	BinarySearchTreeNode(int key) :Parent(nullptr), Left(nullptr), Right(nullptr), Key(key) { }
	BinarySearchTreeNode* Parent;
	BinarySearchTreeNode* Left;
	BinarySearchTreeNode* Right;

	int Key;
	void Print();
};
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Report();
	void InorderTreeWalk(BinarySearchTreeNode* x);
	void PreorderTreeWalk(BinarySearchTreeNode* x);
	void PostorderTreeWalk(BinarySearchTreeNode* x);

	BinarySearchTreeNode* Minimum(BinarySearchTreeNode* x);
	BinarySearchTreeNode* Maximum(BinarySearchTreeNode* x);

	BinarySearchTreeNode* Search(BinarySearchTreeNode* x, int key);
	BinarySearchTreeNode* IterativeSearch(BinarySearchTreeNode* x, int key);

	BinarySearchTreeNode* Successor(BinarySearchTreeNode* x);
	BinarySearchTreeNode* Predecessor(BinarySearchTreeNode* x);

	void Insert(BinarySearchTreeNode* z);
	void Delete(BinarySearchTreeNode* z);

private:
	void Release(BinarySearchTreeNode* x);
	void Transplant(BinarySearchTreeNode* u, BinarySearchTreeNode* v);
public:
	BinarySearchTreeNode* Root;
};



void PrintNode(BinarySearchTreeNode* node);
void TestBinarySearchTree();
