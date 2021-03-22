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
