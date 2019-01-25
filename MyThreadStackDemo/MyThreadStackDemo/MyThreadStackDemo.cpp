// MyThreadStackDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

HANDLE myEvent;

DWORD WINAPI ThreadProc(LPVOID p)
{
	WaitForSingleObject(myEvent, INFINITE);
	return 0;
}

int main()
{
	getchar();
	myEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	DWORD thid;
	HANDLE hTable[10];
	for (int i = 0; i < 10; i++)
		hTable[i] = CreateThread(NULL, 0, &ThreadProc, NULL, 0, &thid);
//		hTable[i] = CreateThread(NULL, 409600, &ThreadProc, NULL, 0, &thid);
	getchar();
	SetEvent(myEvent);
	for (int i = 0; i < 10; i++)
		CloseHandle(hTable[i]);
	getchar();
    return 0;
}

