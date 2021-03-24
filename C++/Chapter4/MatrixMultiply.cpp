#include "MatrixMultiply.h"
#include "Common.h"

void SquareMatrixMultiply(int** a, int** b, int** c, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
}

void TestSquareMatrixMultiply()
{
	int** a = new int* [2];
	int** b = new int* [2];
	int** c = new int* [2];
	for (auto i = 0; i < 2; i++)
	{
		a[i] = new int[2]{ 0 };
		b[i] = new int[2]{ 0 };
		c[i] = new int[2]{ 0 };
	}
	a[0] = new int[2]{ 1,3 };
	a[1] = new int[2]{ 7,5 };
	b[0] = new int[2]{ 6,8 };
	b[1] = new int[2]{ 4,2 };
	c[0] = new int[2]{ 0 };
	c[1] = new int[2]{ 0 };
	SquareMatrixMultiply(a, b, c, 2);
	Print(a, 2, 2);
	Print(b, 2, 2);
	Print(c, 2, 2);
}
