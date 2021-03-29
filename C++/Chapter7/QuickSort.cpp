#include "QuickSort.h"
#include "Common.h"

using namespace std;


void QuickSort(int* A, int start, int end)
{
	if (end - start > 1)
	{
		int mid = Partition(A, start, end);
		QuickSort(A, start, mid);
		QuickSort(A, mid + 1, end);
	}
}

int Partition(int* A, int start, int end)
{
	int x = A[end - 1];
	int i = start - 1;
	for (auto j = start; j < end - 1; j++)
	{
		if (A[j] <= x)
		{
			Exchange(A, ++i, j);
		}
	}
	Exchange(A, ++i, end - 1);
	return i;
}

void RandomizedQuickSort(int* A, int start, int end)
{
	if (end - start > 1)
	{
		int mid = RandomizedPartition(A, start, end);
		RandomizedQuickSort(A, start, mid);
		RandomizedQuickSort(A, mid + 1, end);
	}
}

int RandomizedPartition(int* A, int start, int end)
{
	int i = Random(start, end);
	Exchange(A, i, end);
	return Partition(A, start, end);
}

void TestQuickSort()
{
	int a[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int len = sizeof(a) / sizeof(int);
	QuickSort(a, 0, len);
	Print(a, len);
}

void TestRandomizedQuickSort()
{
	int a[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int len = sizeof(a) / sizeof(int);
	QuickSort(a, 0, len);
	Print(a, len);
}
