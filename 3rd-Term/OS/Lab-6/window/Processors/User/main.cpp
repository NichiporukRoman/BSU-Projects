#include<iostream>
#include <windows.h>
#include <winbase.h>
#include <tlhelp32.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

void setEnvironmentVariableToKill(LPCWSTR value)
{
    if (!SetEnvironmentVariableW(L"PROC_TO_KILL", value))
    {
        std::cerr << GetLastError() << '\n';
    }
}

std::vector<std::wstring> getItems(int argc, char *argv[])
{
    std::vector<std::wstring> args;

    for (int i = 1; i < argc; ++i)
    {
        int size = MultiByteToWideChar(CP_UTF8, 0, &argv[i][0], ((std::string)argv[i]).size(), NULL, 0);
        std::wstring wstring(size, 0);
        MultiByteToWideChar(CP_UTF8, 0, &argv[i][0], ((std::string)argv[i]).size(), &wstring[0], size);
        args.push_back(wstring);
    }
    return args;
}

std::string addArgsToFilePath(std::string commandLine, const std::vector<std::wstring> &args)
{
    for (auto arg : args)
    {
        commandLine += " " + std::string(arg.begin(), arg.end());
    }
    return commandLine;
}

    void startKiller(std::string cmd)
{
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {NULL};
    if (CreateProcessA(NULL, &cmd.front(), NULL,
                       NULL, FALSE, 0, NULL,
                       NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

    int main(int argc, char *argv[]) {
        setEnvironmentVariableToKill(L"opera.exe, chrome.exe");
        startKiller(addArgsToFilePath(
            "C:\\Users\\roman\\CLionProjects\\Killer\\cmake-build-debug\\Killer.exe",
            getItems(argc, argv)));
        setEnvironmentVariableToKill(NULL);

        //startKiller("C:\\Users\\roman\\CLionProjects\\Killer\\cmake-build-debug\\Killer.exe --name chrome.exe");
        return 0;
}
//Переменные EnvironmentVariable берутся из Killer.exe прописанные как переменные Program Argument