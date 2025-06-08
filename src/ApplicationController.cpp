#include "ApplicationController.h"
#include "users/UserFactory.h"
#include <conio.h>
#include <iostream>

using namespace std;

std::vector<Product*> ApplicationController::loadSellerProducts()
{
	std::vector<Product*> products;

	for (const auto& user : users) {
		if (user->getUserType() == "Seller") {
			Seller* seller = dynamic_cast<Seller*>(user);
			if (seller) {
				std::vector<Product*> sellerProducts = seller->getMyProduct();
				for (const auto& product : sellerProducts) {
					products.push_back(product);
				}
			}
		}
	}

	return products;
}

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

					handleCustomerMenu(user);
				} else if (user->getUserType() == "Seller") {
					handleSellerMenu(user);
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

void ApplicationController::handleCustomerMenu(User* user)
{
	int option = 1;
	bool quit = false;

	while (!quit)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		if (option == 1)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  SHOP  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       SHOP\n\n";

		if (option == 2)
			cout << "\t\t\t\t\t \x1B[33m  -* MANAGE PAYMENT METHOD *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t      MANAGE PAYMENT METHOD\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  BACK  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       BACK\n\n";
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
				cout << "\t\t\t\t\t\t  Shopping feature is not implemented yet.\n";
				system("pause");
				break;
			case 2:
				cout << "\t\t\t\t\t\t  Adding payment method feature is not implemented yet.\n";
				system("pause");
				break;
			case 3:
				quit = true;
				break;
			}
		}
	}
}

void ApplicationController::handleShopMenu(User* user)
{
	while (true) {
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		cout << "\t\t\t\t\t\t \x1B[33m  -*  SHOP  *-\33[0m\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";

		// Display products
		std::vector<Product*> products = loadSellerProducts();
		if (products.empty()) {
			cout << "\t\t\t\t   No products available in the shop.\n";
		} else {
			for (const auto& product : products) {
				product->display();
			}
		}

		cout << "\n\nPress any key to go back to the customer menu.";
		char key = _getch();
		if (key == 27) 
		{ 
			break;
		}
	}
}

void ApplicationController::handlePaymentMethod(User* user)
{
	Customer* customer = dynamic_cast<Customer*>(user);

	int option = 1;
	bool quit = false;

	while (!quit)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		if (option == 1)
			cout << "\t\t\t\t\t    \x1B[33m  -* ADD PAYMENT METHOD *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t         ADD PAYMENT METHOD\n\n";

		if (option == 2)
			cout << "\t\t\t\t\t    \x1B[33m  -* REMOVE PAYMENT METHOD *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t         REMOVE PAYMENT METHOD\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  BACK  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       BACK\n\n";
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
				system("cls");
				// Add payment method feature
				break;
			case 2:
				system("cls");
				// Remove payment method feature
				
				break;
			case 3:
				quit = true;
				break;
			}
		}
	}
}

void ApplicationController::handleSellerMenu(User* user)
{
	Seller* seller = dynamic_cast<Seller*>(user);

	int option = 1;
	bool quit = false;
	while (!quit)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		if (option == 1)
			cout << "\t\t\t\t\t    \x1B[33m  -*  MANAGE PRODUCTS  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t          MANAGE PRODUCTS\n\n";

		if (option == 2)
			cout << "\t\t\t\t\t    \x1B[33m  -* VIEW SALES REPORT *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t         VIEW SALES REPORT\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  BACK  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       BACK\n\n";
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
				cout << "\t\t\t\t\t   Managing products feature is not implemented yet.\n";
				system("pause");
				break;
			case 2:
				cout << "\t\t\t\t   Viewing sales report feature is not implemented yet.\n";
				system("pause");
				break;
			case 3:
				quit = true;
				break;
			}
		}
	}

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