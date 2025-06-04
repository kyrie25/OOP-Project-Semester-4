#include "ApplicationController.h"
#include <conio.h>
#include <iostream>

using namespace std;

void ApplicationController::showMainMenu()
{

}

void ApplicationController::handleLogin()
{
    
}

void ApplicationController::run()
{
    int option = 1;

	bool quit = false;

	while (!quit) {
		system("cls");
		cout << "\n\n";
        cout << "\t\t\t\t  \033[93m  /$$$$$$  /$$                           /$$ /$$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m /$$__  $$| $$                          |__/|__/\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m| $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$  /$$ /$$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$| $$| $$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$| $$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$| $$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/| $$| $$\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m \\______/ |__/  |__/ \\______/ | $$____/ |__/|__/\033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m                              | $$               \033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m                              | $$               \033[0m" << '\n';
        cout << "\t\t\t\t  \033[93m                              |__/               \033[0m" << '\n';
        cout << "\n\n\n";

		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		if (option == 1)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  LOGIN  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       LOGIN\n\n";

		if (option == 2)
			cout << "\t\t\t\t\t\t \x1B[33m  -* REGISTER *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t      REGISTER\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  QUIT  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       QUIT\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";


		//get option
		char key = _getch();

		if (key == 'w' && option > 1) {
			option--;
		}
		else if (key == 's' && option < 3) {
			option++;
		}
		else if (key == ' ') {
			switch (option) {
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:

				break;
			}
		}
	}

	system("cls");
}