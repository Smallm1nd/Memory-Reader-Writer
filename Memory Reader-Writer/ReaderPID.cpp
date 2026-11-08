#include "ReaderPID.h"

DWORD get_pid(std::wstring& target_name) {
    DWORD pid = 0;
        
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    if (Process32FirstW(snapshot, &entry) == TRUE)
    {
        do {
            std::wstring current_process_name = entry.szExeFile;

            if (target_name == current_process_name)
            {
                pid = entry.th32ProcessID;
                break;
            }

        } while (Process32NextW(snapshot, &entry) == TRUE);
    }

    CloseHandle(snapshot);

    return pid;
}

