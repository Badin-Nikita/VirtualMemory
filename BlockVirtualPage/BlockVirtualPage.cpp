#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	LPVOID vm;
	SIZE_T size = 4096;

	vm = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
	if (!vm)
	{
		cout << "Virtual allocation failed." << endl;
		return GetLastError();
	}
	cout << "Virtual memory address: " << vm << endl;

	if (!VirtualLock(vm, size))
	{
		cout << "Virtual lock failed." << endl;
		return GetLastError();
	}
	cout << "Virtual memory locked." << endl;

	if (!VirtualUnlock(vm, size))
	{
		cout << "Virtual unlock failed." << endl;
		return GetLastError();
	}
	cout << "Virtual memory unlocked." << endl;
	if (!VirtualFree(vm, 0, MEM_RELEASE))
	{
		cout << "Memory release failed." << endl;
		return GetLastError();
	}
	cout << "Memory released." << endl;
	return 0;
}