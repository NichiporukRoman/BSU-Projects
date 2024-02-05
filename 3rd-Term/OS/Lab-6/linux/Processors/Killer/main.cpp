#include <iostream>
#include <string.h>
#include <unistd.h>
#include <csignal>
#include <vector>
#include <sstream>

void killById(int id) {
    kill(id, SIGKILL);
}

void killByName(const char* name) {
    system((std::string() + "pkill -f " + name).c_str());
}

void empty_handler(int signal_id) {

}

int main(int argc, char* argv[]) {
    signal(SIGTERM, empty_handler);

    for (int i = 1; i < argc ; ++i) {
        if (strcmp(argv[i], "--name") == 0) {
            killByName(argv[i + 1]);
        }
        if (strcmp(argv[i], "--id") == 0) {
            killById(std::stoi(argv[i + 1]));
        }
    }

    char* c_proc_to_kill = getenv("PROC_TO_KILL");
    if (c_proc_to_kill != nullptr) {
        std::string proc_to_kill = c_proc_to_kill;
        std::vector<std::string> tokens;

        std::stringstream check1(proc_to_kill);

        std::string intermediate;

        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }

        for(int i = 0; i < tokens.size(); i++) {
            killByName(tokens[i].c_str());
        }
    }
    return 0;
}
