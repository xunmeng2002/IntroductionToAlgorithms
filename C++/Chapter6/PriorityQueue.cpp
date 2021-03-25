#include "PriorityQueue.h"
#include <iostream>

using namespace std;


void TestPriorityQueue()
{
	PriorityQueue<int> queue;
	int A[] = { 13, 9, 5,  15, 12, 8, 7, 4, 0, 6, 2, 1 };
	int len = sizeof(A) / sizeof(int);
	queue.InitArray(A, len);

	queue.PrintHeap();
	cout << "HeapMaximum:" << queue.HeapMaximum() << endl;
	queue.PrintHeap();
	cout << "HeapExtractMax:" << queue.HeapExtractMax() << endl;
	queue.PrintHeap();
	cout << "HeapExtractMax:" << queue.HeapExtractMax() << endl;
	queue.PrintHeap();
	cout << "HeapExtractMax:" << queue.HeapExtractMax() << endl;
	queue.PrintHeap();

	queue.MaxHeapInsert(7);
	queue.PrintHeap();
	queue.MaxHeapInsert(13);
	queue.PrintHeap();
	queue.MaxHeapInsert(15);
	queue.PrintHeap();
}


