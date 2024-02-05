#include <iostream>
#include <string.h>
#include <unistd.h>
#include <csignal>
#include <vector>
#include <sstream>
int main(int argc, char* argv[]) {
    setenv("PROC_TO_KILL", "thunderbird,firefox", true);
    system("../Killer");
    int pid = fork();
    switch (pid) {
        case -1:
            return -1;
        case 0:
            execv("../Killer", argv);
            _exit(0);
        default:
            system("../Killer");
            _exit(0);
    }
        unsetenv("PROC_TO_KILL"); 
    return 0;
}
