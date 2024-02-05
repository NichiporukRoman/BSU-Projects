#include <iostream>
#include <unistd.h>


std::string processes[] = {
        "/home/roman/CLionProjects/ProcessM/cmake-build-debug/ProcessM",
        "/home/roman/CLionProjects/ProcessA/cmake-build-debug/ProcessA",
        "/home/roman/CLionProjects/ProcessP/cmake-build-debug/ProcessP"};

int main() {
    int p[3];
    int pid;
    std::string line;
    for (int i = 0; i < 3; i++) {
        pipe(p);
        pid = fork();
        if (!pid) {
            dup2(p[1], 1);
            system(processes[i].c_str());
            exit(0);
        }
        dup2(p[0],0);
        close(p[1]);
    }
    system("/home/roman/CLionProjects/ProcessS/cmake-build-debug/ProcessS";
    return 0;
}
