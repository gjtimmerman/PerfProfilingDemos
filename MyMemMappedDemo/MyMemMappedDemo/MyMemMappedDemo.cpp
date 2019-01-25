// MyMemMappedDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	getchar();
	HANDLE hFile;
	HANDLE memMappedFile;
	hFile = CreateFile(L"dscn1098_2.jpg", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == NULL)
	{
		printf("File not opened!");
		return 0;
	}
	getchar();
	memMappedFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
//	memMappedFile = CreateFileMapping(NULL, NULL, PAGE_READWRITE, 0, 40960000, NULL);
	if (memMappedFile == NULL)
	{
		printf("MemoryMappedFile not opened!");
		return 0;
	}
	LPVOID myPointer = MapViewOfFile(memMappedFile, FILE_MAP_READ, 0, 0, 0);
//	LPVOID myPointer = MapViewOfFile(memMappedFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (myPointer == NULL)
	{
		printf("MemoryMappedFile not opened!");
		return 0;
	}
	getchar();
	UnmapViewOfFile(myPointer);
	CloseHandle(memMappedFile);
	CloseHandle(hFile);
	getchar();
    return 0;
}

