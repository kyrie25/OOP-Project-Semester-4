#include "ApplicationController.h"
#include "users/UserFactory.h"
#include <conio.h>
#include <iostream>

using namespace std;

void ApplicationController::handleRegister()
{
	while (true) {
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

		cout << "\t\t\t     Please enter your desired username and password to register.\n\n\n";

		string username, password;
		bool isValid = true;
		cout << "\t\t\t\t\t\t   Username: ";
		getline(cin, username);
		cout << "\t\t\t\t\t\t   Password: ";
		getline(cin, password);

		//check if username and password have space
		if (username.find(' ') != string::npos || password.find(' ') != string::npos) {
			cout << "\t\t\t     Username and password cannot contain spaces. Please try again.\n";
			system("pause");
			continue;
		}

		if (username.empty() || password.empty()) {
			cout << "\t\t\t     Username and password cannot be empty. Please try again.\n";
			system("pause");
			continue;
		}
		
		for (const auto& user : users) {
			if (user->getUsername() == username) {
				isValid = false;
				break;
			}
		}

		if (!isValid) {
			cout << "\t\t\t     Username already exists. Please choose a different username.\n";
			system("pause");
			continue;
		}

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

		//choose user type
		cout << "\t\t\t\t          Please choose your user type:\n\n";
		cout << "\t\t\t\t\t\t   1. Customer\n";
		cout << "\t\t\t\t\t\t   2. Seller\n";

		int userType;
		cout << "\t\t\t\t          Enter your choice (1 or 2): ";
		cin >> userType;
		cin.ignore(); 
		if (userType != 1 && userType != 2) {
			cout << "\t\t\t     Invalid choice. Please try again.\n";
			system("pause");
			continue;
		}

		UserFactory userFactory;
		User* newUser = userFactory.createUser(userType == 1 ? "Customer" : "Seller", username, password);

		users.push_back(newUser);
		cout << "\t\t\t\t     Registration successful! Welcome, " << username << "!\n";
		cout << "\t\t\t\t     You can now log in with your new account.\n";
		system("pause");
		return;
	}
}

void ApplicationController::handleLogin()
{
	char key;
    while (true) {
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
		cout << "\t\t\t          Please enter your username and password to log in.\n\n\n";
		string username, password;
		
		cout << "\t\t\t\t\t\t   Username: ";
		cin >> username;
		cout << "\t\t\t\t\t\t   Password: ";
		cin >> password; 

		if (username.empty() || password.empty()) {
			cout << "\t\t\t          Username and password cannot be empty. Please try again.\n";
			system("pause");
			continue;
		}
		for (const auto& user : users) {
			if (user->getUsername() == username && user->checkPassword(password)) {
				cout << "\t\t\t\t\t\t  Login successful!\n";
				system("pause");

				if (user->getUserType() == "Customer") {
					handleCustomerMenu();
				} else if (user->getUserType() == "Seller") {
					handleSellerMenu();
				} 
					
				return;
			}
		}
		cout << "\t\t\t          Invalid username or password. Please try again.\n";
		key = _getch();
		if (key == 27) { 
			return;
		}
	}
}

void ApplicationController::handleCustomerMenu()
{
	
}

void ApplicationController::handleSellerMenu()
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
				handleLogin();
				break;
			case 2:
				handleRegister();
				break;
			case 3:
				quit = true;	
				cout << "Exiting the application. Goodbye!\n";
				system("pause");
				break;
			}
		}
	}

	system("cls");
}