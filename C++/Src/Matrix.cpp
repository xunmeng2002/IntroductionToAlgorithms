#include "Matrix.h"

using namespace std;

void TestMatrix()
{
	Matrix<int> m1(2,2), m2(2, 2);
	int a[2] = { 1,2 };
	for (auto i = 0; i < 2;i++)
	{
		m1.SetRowValue(i, a);
		m2.SetRowValue(i, a);
	}
	m1.Print("m1");
	m2.Print("m2");
	Matrix<int> m3 = m1 + m2;
	m3.Print("m3");
	Matrix<int> m4 = m1 - m2;
	m4.Print("m4");

	Matrix<int> m5(2, 3), m6(3, 2);
	int b[3] = { 1, 2, 3 };
	int c[2] = { 1, 2 };
	m5.SetRowValue(0, b);
	m5.SetRowValue(1, b);
	m6.SetRowValue(0, c);
	m6.SetRowValue(1, c);
	m6.SetRowValue(2, c);
	Matrix<int> m7 = m5 * m6;
	m5.Print("m5");
	m6.Print("m6");
	m7.Print("m7");

	Matrix<int> m8(2, 3);
	int** p = new int* [2];
	p[0] = new int[3]{ 1, 2, 3 };
	p[1] = new int[3]{ 4, 5,6 };
	m8.SetValue(p);
	m8.Print("m8");

	Matrix<int> m9(m8), m10;
	m10 = m8;
	m9.Print("m9");
	m10.Print("m10");
}