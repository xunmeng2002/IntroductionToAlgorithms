#coding:utf-8
import sys


def MergeSort(A, start, end):
    if end - start > 1:
        mid = int((start + end)/2)
        MergeSort(A, start, mid)
        MergeSort(A, mid, end)
        Merge(A, start, mid, end)

def Merge(A, start, mid, end):
    l = A[start: mid]
    r = A[mid: end]
    l.append(sys.maxint)
    r.append(sys.maxint)
    j = 0
    k = 0
    for i in range(start, end):
        if l[j] <= r[k]:
            A[i] = l[j]
            j += 1
        else:
            A[i] = r[k]
            k += 1

A = [2, 4, 6, 8, 10, 1, 3, 5, 7, 9]
print(A)
MergeSort(A, 0, len(A))
print(A)
