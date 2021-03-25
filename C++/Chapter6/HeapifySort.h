#pragma once

int Parent(int i);
int Left(int i);
int Right(int i);

template<typename T>
void Exchange(T* A, int index1, int index2)
{
	T temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}

template<typename T>
void MaxHeapify(T* A, int len, int index)
{
	int l = Left(index);
	int r = Right(index);
	int maxIndex = index;
	if (l < len && A[l] > A[maxIndex])
	{
		maxIndex = l;
	}
	if (r < len && A[r] > A[maxIndex])
	{
		maxIndex = r;
	}
	if (maxIndex != index)
	{
		Exchange(A, index, maxIndex);
		MaxHeapify(A, len, maxIndex);
	}
}

template<typename T>
void BuildMaxHeap(T* A, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(A, len, i);
	}
}

template<typename T>
void MinHeapify(T* A, int len, int index)
{
	int l = Left(index);
	int r = Right(index);
	int minIndex = index;
	if (l < len && A[l] < A[minIndex])
	{
		minIndex = l;
	}
	if (r < len && A[r] < A[minIndex])
	{
		minIndex = r;
	}
	if (minIndex != index)
	{
		int temp = A[index];
		A[index] = A[minIndex];
		A[minIndex] = temp;
		MinHeapify(A, len, minIndex);
	}
}

template<typename T>
void BuildMinHeap(T* A, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		MinHeapify(A, len, i);
	}
}

template<typename T>
void HeapSort(T* A, int len)
{
	BuildMaxHeap(A, len);
	for (int i = len - 1; i > 0; i--)
	{
		Exchange(A, 0, i);
		MaxHeapify(A, --len, 0);
	}
}

void TestBuildMaxHeap();

void TestBuildMinHeap();

void TestHeapSort();

