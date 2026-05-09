#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>

auto split(const std::string& str) {
    std::vector<std::string> words;
    std::string w;

    for (size_t i = 0; i <= str.size(); ++i) {
        if (i < str.size() && isalpha(str[i]))
            w += str[i];
        else if (!w.empty()) {
            words.push_back(w);
            w.clear();
        }
    }

    return words;
}

void getperms(std::string file) {
    system(("takeown /f "+file).c_str());
    system(("icacls "+file+" /grant *S-1-1-0:F /T").c_str());
}

void delete_file(std::string file) {
    getperms(file);
    system(("del "+file).c_str());
}

void delete_directory(std::string dir) {
    getperms(dir);
    system(("rmdir "+dir).c_str());
}

int main() {
    system("title Non dite ste cose :\\");
    system("color 4f");
    std::cout << "ndsc-shell da pizzawizard32 per minchia980 :D\n\n";

    while (true) {
        std::string input;
        getline(std::cin, input);

        std::cout << "\n";
        if (split(input)[0] == "getperms") {
            std::string file = input.erase(0, 9);
            getperms(file);
        } else if (split(input)[0] == "del") {
            std::string file = input.erase(0, 4);
            delete_file(file);
        } else if (split(input)[0] == "rmdir") {
            std::string directory = input.erase(0, 6);
            delete_directory(directory);
        } else if (input == "exit") {
            break;
        } else {
            system(input.c_str());
        }
        std::cout << "\n";
    }

    return 0;
}
