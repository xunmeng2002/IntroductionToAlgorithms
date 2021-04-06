#include "RedBlackTree.h"
#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const Color& color)
{
	if (color == Color::Red)
	{
		os << "Red";
	}
	else
	{
		os << "Black";
	}
	return os;
}

void RedBlackTreeNode::Print()
{
	cout << "(" << Key << ": " << Color  << ")  ";
}


RedBlackTree::RedBlackTree()
{
	Nil = new RedBlackTreeNode(0, Color::Black);
	Root = Nil;
}
RedBlackTree::~RedBlackTree()
{
	if (Root != nullptr)
	{
		Release(Root);
	}
	Root = nullptr;
	if (Nil != nullptr)
	{
		delete Nil;
	}
	Nil = nullptr;
}

void RedBlackTree::Report()
{
	cout << "PreorderTreeWalk:\t";
	PreorderTreeWalk(Root);
	cout << endl << "InorderTreeWalk:\t";
	InorderTreeWalk(Root);
	cout << endl << "PostorderTreeWalk:\t";
	PostorderTreeWalk(Root);
	cout << endl;
}
void RedBlackTree::InorderTreeWalk(RedBlackTreeNode* x)
{
	if (x != Nil)
	{
		InorderTreeWalk(x->Left);
		x->Print();
		InorderTreeWalk(x->Right);
	}
}
void RedBlackTree::PreorderTreeWalk(RedBlackTreeNode* x)
{
	if (x != Nil)
	{
		x->Print();
		PreorderTreeWalk(x->Left);
		PreorderTreeWalk(x->Right);
	}
}
void RedBlackTree::PostorderTreeWalk(RedBlackTreeNode* x)
{
	if (x != Nil)
	{
		PostorderTreeWalk(x->Left);
		PostorderTreeWalk(x->Right);
		x->Print();
	}
}

RedBlackTreeNode* RedBlackTree::TreeMinimum(RedBlackTreeNode* x)
{
	while (x->Left != nullptr)
	{
		x = x->Left;
	}
	return x;
}
RedBlackTreeNode* RedBlackTree::TreeMaximum(RedBlackTreeNode* x)
{
	while (x->Right != nullptr)
	{
		x = x->Right;
	}
	return x;
}

void RedBlackTree::Insert(RedBlackTreeNode* z)
{
	auto x = Root;
	RedBlackTreeNode* y = Nil;
	while (x != Nil)
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
	if (y == Nil)
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
	z->Left = Nil;
	z->Right = Nil;
	z->Color = Color::Red;
	InsertFixUp(z);
}
void RedBlackTree::Delete(RedBlackTreeNode* z)
{
	RedBlackTreeNode* x = nullptr;
	auto y = z;
	auto y_original_color = y->Color;
	if (z->Left == Nil)
	{
		x = z->Right;
		Transplant(z, z->Right);
	}
	else if (z->Right == Nil)
	{
		x = z->Left;
		Transplant(z, z->Left);
	}
	else
	{
		y = TreeMinimum(z->Right);
		y_original_color = y->Color;
		x = y->Right;
		if (y->Parent != z)
		{
			Transplant(y, y->Right);
			y->Right = z->Right;
			y->Right->Parent = y;
		}
		Transplant(z, y);
		y->Left = z->Left;
		y->Left->Parent = y;
		y->Color = z->Color;
	}
	if (y_original_color == Color::Black)
	{
		DeleteFixUp(x);
	}
}

