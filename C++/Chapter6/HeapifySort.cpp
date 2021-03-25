#include "HeapifySort.h"
#include "Common.h"

int Parent(int i)
{
	return (i - 1) / 2;
}
int Left(int i)
{
	return 2 * i + 1;
}
int Right(int i)
{
	return 2 * (i + 1);
}

void TestBuildMaxHeap()
{
	int a[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int len = sizeof(a) / sizeof(int);
	BuildMaxHeap(a, len);
	Print(a, len);
}

void TestBuildMinHeap()
{
	int a[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int len = sizeof(a) / sizeof(int);
	BuildMinHeap(a, len);
	Print(a, len);
}

void TestHeapSort()
{
	int a[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int len = sizeof(a) / sizeof(int);
	HeapSort(a, len);
	Print(a, len);
}
