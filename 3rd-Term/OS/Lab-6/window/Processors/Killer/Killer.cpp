#include "Killer.h"

void killProcessByIdentifier(int ProcessID){
    HANDLE process = OpenProcess(PROCESS_TERMINATE, false, ProcessID);
    if (process != nullptr) {
        TerminateProcess(process, 0);
        CloseHandle(process);
    }
}

void killProcessByName(const char* filename) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 describer;
    describer.dwSize = sizeof(PROCESSENTRY32);
    while (Process32Next(snapshot, &describer)) {
        if (strcmp(describer.szExeFile, filename) == 0) {
            HANDLE process = OpenProcess(PROCESS_TERMINATE, false, describer.th32ProcessID);
            if (process != nullptr) {
                TerminateProcess(process, 0);
                CloseHandle(process);
            }
        }
    }
    CloseHandle(snapshot);
}

void killProcessList(char** preyProcesses, int length){ //preyProcesses Aka PROC_TO_KILL
    for (int i = 0; i < length; ++i) {
        if (strcmp(preyProcesses[i], "--name") == 0){
            killProcessByName(preyProcesses[i + 1]);
        }
        if (strcmp(preyProcesses[i], "--id") == 0){
            killProcessByIdentifier(std::stoi(preyProcesses[i + 1]));
        }
    }
}

void killProcessByEnvironment()
{
    std::wstring buff;
    buff.resize(65535);
    DWORD size = GetEnvironmentVariableW(L"PROC_TO_KILL", &buff[0], size);
    buff.resize(size);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::string args = converter.to_bytes(buff);
    char *nextPtr = NULL;
    char *ptr = strtok_s(&args.front(), ",", &nextPtr);
    while (ptr != NULL)
    {
        killProcessByName(ptr);
        ptr = strtok_s(NULL, ",", &nextPtr);
    }
}

int main(int argc, char *argv[])
{
    killProcessByEnvironment();
    killProcessList(argv, argc);
    return 0;
}

