#include "InsertionSort.h"
#include "Common.h"
#include <iostream>
using namespace std;

void InsertionSort(int* a, int len)
{
    for (int j = 1; j < len; j++)
    {
        int key = a[j];
        int i = j;
        while (--i >= 0 && a[i]> key)
        {
            a[i + 1] = a[i];
        }
        a[i + 1] = key;
    }
}

void TestInsertionSort()
{
    int a[] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    int len = sizeof(a) / sizeof(int);
    InsertionSort(a, len);
    Print(a, len);
}