#include "RandomizedSelect.h"
#include "QuickSort.h"
#include "Common.h"


int RandomizedSelect(int* A, int start, int end, int index)
{
	if (end - start <= 1)
	{
		return A[start];
	}
	int mid = RandomizedPartition(A, start, end);
	if (index == mid - start + 1)
	{
		return A[mid];
	}
	else if (index < mid - start + 1)
	{
		return RandomizedSelect(A, start, mid, index);
	}
	else
	{
		return RandomizedSelect(A, mid + 1, end, index - (mid - start + 1));
	}
}


void TestRandomizedSelect()
{
	int a[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int len = sizeof(a) / sizeof(int);
	cout << "the smallest number is :" << RandomizedSelect(a, 0, len, 1) << endl;
	cout << "the 3rd smallest number is :" << RandomizedSelect(a, 0, len, 3) << endl;
	Print(a, len);
}
