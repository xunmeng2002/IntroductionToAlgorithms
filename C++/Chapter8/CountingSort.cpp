#include "CountingSort.h"
#include "Common.h"


void CountingSort(int* A, int* B, int len, int maxItem)
{
	int* C = new int[maxItem + 1LL];
	for (auto i = 0; i <= maxItem; i++)
	{
		C[i] = 0;
	}
	for (auto i = 0; i < len; i++)
	{
		C[A[i]] += 1;
	}
	C[0] -= 1;
	for (auto i = 1; i <= maxItem; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (auto i = 0; i < len; i++)
	{
		B[C[A[i]]] = A[i];
		C[A[i]] -= 1;
	}
}

void TestCountingSort()
{
	int a[] = { 2, 18, 7, 1, 3, 5, 6, 4, 0 };
	int len = sizeof(a) / sizeof(int);
	int* b = new int[len];
	CountingSort(a, b, len, 18);
	Print(a, len);
	Print(b, len);
}
