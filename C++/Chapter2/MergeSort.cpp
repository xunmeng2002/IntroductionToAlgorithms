#include "MergeSort.h"
#include "Common.h"
#include <limits>


void MergeSort(int* a, int start, int end)
{
	if (end - start > 1)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid);
		MergeSort(a, mid, end);
		Merge2(a, start, mid, end);
	}
}

void Merge(int* a, int start, int mid, int end)
{
	int len1 = mid - start;
	int len2 = end - mid;
	int* l = new int[len1 + 1];
	int* r = new int[len2 + 1];
	int* p = a + start;
	int* p1 = l, * p2 = r;
	for (int i = 0; i < len1; i++)
	{
		*p1++ = *p++;
	}
	l[len1] = INT_MAX;
	for (int i = 0; i < len2; i++)
	{
		*p2++ = *p++;
	}
	r[len2] = INT_MAX;
	p = a + start;
	p1 = l;
	p2 = r;
	for(int i = start; i < end; i++)
	{
		if (*p1 <= *p2)
		{
			*p++ = *p1++;
		}
		else
		{
			*p++ = *p2++;
		}
	}
	delete[] l;
	delete[] r;
}
void Merge2(int* a, int start, int mid, int end)
{
	int len1 = mid - start;
	int len2 = end - mid;
	int* l = new int[len1];
	int* r = new int[len2];
	int* p = a + start;
	int * p1 = l, * p2 = r;
	for (int i = 0; i < len1; i++)
	{
		*p1++ = *p++;
	}
	for (int i = 0; i < len2; i++)
	{
		*p2++ = *p++;
	}
	p = a + start;
	p1 = l;
	p2 = r;
	for (int i = start; i < end; i++)
	{
		if (p1 == l + len1)
		{
			*p++ = *p2++;
		}
		else if (p2 == r + len2)
		{
			*p++ = *p1++;
		}
		else if (*p1 <= *p2)
		{
			*p++ = *p1++;
		}
		else
		{
			*p++ = *p2++;
		}
	}
	delete[] l;
	delete[] r;
}

void TestMergeSort()
{
	int a[] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int len = sizeof(a) / sizeof(int);
	MergeSort(a, 0, len);
	Print(a, len);
}

