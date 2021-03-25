#pragma once
#include "HeapifySort.h"
#include "Common.h"

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue()
	{
		Array = nullptr;
		HeapSize = 0;
		Length = 0;
	}
	PriorityQueue(T* A, int len)
	{
		Length = len * 2LL;
		Array = new T[Length]{ 0 };
		
		HeapSize = len;
		memcpy(Array, A, sizeof(T) * len);

		BuildMaxHeap(Array, HeapSize);
	}
	~PriorityQueue()
	{
		if (Array != nullptr)
		{
			delete Array;
		}
		Array = nullptr;
		HeapSize = 0;
		Length = 0;
	}
	void InitArray(T* A, int len)
	{
		if (len > Length)
		{
			delete[] Array;
			Length = len * 2LL;
			Array = new T[Length];
		}
		else
		{
			memset(Array, 0, sizeof(T) * Length);
		}
		HeapSize = len;
		memcpy(Array, A, sizeof(T) * len);

		BuildMaxHeap(Array, HeapSize);
	}

	T HeapMaximum()
	{
		return Array[0];
	}
	T HeapExtractMax()
	{
		if (HeapSize < 1)
		{
			throw exception("heap underflow");
		}
		T max = Array[0];
		Array[0] = Array[HeapSize - 1];
		HeapSize -= 1;
		MaxHeapify(Array, HeapSize, 0);
		return max;
	}
	void HeapIncreaseKey(int index, int key)
	{
		if (key < Array[index])
		{
			throw exception("new key is smaller than current key");
		}
		Array[index] = key;
		while (index > 0 && Array[Parent(index)] < Array[index])
		{
			Exchange(Array, Parent(index), index);
			index = Parent(index);
		}
	}
	void MaxHeapInsert(T key)
	{
		if (HeapSize == Length)
		{
			ExtendArray();
		}
		Array[HeapSize] = key;
		HeapSize += 1;

		HeapIncreaseKey(HeapSize - 1, key);
	}

	void PrintHeap()
	{
		Print(Array, HeapSize);
	}
private:
	void ExtendArray()
	{
		T* A = new T[Length * 2LL];
		memcpy(A, Array, sizeof(T) * Length);
		delete[] Array;
		Array = A;
		Length *= 2;
	}
	
private:
	T* Array;
	int HeapSize;
	int Length;
};

void TestPriorityQueue();
