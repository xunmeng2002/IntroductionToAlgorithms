#include "Common.h"


int Random(int x)
{
	return rand() % x;
}
int Random(int start, int end)
{
	return (start + rand() % (end - start));
}