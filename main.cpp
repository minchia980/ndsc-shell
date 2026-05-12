#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>

std::string cd = "C:\\";

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
    system(("cd "+cd+" && del "+file).c_str());
}

void delete_directory(std::string dir) {
    getperms(dir);
    system(("cd "+cd+" && rmdir "+dir).c_str());
}

void rainbow() {
    system("color 4f");
    Sleep(0500);
    system("color 6f");
    Sleep(0500);
    system("color 2f");
    Sleep(0500);
    system("color 1f");
    Sleep(0500);
    system("color 5f");
    Sleep(0500);
}

int main() {
    system("title minchia980 :D");
    system("color 4f");
    std::cout << "minchia980/ndsc 1.0.0-beta.1\nper informazioni su questo aggiornamento, usa il comando \"ver\".\n\n";
    PlaySound(TEXT("startup.wav"), NULL, SND_FILENAME | SND_ASYNC);

    while (true) {
        std::string input;
        std::cout << cd << " > ";
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
        } else if (input == "rdi") {
            cd = "C:\\";
        } else if (split(input)[0] == "cd") {
            std::string directory = input.erase(0, 3);
            cd = cd+directory+"\\";
        } else if (input == "ver") {
            system("notepad version.txt");
        } else if (input == "instructions") {
            system("notepad instructions.txt");
        } else if (input == "rainbow") {
            std::string answer;
            std::cout << "warning: flashing lights\nattenzione: luci lampeggianti.\n\nscrivi \"ok\" per continuare\nwrite \"ok\" to continue\n";
            getline(std::cin, answer);
            if (answer == "ok") {
                while (true)
                    rainbow();
            }
        } else if (input == "exit") {
            break;
        } else {
            system(("cd "+cd+" && "+input).c_str());
        }
        std::cout << "\n";
    }

    return 0;
}
