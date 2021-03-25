#pragma once
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void PrintVector(const vector<T>& a)
{
	for (auto& item : a)
	{
		cout << item << "  ";
	}
	cout << endl;
}

template<typename T>
void Print(T* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

template<typename T>
void Print(T** a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
void Exchange(T* A, int index1, int index2)
{
	T temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}