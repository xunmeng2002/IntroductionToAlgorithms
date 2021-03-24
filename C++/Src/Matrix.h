#pragma once
#include <stdio.h>
#include <iostream>

template<typename T>
class Matrix
{
public:
	Matrix()
	{
		Row = Column = 0;
		Item = nullptr;
	}
	Matrix(int row, int column)
	{
		Create(row, column);
	}
	Matrix(const Matrix<T>& other)
	{
		Row = other.Row;
		Column = other.Column;
		Item = new T * [Row];
		for (int i = 0; i < Row; i++)
		{
			Item[i] = new T[Column];
			::memcpy(Item[i], other.Item[i], sizeof(Item[i]));
		}
	}
	Matrix<T>& operator=(const Matrix<T>& other)
	{
		Row = other.Row;
		Column = other.Column;
		Item = new T * [Row];
		for (int i = 0; i < Row; i++)
		{
			Item[i] = new T[Column];
			::memcpy(Item[i], other.Item[i], sizeof(Item[i]));
		}
	}
	Matrix(Matrix<T>&& other)
	{
		Row = other.Row;
		Column = other.Column;
		Item = other.Item;
		other.Item = nullptr;
	}
	Matrix<T>& operator=(Matrix<T>&& other)
	{
		Row = other.Row;
		Column = other.Column;
		Item = other.Item;
		other.Item = nullptr;
	}
	~Matrix()
	{
		Release();
	}
	void Create(int row, int column)
	{
		Row = row;
		Column = column;
		Item = new T * [row];
		for (int i = 0; i < row; i++)
		{
			Item[i] = new T[column];
		}
	}
	void Release()
	{
		if (Item != nullptr)
		{
			for (int i = 0; i < Row; i++)
			{
				delete[] Item[i];
			}
			delete[] Item;
		}
		Item = nullptr;
		Row = 0;
		Column = 0;
	}
	void Resize(int row, int column)
	{
		if (row == Row && column == Column)
			return;
		Release();
		Create(row, column);
	}

	int* operator[](int i)
	{
		return Item[i];
	}
	Matrix<T> operator+(const Matrix<T>& other)
	{
		if (other.Row != Row || other.Column != Column)
			return Matrix<T>();
		Matrix<T> result(Row, Column);
		for (auto i = 0; i < Row; i++)
		{
			for (auto j = 0; j < Column; j++)
			{
				result[i][j] = Item[i][j] + other.Item[i][j];
			}
		}
		return std::move(result);
	}
	Matrix<T> operator-(const Matrix<T>& other)
	{
		if (other.Row != Row || other.Column != Column)
			return Matrix<T>();
		Matrix<T> result(Row, Column);
		for (auto i = 0; i < Row; i++)
		{
			for (auto j = 0; j < Column; j++)
			{
				result[i][j] = Item[i][j] - other.Item[i][j];
			}
		}
		return std::move(result);
	}
	Matrix<T> operator*(const Matrix<T>& other)
	{
		if (Column != other.Row)
			return Matrix<T>();
		Matrix<T> result(Row, other.Column);
		for (auto i = 0; i < Row; i++)
		{
			for (auto j = 0; j < other.Column; j++)
			{
				T key = 0;
				for (auto k = 0; k < Column; k++)
				{
					key += Item[i][k] * other.Item[k][j];
				}
				result[i][j] = key;
			}
		}
		return std::move(result);
	}
	int GetRow() { return Row; }
	int GetColumn() { return Column; }
	bool SetRowValue(int row, int* values)
	{
		if (row >= Row)
			return false;
		for (int i = 0; i < Column; i++)
		{
			Item[row][i] = values[i];
		}
		return true;
	}
	void SetValue(int** values)
	{
		for(auto i = 0; i < Row; i++)
			for (auto j = 0; j < Column; j++)
			{
				Item[i][j] = values[i][j];
			}
	}
	void Print(std::string name)
	{
		printf("%s:\n", name.c_str());
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				printf("%d\t", Item[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
private:
	int Row;
	int Column;

	T** Item;
};


void TestMatrix();