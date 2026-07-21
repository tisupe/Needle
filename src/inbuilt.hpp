#include <filesystem>
#include <iostream>
#include <string>
#include <functional>
#include <map>

#include "handler.hpp"

using inBuiltFunctions = std::function<void(const std::vector<std::string>&)>;

inline void execute_exit(const std::vector<std::string> &parseArguments);
inline void execute_echo(const std::vector<std::string> &parseArguments);
inline void execute_type(const std::vector<std::string> &parseArguments);
inline void execute_pwd(const std::vector<std::string> &parseArguments);
inline void execute_cd(const std::vector<std::string> &parseArguments);

static std::map<std::string, inBuiltFunctions> inBuilt = {
    {"echo", execute_echo},
    {"exit", execute_exit},
    {"type", execute_type},
    {"pwd", execute_pwd},
    {"cd", execute_cd}
};

inline bool checkInbuilt(const std::string &command) {
    return inBuilt.count(command) > 0;
}

inline void execute_exit(const std::vector<std::string> &parseArguments) {
    exit(0);
}

inline void execute_echo(const std::vector<std::string> &parseArguments) {
    for (auto i = parseArguments.begin() + 1; i != parseArguments.end(); ++i) {
        std::cout << *i;
        if (std::next(i) != parseArguments.end()) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

inline void execute_type(const std::vector<std::string> &parseArguments) {
    if (parseArguments.size() < 2) {
        std::cerr << "type: missing argument\n";
    } else if (parseArguments.size() > 2) {
        std::cerr << "type: too many arguments\n";
    } else if (parseArguments.size() == 0) {
        std::cerr << "type: too few arguments\n";
    } else {
        std::string keyword = parseArguments[1];
        if (checkInbuilt(keyword)) {
            std::cout << keyword << " is a shell builtin\n";
        } else {
            std::string execPath = checkExecutable(keyword);
            if (!execPath.empty()) {
                std::cout << keyword << " is " << execPath << "\n";
            } else {
                std::cerr << keyword << ": not found\n";
            }
        }
    }
}

inline void execute_pwd(const std::vector<std::string> &parseArguments) {
    try{
    std::filesystem::path working_dir = std::filesystem::current_path();
    std::cout << working_dir.string() << "\n";
    }
    catch (const std::filesystem::filesystem_error &error) {
        std::cerr << "pwd: " << error.what() << "\n";
    }
}

inline void execute_cd(const std::vector<std::string> &parseArguments) {
    try {
        if (parseArguments[1]=="~") {
            try {
                std::filesystem::current_path(std::getenv("HOME"));
            }
            catch (std::filesystem::filesystem_error &error) {
                std::cout<<"cd: "<<parseArguments[1]<<": No such file or directory\n";
            }
        }
        else {
            std::filesystem::current_path(parseArguments[1]);
        }
    }
    catch (std::filesystem::filesystem_error &error) {
        std::cout<<"cd: "<<parseArguments[1]<<": No such file or directory\n";
    }
}
