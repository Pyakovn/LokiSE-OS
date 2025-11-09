#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <stdexcept>
#include <thread>
#include <chrono>



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


void showHelp() {
    puts("\n=================================== LOKISE OS HELP =================================");
    puts("VERSION: LOKISE OS V1.0");
    puts("CREATED BY: PYAKOVN@RO.RU");
    puts("\nAVAILABLE COMMANDS:");
    puts("--------------------------------------------------------------------------------");
    puts("? / help / HELP / Help    - Display this help screen with all commands");
    puts("                          description and system information.");
    puts("");
    puts("CALC / calc / Calc        - Launch the calculator. Prompts for:");
    puts("                          1. First number (double or integer)");
    puts("                          2. Operation (+, -, *, /)");
    puts("                          3. Second number (double or integer)");
    puts("                          Supports decimal numbers and basic arithmetic.");
    puts("");
    puts("RAND / rand / Rand        - Generate a random number with specified");
    puts("                          number of digits. Prompts for digit count");
    puts("                          (must be positive integer). First digit is");
    puts("                          1–9, subsequent digits are 0–9.");
    puts("");
    puts("TEXT / Text / text        - Open a text file in the system's default");
    puts("                          editor. Prompts for filename. File must exist");
    puts("                          in current directory.");
    puts("");
    puts("EXIT / exit / Exit        - Gracefully exit the system. Displays logout");
    puts("                          countdown (3, 2, 1 seconds) and returns");
    puts("                          exit code 0.");
    puts("");
    puts("CRASH / crash / Crash     - Simulate a system crash. Displays error");
    puts("                          message, logout countdown, and returns exit");
    puts("                          code 9 (error state).");
}


// Функция генерации случайного числа
void generateRandomNumber() {
    int digits;
    cout << "Enter number of digits: ";
    cin >> digits;

    if (digits <= 0) {
        cout << "Invalid digit count!" << endl;
        return;
    }

    srand(time(0));
    string randomNumber = to_string(rand() % 9 + 1);  // Первая цифра 1-9

    for (int i = 1; i < digits; i++) {
        randomNumber += to_string(rand() % 10);  // Остальные цифры 0-9
    }

    cout << "Generated random number: " << randomNumber << endl;
}
// Функция имитации сбоя системы
void simulateCrash() {
    cout << "\\nCRITICAL SYSTEM ERROR!\\n";
    cout << "System is shutting down...\\n";
    for (int i = 3; i > 0; i--) {
        cout << "Shutdown in: " << i << " seconds\\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "SYSTEM CRASHED!\\n";
    exit(9);
}

int main() {
    cout << "LOKISE OS: ENTER ? FOR MORE INFORMATION\\n";

    string command, operation;

    while (true) {
        cout << "\\nADMINISTRATOR $~> ";
        cin >> command;

        if (command == "?" || command == "help" || command == "HELP" || command == "Help") {
            showHelp();
        }
        else if (command == "CALC" || command == "calc" || command == "Calc") {
            // Обработка калькулятора
            double num1, num2, result;
            char op;

            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter operation (+, -, *, /): ";
            cin >> op;
            cout << "Enter second number: ";
            cin >> num2;

            switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 != 0) result = num1 / num2;
                else {
                    cout << "Error: Division by zero!\\n";
                    continue;
                }
                break;
            default:
                cout << "Invalid operation!\\n";
                continue;
            }
            cout << "Result: " << result << "\\n";
        }
        else if (command == "RAND" || command == "rand" || command == "Rand") {
            generateRandomNumber();
        }
        else if (command == "TEXT" || command == "Text" || command == "text") {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            openEditor(filename);
        }
        else if (command == "EXIT" || command == "exit" || command == "Exit") {
            cout << "\\nLOKISE OS: THE USER HAS LOGGED OUT OF THE SYSTEM!\\n";
            cout << "EXIT CODE: 0\\n";
            for (int i = 3; i > 0; i--) {
                cout << "LOKISE OS: " << i << " SECOND UNTIL LOGOUT...\\n";
                this_thread::sleep_for(chrono::seconds(1));
            }
            return 0;
        }
        else if (command == "CRASH" || command == "crash" || command == "Crash") {
            simulateCrash();
        }
        else {
            cout << "UNKNOWN COMMAND: " << command << "\\n";
        }
    }
    return 0;
}