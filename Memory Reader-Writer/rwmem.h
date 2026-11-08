#pragma once

template<typename T>
T read_memory(HANDLE proc, LPCVOID addr);

template<typename T>
void write_memory(HANDLE proc, LPCVOID addr, T& val);

template<typename T>
DWORD protect_memory(HANDLE proc, LPCVOID addr, DWORD protect);

