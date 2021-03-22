#coding:utf-8


def InsertionSort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key


A = [2, 4, 6, 8, 10, 1, 3, 5, 7, 9]
print(A)
InsertionSort(A)
print(A)
