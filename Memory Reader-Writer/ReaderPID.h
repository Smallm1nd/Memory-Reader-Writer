#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <string>

DWORD get_pid(std::wstring& target_name);