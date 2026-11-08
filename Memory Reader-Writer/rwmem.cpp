#include <Windows.h>
#include "rwmem.h"

template<typename T>
T read_memory(HANDLE proc, LPCVOID addr)
{
	T val;
	ReadProcessMemory(proc, addr, &val, sizeof(T), NULL);
	return val;
}

template<typename T>
void write_memory(HANDLE proc, LPCVOID addr, T& val)
{
	WriteProcessMemory(proc, addr, val, sizeof(val), NULL);
}

template<typename T>
DWORD protect_memory(HANDLE proc, LPCVOID addr, DWORD protect)
{
	DWORD old_protect = 0;
	VirtualProtectEx(proc, addr, sizeof(T), protect, &old_protect);
	return old_protect;
}
