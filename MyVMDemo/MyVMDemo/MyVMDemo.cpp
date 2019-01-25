// MyVMDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int c;
	c = getchar();
	LPVOID address = VirtualAlloc(NULL, 40960000, MEM_RESERVE, PAGE_READWRITE);
	DWORD err;
	if (address == NULL)
	{
		err = GetLastError();
		printf("%x\n", err);
	}
	else
		printf("%p\n", address);
	c = getchar();
	address = VirtualAlloc(address, 40960000, MEM_COMMIT, PAGE_READWRITE);
	if (address == NULL)
	{
		err = GetLastError();
		printf("%x\n", err);
		return 0;
	}
	else
		printf("%p\n", address);
	c = getchar();
	for (int i = 0; i < 10240000; i++)
		((int*)address)[i] = i;
	c = getchar();
	VirtualFree(address, 40960000, MEM_DECOMMIT);
	c = getchar();
	VirtualFree(address, 0, MEM_RELEASE);
	c = getchar();
	return 0;
}