void RedBlackTree::LeftRotate(RedBlackTreeNode* x)
{
	auto y = x->Right;
	x->Right = y->Left;
	if (y->Left != Nil)
	{
		y->Left->Parent = x;
	}
	y->Parent = x->Parent;
	if (x->Parent == Nil)
	{
		Root = y;
	}
	else if(x == x->Parent->Left)
	{
		x->Parent->Left = y;
	}
	else
	{
		x->Parent->Right = y;
	}
	y->Left = x;
	x->Parent = y;
}
void RedBlackTree::RightRotate(RedBlackTreeNode* y)
{
	auto x = y->Left;
	y->Left = x->Right;
	if (x->Right != Nil)
	{
		x->Right->Parent = y;
	}
	x->Parent = y->Parent;
	if (y->Parent == Nil)
	{
		Root = x;
	}
	else if (y == y->Parent->Left)
	{
		y->Parent->Left = x;
	}
	else
	{
		y->Parent->Right = x;
	}
	x->Right = y;
	y->Parent = x;
}
void RedBlackTree::InsertFixUp(RedBlackTreeNode* z)
{
	while (z->Parent->Color == Color::Red)
	{
		if (z->Parent == z->Parent->Parent->Left)
		{
			auto y = z->Parent->Parent->Right;
			if (y->Color == Color::Red)
			{
				z->Parent->Color = Color::Black;
				y->Color = Color::Black;
				z->Parent->Parent->Color = Color::Red;
				z = z->Parent->Parent;
			}
			else
			{
				if (z == z->Parent->Right)
				{
					z = z->Parent;
					LeftRotate(z);
				}
				z->Parent->Color = Color::Black;
				z->Parent->Parent->Color = Color::Red;
				RightRotate(z->Parent->Parent);
			}
		}
		else
		{
			auto y = z->Parent->Parent->Left;
			if (y->Color == Color::Red)
			{
				z->Parent->Color = Color::Black;
				y->Color = Color::Black;
				z->Parent->Parent->Color = Color::Red;
				z = z->Parent->Parent;
			}
			else
			{
				if (z == z->Parent->Left)
				{
					z = z->Parent;
					RightRotate(z);
				}
				z->Parent->Color = Color::Black;
				z->Parent->Parent->Color = Color::Red;
				LeftRotate(z->Parent->Parent);
			}
		}
	}
	Root->Color = Color::Black;
}
void RedBlackTree::DeleteFixUp(RedBlackTreeNode* x)
{
	while (x != Root && x->Color == Color::Black)
	{
		if (x == x->Parent->Left)
		{
			auto w = x->Parent->Right;
			if (w->Color == Color::Red)					//case 1	=> case 2¡¢3¡¢4
			{
				w->Color = Color::Black;
				x->Parent->Color = Color::Red;
				LeftRotate(x->Parent);
			}
			else // w->Color == Color::Black
			{
				if (w->Left->Color == Color::Black && w->Right->Color == Color::Black)		//case 2
				{
					w->Color = Color::Red;
					x = x->Parent;
				}
				else if (w->Right->Color == Color::Black)		//case 3
				{
					w->Left->Color = Color::Black;
					w->Color = Color::Red;
					RightRotate(w);
				}
				else //w->Right->Color == Color::Red			//case 4
				{
					w->Color = x->Parent->Color;
					x->Parent->Color = Color::Black;
					w->Right->Color = Color::Black;
					LeftRotate(x->Parent);
					x = Root;
				}
			}
		}
		else
		{
			auto w = x->Parent->Left;
			if (w->Color == Color::Red)
			{
				w->Color = Color::Black;
				x->Parent->Color = Color::Red;
				RightRotate(x->Parent);
}
			else // w->Color == Color::Black
			{
				if (w->Left->Color == Color::Black && w->Right->Color == Color::Black)
				{
					w->Color = Color::Red;
					x = x->Parent;
				}
				else if (w->Left->Color == Color::Black)
				{
					w->Right->Color = Color::Black;
					w->Color = Color::Red;
					LeftRotate(w);
				}
				else // w->Left->Color == Color::Red
				{
					w->Color = x->Parent->Color;
					x->Parent->Color = Color::Black;
					w->Left->Color = Color::Black;
					RightRotate(x->Parent);
					x = Root;
				}
			}
		}
	}
	x->Color = Color::Black;
}
void RedBlackTree::Transplant(RedBlackTreeNode* u, RedBlackTreeNode* v)
{
	if (u->Parent == Nil)
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
	
	v->Parent = u->Parent;
}

void RedBlackTree::Release(RedBlackTreeNode* x)
{
	if (x != Nil)
	{
		Release(x->Left);
		Release(x->Right);
		delete x;
	}
}

void TestRedBlackTree()
{
	vector<RedBlackTreeNode*> nodes;
	for (auto i = 0; i < 15; i++)
	{
		nodes.push_back(new RedBlackTreeNode(i, Color::Red));
	}

	RedBlackTree* tree = new RedBlackTree();
	for (auto node : nodes)
	{
		tree->Insert(node);
		tree->Report();
	}
	
	for (auto node : nodes)
	{
		tree->Delete(node);
		tree->Report();
	}


}

