#include "FindMaximumSubArray.h"
#include <stdio.h>

using namespace std;

std::tuple<int, int, int> FindMaximumSubArray(int* a, int start, int end)
{
	if (end - start > 1)
	{
		int mid = (start + end) / 2;
		auto left = FindMaximumSubArray(a, start, mid);
		auto right = FindMaximumSubArray(a, mid, end);
		auto cross = FindMaxCrossingSubArray(a, start, mid, end);
		if (get<2>(left) >= get<2>(right) && get<2>(left) >= get<2>(cross))
		{
			return left;
		}
		else if (get<2>(right) >= get<2>(left) && get<2>(right) >= get<2>(cross))
		{
			return right;
		}
		else
		{
			return cross;
		}
	}
	else
	{
		return tuple<int, int, int>(start, end, a[start]);
	}
}

std::tuple<int, int, int> FindMaxCrossingSubArray(int* a, int start, int mid, int end)
{
	int max_low_sum = a[mid - 1];
	int max_low_index = mid - 1;
	int sum = 0;
	for (int i = mid - 1; i >= 0; i--)
	{
		sum += a[i];
		if (sum > max_low_sum)
		{
			max_low_sum = sum;
			max_low_index = i;
		}
	}
	int max_high_sum = a[mid];
	int max_high_index = mid;
	sum = 0;
	for (int i = mid; i < end; i++)
	{
		sum += a[i];
		if (sum > max_high_sum)
		{
			max_high_sum = sum;
			max_high_index = i;
		}
	}
	return tuple<int, int, int>(max_low_index, max_high_index, max_low_sum + max_high_sum);
}


void TestFindMaximumSubArray()
{
	int a[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int len = sizeof(a) / sizeof(int);
	auto result = FindMaximumSubArray(a, 0, len);
	printf("left_index:%d, right_index:%d, max_sum:%d\n", get<0>(result), get<1>(result), get<2>(result));
}
