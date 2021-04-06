#pragma once
#include <iostream>

enum class Color : int
{
	Red = 0,
	Black = 1,
};
std::ostream& operator<<(std::ostream& os, const Color& color);

struct RedBlackTreeNode
{
	RedBlackTreeNode(int key, Color color) :Parent(nullptr), Left(nullptr), Right(nullptr), Key(key), Color(color){ }
	RedBlackTreeNode* Parent;
	RedBlackTreeNode* Left;
	RedBlackTreeNode* Right;

	int Key;
	Color Color;
	void Print();
};

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	void Report();
	void InorderTreeWalk(RedBlackTreeNode* x);
	void PreorderTreeWalk(RedBlackTreeNode* x);
	void PostorderTreeWalk(RedBlackTreeNode* x);

	RedBlackTreeNode* TreeMinimum(RedBlackTreeNode* x);
	RedBlackTreeNode* TreeMaximum(RedBlackTreeNode* x);

	void Insert(RedBlackTreeNode* z);
	void Delete(RedBlackTreeNode* z);



private:
	void LeftRotate(RedBlackTreeNode* x);
	void RightRotate(RedBlackTreeNode* y);
	void InsertFixUp(RedBlackTreeNode* z);
	void DeleteFixUp(RedBlackTreeNode* z);
	void Transplant(RedBlackTreeNode* u, RedBlackTreeNode* v);

	void Release(RedBlackTreeNode* x);

public:
	RedBlackTreeNode* Root;
	RedBlackTreeNode* Nil;
};

void TestRedBlackTree();

