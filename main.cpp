#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// Функция проверяет, можно ли строку s полностью преобразовать в число типа double
bool isDouble(const string& s) {
    try {
        size_t pos;
        stod(s, &pos);         // пытаемся преобразовать строку в double
        return pos == s.size(); // проверяем, что ВСЯ строка была числом
    } catch (...) {
        return false;           // если ошибка — значит, это не корректное double-число
    }
}

// Функция проверяет, можно ли строку s полностью преобразовать в целое число
bool isInteger(const string& s) {
    try {
        size_t pos;          // переменная для хранения позиции первого нецифрового символа
        stoll(s, &pos);       // пытаемся преобразовать строку в int
                             // если удачно, pos будет указывать на следующий символ после числа

        return pos == s.size();  // если вся строка — число, pos будет равен длине строки
    } catch (...) {
        return false;  // если преобразование вызвало исключение (например, не число) — возвращаем false
    }
}

// Функция для вызова редактора файла txt
void openEditor(const string& filename) {
#ifdef _WIN32
    // Windows: откроется блокнот
    system(("notepad " + filename).c_str());
#elif __APPLE__
    // macOS: откроется TextEdit
    system(("open -e " + filename).c_str());
#else
    // Linux или Unix-подобная: откроется nano
    system(("nano " + filename).c_str());
#endif
}

int main() {
    cout << "LOKISE OS: ENTER ? FOR MORE INFORMATION" << endl;

    string command, file, operation;

    while (true) {
        cout << endl << "ADMINISTRATOR $~> ";
		
        cin >> command;

        if (command == "?" || command == "help" || command == "HELP" || command == "Help")
		{
            puts("\nINFORMATION: LOKISE OS V1.0");
            puts("INFORMATION: CREATED BY PYAKOVN@RO.RU AND LOKISE@GMAIL.COM\n\n");
        }
		
		else if (command =="CALC" || command == "calc" || command == "Calc")	
		{
			long long kolvo, tek = 1;
			string first, second;
			
			cout << "\nCALCULATOR: ENTER THE FIRST NUMBER" << endl << ">";

			cin >> first;

			cout << "CALCULATOR: ENTER THE OPERARION + - * / (DO NOT ENTER A NUMBERS, LETTERS OR MORE THAN ONE OPERATION! THE SYSTEM WILL GO CRAZY BECAUSE OF THIS!)" << endl << ">";
			
			cin >> operation;
			
			cout << "CALCULATOR: ENTER THE SECOND NUMBER" << endl << ">";
			
			cin >> second;

			if (!isDouble(first) || !isDouble(second)) 
			{
				if (!isDouble(first)) {
					cout << "CALCULATOR: COMMAND NOT FOUND: " << first;
				} else {
					cout << "CALCULATOR: COMMAND NOT FOUND: " << second;
				}
			}
			else
			{
				double first_num = stod(first);
				double second_num = stod(second);

				if (operation == "+")
				{
					cout << first_num << operation << second_num << "=" << first_num + second_num;
				}
				else if (operation == "*")
				{
					cout << first_num << operation << second_num << "=" << first_num * second_num;
				}
				else if (operation == "-")
				{
					cout << first_num << operation << second_num << "=" << first_num - second_num;
				}
				else if (operation == "/")
				{
					cout << first_num << operation << second_num << "=" << first_num / second_num;
				} 

				else 
				{
					cout << "CALCULATOR: COMMAND NOT FOUND: " << operation;
				}
			}
		}
			
		else if (command == "RAND" || command == "rand" || command == "Rand")
		{	
			cout << "\nRANDOMISER: ENTER THE NUMBER OF NUMBERS IN A RANDOM NUMBER" << endl << ">";

			string kolvo;

			cin >> kolvo;

			if (!isInteger(kolvo)) 
			{
				cout << "RANDOMIZER: COMMAND NOT FOUND: " << kolvo;
			}
			else
			{
				long long kolvo_num = stoll(kolvo);
				
				srand(time(0));

				cout << "RANDOMIZER: RANDOM NUMBER: " << 1 + rand() % 9;

				kolvo_num--;

				for (long long tek = 1; tek <= kolvo_num; tek++)
				{
					cout << 0 + rand() % 9; 
				}
			}
		}

		else if (command == "TEXT" || command == "Text" || command == "text")
		{
			cout << "TEXT EDITOR: ENTER THE NAME OF THE FILE" << endl << ">";

			string file_name;

			while (!fs::exists(file_name)) 
			{
				cin >> file_name;

				if (!fs::exists(file_name)) 
				{
					cout << "TEXT EDITOR: FILE NOT FOUND: " << file_name << endl << ">";
				}
			}

			openEditor(file_name);
		}
		
		else if (command == "EXIT" || command == "exit" || command == "Exit")
		{
			cout << "\nLOKISE OS: THE USER HAS LOGGED OUT OF THE SYSTEM!" << endl << "EXIT CODE:0";
			sleep(2);

			cout << endl << "LOKISE OS: 3 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: 2 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: 1 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: LOGOUT...";
			sleep(1);

			return 0;
		} 
					
		else if (command == "CRASH" || command == "crash" || command == "Crash") 
		{
			cout << "\nLOKISE OS: ERROR! RAM CANNOT BE READ!" << endl << "EXIT CODE:9";
			sleep(2);

			cout << endl << "LOKISE OS: 3 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: 2 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: 1 SECOND UNTIL LOGOUT...";
			sleep(1);

			cout << endl << "LOKISE OS: LOGOUT...";
			sleep(1);

			return 9;
		}

		else
		{
			cout << "LOKISE OS: COMMAND NOT FOUND: " << command;
		}
	}
}
