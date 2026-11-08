#include <iostream>
#include "ReaderPID.h"
#include "rwmem.h"

int main()
{
    std::wstring name_exe = L"firefox.exe";
    DWORD pid =  get_pid(name_exe);
    printf("process id = %d", pid);

    HANDLE process = OpenProcess(PROCESS_VM_READ | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, false, pid);
    if (process == INVALID_HANDLE_VALUE)
    {
        printf("Failed open PID %d, error code %d", pid, GetLastError());
        return 1;
    }
    
    

    CloseHandle(process);
}
