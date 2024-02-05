#ifndef KILLER_KILLER_H
#define KILLER_KILLER_H
#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string>
#include <locale>
#include <codecvt>
#include <iostream>

void killProcessByIdentifier(int ProcessID);
void killProcessByName(const char* filename);
void killProcessList(char** preyProcesses, int length);
void killProcessByEnvironment();

#endif //KILLER_KILLER_H
