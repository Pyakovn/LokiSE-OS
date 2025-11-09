#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// ??????? ?????????, ????? ?? ?????? s ????????? ????????????? ? ????? ???? double
bool isDouble(const string& s) {
    try {
        size_t pos;
        stod(s, &pos);         // ???????? ????????????? ?????? ? double
        return pos == s.size(); // ?????????, ??? ??? ?????? ???? ??????
    } catch (...) {
        return false;           // ???? ?????? — ??????, ??? ?? ?????????? double-?????
    }
}

// ??????? ?????????, ????? ?? ?????? s ????????? ????????????? ? ????? ?????
bool isInteger(const string& s) {
    try {
        size_t pos;          // ?????????? ??? ???????? ??????? ??????? ??????????? ???????
        stoll(s, &pos);       // ???????? ????????????? ?????? ? int
                             // ???? ??????, pos ????? ????????? ?? ????????? ?????? ????? ?????

        return pos == s.size();  // ???? ??? ?????? — ?????, pos ????? ????? ????? ??????
    } catch (...) {
        return false;  // ???? ?????????????? ??????? ?????????? (????????, ?? ?????) — ?????????? false
    }
}

// ??????? ??? ?????? ????????? ????? txt
void openEditor(const string& filename) {
#ifdef _WIN32
    // Windows: ????????? ???????
    system(("notepad " + filename).c_str());
#elif __APPLE__
    // macOS: ????????? TextEdit
    system(("open -e " + filename).c_str());
#else
    // Linux ??? Unix-????????: ????????? nano
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
            else if (command == "?" || command == "help" || command == "HELP" || command == "Help") {
    puts("\n=================================== LOKISE OS HELP =================================");
    puts("VERSION: LOKISE OS V1.0");
    puts("CREATED BY: PYAKOVN@RO.RU AND LOKISE@GMAIL.COM");
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
    puts("                          in current directory. On Windows: Notepad,");
    puts("                          on macOS: TextEdit, on Linux/Unix: nano.");
    puts("");
    puts("EXIT / exit / Exit        - Gracefully exit the system. Displays logout");
    puts("                          countdown (3, 2, 1 seconds) and returns");
    puts("                          exit code 0.");
    puts("");
    puts("CRASH / crash / Crash     - Simulate a system crash. Displays error");
    puts("                          message, logout countdown, and returns exit");
    puts("                          code 9 (error state).");
    puts("--------------------------------------------------------------------------------");
    puts("NOTES:");
    puts("- All commands are case-insensitive.");
    puts("- Invalid input is handled with appropriate error messages.");
    puts("- Use quotation marks if filename contains spaces (not supported in this");
    puts("  version - files with spaces may cause issues in editor launch).");
    puts("============================================================================");
}
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
