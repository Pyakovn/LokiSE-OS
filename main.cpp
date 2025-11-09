#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <stdexcept>
#include <thread>  // Для sleep
#include <chrono>  // Для sleep

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
namespace fs = std::filesystem;

// Функция проверки, можно ли преобразовать строку в double
bool isDouble(const string& s) {
    if (s.empty()) return false;
    try {
        size_t pos;
        stod(s, &pos);
        return pos == s.size();
    }
    catch (const invalid_argument&) {
        return false;
    }
    catch (const out_of_range&) {
        return false;
    }
}

// Функция проверки, можно ли преобразовать строку в целое число
bool isInteger(const string& s) {
    if (s.empty()) return false;
    try {
        size_t pos;
        stoll(s, &pos);
        return pos == s.size();
    }
    catch (const invalid_argument&) {
        return false;
    }
    catch (const out_of_range&) {
        return false;
    }
}

// Функция открытия редактора для указанного файла
void openEditor(const string& filename) {
#ifdef _WIN32
    system(("notepad \"" + filename + "\"").c_str());
#elif __APPLE__
    system(("open -e \"" + filename + "\"").c_str());
#else
    system(("nano \"" + filename + "\"").c_str());
#endif
}

// Функция для обработки команд AMD
void handleAMDCommand(const string& command) {
    cout << "AMD Command: " << command << " processed" << endl;
}

int main() {
    cout << "LOKISE OS AMD Edition: ENTER ? FOR MORE INFORMATION" << endl;

    string command, operation;

    while (true) {
        cout << endl << "ADMINISTRATOR $~> ";
        cin >> command;

        if (command == "?" || command == "help" || command == "HELP" || command == "Help") {
            // Отображение справки
            puts("\n=================================== LOKISE OS AMD HELP =================================");
            puts("VERSION: LOKISE OS AMD V1.0");
            puts("CREATED BY: PYAKOVN@RO.RU");
            puts("\nAVAILABLE COMMANDS:");
            // ... (остальные команды)
        }
        else if (command == "CALC" || command == "calc" || command == "Calc") {
            // Обработка калькулятора
            // ...
        }
        else if (command == "RAND" || command == "rand" || command == "Rand") {
            // Генерация случайного числа
            // ...
        }
        else if (command == "TEXT" || command == "Text" || command == "text") {
            // Открытие текстового файла
            // ...
        }
        else if (command == "EXIT" || command == "exit" || command == "Exit") {
            // Выход из системы
            cout << "\nLOKISE OS: THE USER HAS LOGGED OUT OF THE SYSTEM!" << endl;
            cout << "EXIT CODE: 0" << endl;
            for (int i = 3; i > 0; i--) {
                cout << "LOKISE OS: " << i << " SECOND UNTIL LOGOUT..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            return 0;
        }
        else if (command == "AMD" || command == "amd" || command == "AMDINFO") {
            // Обработка AMD-специфичных команд
            handleAMDCommand(command);
        }
        else {
            cout << "UNKNOWN COMMAND: " << command << endl;
        }
    }
    return 0;
}