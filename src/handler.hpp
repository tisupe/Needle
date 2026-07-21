#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>
#include <unistd.h>
#include <sys/wait.h>

inline std::string input() {
    std::string input;
    getline(std::cin, input);
    return input;
}

inline std::vector<std::string> arguments(const std::string &input) {
    std::vector<std::string> parseArguments;
    std::stringstream ss(input);
    std::string argument;
    bool inQuotes= false;

    while (ss >> argument) {
        if (argument == " ") {
            inQuotes = !inQuotes;
            continue;
        }
        if (argument == "'") {

        }
        parseArguments.push_back(argument);
    }
    return parseArguments;
}

inline std::string checkExecutable(const std::string &command) {
    std::stringstream env_path(getenv("PATH"));
    std::string directory;

    while (std::getline(env_path, directory, ':')) {
        std::string filePath = directory + "/" + command;
        if (std::filesystem::exists(filePath) &&
            (std::filesystem::status(filePath).permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
            return filePath;
        }
    }
    return "";
}

inline void executeExternal(const std::string& executable_path, std::vector<std::string> &parseArguments) {
    std::vector<char*> argv_cstrings;
    for (const std::string &arg_str : parseArguments) {
        argv_cstrings.push_back(const_cast<char*>(arg_str.c_str()));
    }
    argv_cstrings.push_back(nullptr);

    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Execution Failed: Failed to fork process.\n";
    } else if (pid == 0) {
        execvp(executable_path.c_str(), argv_cstrings.data());

        perror(argv_cstrings[0]);
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}
