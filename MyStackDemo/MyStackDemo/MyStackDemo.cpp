// MyStackDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern int j = 0;

void f(int i)
{
	if (i >= 129000)
		return;
	f(i + 1);
	j += i;
}

int main()
{
	getchar();
	f(0);
	printf("%d\n", j);
	getchar();
    return 0;
}

