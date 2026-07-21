#include "inbuilt.hpp"
using namespace std;

int main() {
    cout << unitbuf;
    cerr << unitbuf;

    while (true) {
        cout << "$ ";

        string parseInput = input();
        vector<string> parseArguments = arguments(parseInput);

        if (parseArguments.empty()) {
            continue;
        }

        string parseCommand = parseArguments[0];
        bool isInbuilt = checkInbuilt(parseCommand);

        if (inBuilt.count(parseCommand)) {
            inBuilt[parseCommand](parseArguments);
        } else {
            string execPath = checkExecutable(parseCommand);

            if (!execPath.empty()) {
                parseArguments[0] = parseCommand;
                executeExternal(execPath, parseArguments);
            } else {
                cerr << parseCommand << ": command not found\n";
            }
        }
    }
    return 0;
}
