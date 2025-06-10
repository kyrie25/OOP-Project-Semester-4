#include "ApplicationController.h"
#include "users/UserFactory.h"
#include "products/ProductFactory.h"
#include "payments/PaymentMethodFactory.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

std::vector<std::pair<Seller *, std::pair<Product *, int>>> ApplicationController::loadSellerProducts()
{
	std::vector<std::pair<Seller *, std::pair<Product *, int>>> sellerProducts;

	for (const auto &user : users)
	{
		if (user->getUserType() == "Seller")
		{
			Seller *seller = dynamic_cast<Seller *>(user);
			if (seller)
			{
				std::vector<std::pair<Product *, int>> products = seller->getMyProductDetails();
				for (const auto &product : products)
				{
					sellerProducts.push_back({seller, product});
				}
			}
		}
	}

	return sellerProducts;
}

//------------------------------------
// REGISTRATION AND LOGIN SECTION
//------------------------------------

void ApplicationController::handleRegister()
{
	while (true)
	{
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

		// check if username and password have space
		if (username.find(' ') != string::npos || password.find(' ') != string::npos)
		{
			cout << "\t\t\t     Username and password cannot contain spaces. Please try again.\n";
			system("pause");
			continue;
		}

		if (username.empty() || password.empty())
		{
			cout << "\t\t\t     Username and password cannot be empty. Please try again.\n";
			system("pause");
			continue;
		}

		for (const auto &user : users)
		{
			if (user->getUsername() == username)
			{
				isValid = false;
				break;
			}
		}

		if (!isValid)
		{
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

		// choose user type
		cout << "\t\t\t\t          Please choose your user type:\n\n";
		cout << "\t\t\t\t\t\t   1. Customer\n";
		cout << "\t\t\t\t\t\t   2. Seller\n";

		int userType;
		cout << "\t\t\t\t          Enter your choice (1 or 2): ";
		cin >> userType;
		cin.ignore();
		if (userType != 1 && userType != 2)
		{
			cout << "\t\t\t     Invalid choice. Please try again.\n";
			system("pause");
			continue;
		}

		UserFactory userFactory;
		User *newUser = userFactory.createUser(userType == 1 ? "Customer" : "Seller", username, password);

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
	while (true)
	{
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
		cin.ignore();
		cout << "\t\t\t\t\t\t   Password: ";
		cin >> password;
		cin.ignore();

		if (username.empty() || password.empty())
		{
			cout << "\t\t\t          Username and password cannot be empty. Please try again.\n";
			system("pause");
			continue;
		}
		for (const auto &user : users)
		{
			if (user->getUsername() == username && user->checkPassword(password))
			{
				cout << "\t\t\t\t\t\t  Login successful!\n";
				system("pause");

				if (user->getUserType() == "Customer")
				{

					handleCustomerMenu(user);
				}
				else if (user->getUserType() == "Seller")
				{
					handleSellerMenu(user);
				}

				return;
			}
		}
		cout << "\t\t\t          Invalid username or password. Please try again.\n";
		key = _getch();
		if (key == KEY_ESC)
		{
			return;
		}
	}
}

//------------------------------------
// CUSTOMER SECTION
//------------------------------------

void ApplicationController::handleCustomerMenu(User *user)
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

		// get option
		char key = _getch();
		if ((key == 'w' || key == KEY_UP) && option > 1) // up arrow key
		{
			option--;
		}
		else if ((key == 's' || key == KEY_DOWN) && option < 3) // down arrow key
		{
			option++;
		}
		else if (key == ' ' || key == KEY_ENTER) // space or enter key
		{
			switch (option)
			{
			case 1:
				handleShopMenu(user);
				break;
			case 2:
				handlePaymentMethod(user);
				break;
			case 3:
				quit = true;
				break;
			}
		}
	}
}

void ApplicationController::handleShopMenu(User *user)
{
	while (true)
	{
		system("cls");
		cout << "\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		cout << "\t\t\t\t\t\t \x1B[33m  -*  SHOP  *-\33[0m\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";

		// Display products and allow user to select a product
		std::vector<pair<Seller *, pair<Product *, int>>> products = loadSellerProducts();

		if (products.empty())
		{
			cout << "\t\t\t\t\t No products available in the shop.\n";
			system("pause");
			return;
		}

		cout << '\n';

		for (size_t i = 0; i < products.size(); ++i)
		{
			cout << "\t\t\t\t\t " << i + 1 << ". " << products[i].second.first->getName() << " - "
				 << products[i].second.first->getType()
				 << " - Price: $" << products[i].second.first->getPrice() << "\n";
		}

		cout << "\t\t\t\t\t -----------====***====-----------\n";
		cout << "\t\t\t\t\t " << 'x' << ". Back to menu\n";
		cout << "\t\t\t\t\t Please select a product by number: ";
		string input;
		getline(cin, input);
		if (input == "x" || input == "X" || input == to_string(products.size() + 1))
		{
			return; // Back to menu
		}
		int choice = 0;
		try
		{
			choice = std::stoi(input);
		}
		catch (const std::invalid_argument &)
		{
			cout << "\t\t\t\t\t Invalid input. Please enter a number.\n";
			system("pause");
			continue;
		}
		catch (const std::out_of_range &)
		{
			cout << "\t\t\t\t\t Number out of range. Please try again.\n";
			system("pause");
			continue;
		}
		if (choice < 1 || choice > products.size() + 1)
		{
			cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
			system("pause");
			continue;
		}

		// display selected product details
		system("cls");
		cout << "\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		cout << "\t\t\t\t\t\t\x1B[33m  PRODUCT DETAILS \33[0m\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";

		cout << '\n';
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		cout << "\t\t\t\t\t Product Name: " << products[choice - 1].second.first->getName() << "\n";
		cout << "\t\t\t\t\t Product Type: " << products[choice - 1].second.first->getType() << "\n";
		cout << "\t\t\t\t\t Product Description: " << products[choice - 1].second.first->getDescription() << "\n";
		cout << "\t\t\t\t\t Product Price: $" << products[choice - 1].second.first->getPrice() << "\n";
		cout << "\t\t\t\t\t Product Amount: " << products[choice - 1].second.second << "\n";
		cout << "\t\t\t\t\t Seller: " << products[choice - 1].first->getUsername() << "\n";
		cout << "\n\t\t\t\t\t -----------====***====-----------\n\n";

		// buy or back to shop menu
		cout << "\n\t\t\t\t\t Would you like to buy this product? (y/n): ";
		char buyChoice;
		cin >> buyChoice;
		cin.ignore();
		if (buyChoice == 'y' || buyChoice == 'Y')
		{
			// choose payment method
			std::vector<PaymentMethod *> paymentMethods = dynamic_cast<Customer *>(user)->getPaymentMethods();
			if (paymentMethods.empty())
			{
				cout << "\t\t\t\t\t No payment methods available. Please add a payment method first.\n";
				system("pause");
				continue;
			}
			cout << "\t\t\t\t\t Please select a payment method:\n";
			for (size_t i = 0; i < paymentMethods.size(); ++i)
			{
				cout << "\t\t\t\t\t " << i + 1 << ". " << paymentMethods[i]->getMethodName() << "\n";
			}
			cout << "\t\t\t\t\t " << "x. Back to menu\n";
			cout << "\t\t\t\t\t Please select a payment method by number: ";
			string input;
			getline(cin, input);
			cout << "\n";

			if (input == "x" || input == "X")
			{
				continue; // Back to menu
			}
			int choice = 0;
			try
			{
				choice = std::stoi(input);
			}
			catch (const std::invalid_argument &)
			{
				cout << "\t\t\t\t\t Invalid input. Please enter a number.\n";
				system("pause");
				continue;
			}
			catch (const std::out_of_range &)
			{
				cout << "\t\t\t\t\t Number out of range. Please try again.\n";
				system("pause");
				continue;
			}
			if (choice < 1 || choice > paymentMethods.size())
			{
				cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
				system("pause");
				continue;
			}

			// Process payment
			PaymentMethod *selectedMethod = paymentMethods[choice - 1];
			double amount = products[choice - 1].second.first->getPrice();

			if (selectedMethod->processPayment(amount))
			{
				cout << "\t\t\t\t\t Payment successful!\n";
			}
			else
			{
				cout << "\t\t\t\t\t Payment failed. Please check if you have sufficient funds.\n";
			}
			// remove product from seller's products if amount is 0 then remove from seller's products

			Seller *seller = products[choice - 1].first;
			seller->sellProduct(products[choice - 1].second.first->getName(), 1);
			products[choice - 1].second.second--;
			if (products[choice - 1].second.second <= 0)
			{
				products.erase(products.begin() + choice - 1);
			}
			cout << "\t\t\t\t\t Thank you for your purchase!\n";
			system("pause");
			return; // Back to shop menu
		}
		else if (buyChoice == 'n' || buyChoice == 'N')
		{
			// Back to shop menu
		}
		else
		{
		}
	}
}

void ApplicationController::handlePaymentMethod(User *user)
{
	Customer *customer = dynamic_cast<Customer *>(user);
	if (!customer)
	{
		cout << "\t\t\t\t\t Error: Only customers can manage payment methods.\n";
		system("pause");
		return;
	}

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
			cout << "\t\t\t\t\t    \x1B[33m -* REMOVE PAYMENT METHOD *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t        REMOVE PAYMENT METHOD\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  BACK  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       BACK\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";

		// get option
		char key = _getch();
		if ((key == 'w' || key == KEY_UP) && option > 1)
		{
			option--;
		}
		else if ((key == 's' || key == KEY_DOWN) && option < 3)
		{
			option++;
		}
		else if (key == ' ' || key == KEY_ENTER)
		{
			switch (option)
			{
			case 1:
			{
				std::vector<PaymentMethod *> methods = customer->getPaymentMethods();
				system("cls");
				cout << "\n\t\t\t\t\t ADD PAYMENT METHOD\n\n";

				// List all possible payment methods
				std::vector<std::string> allMethods = {"CreditCard", "PayPal", "BankTransfer"};
				std::vector<std::string> availableMethods;

				// Exclude already added methods
				for (const auto &method : allMethods)
				{
					bool alreadyAdded = false;
					for (const auto &m : methods)
					{
						if (m->getMethodName() == method)
						{
							alreadyAdded = true;
							break;
						}
					}
					if (!alreadyAdded)
					{
						availableMethods.push_back(method);
					}
				}

				if (availableMethods.empty())
				{
					cout << "\t\t\t\t\t All payment methods already added.\n";
					system("pause");
					break;
				}

				for (size_t i = 0; i < availableMethods.size(); ++i)
				{
					cout << "\t\t\t\t\t " << i + 1 << ". " << availableMethods[i] << "\n";
				}
				cout << "\t\t\t\t\t ---------------------------------\n";
				cout << "\t\t\t\t\t x. Back to menu\n";
				cout << "\t\t\t\t\t Choose payment type (1-" << availableMethods.size() << "): ";
				string choice;
				getline(cin, choice);
				if (choice == "x" || choice == "X")
				{
					break; // Back to menu
				}
				int idx = 0;
				try
				{
					idx = std::stoi(choice);
				}
				catch (...)
				{
					cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
					system("pause");
					break;
				}
				if (idx < 1 || idx > (int)availableMethods.size())
				{
					cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
					system("pause");
					break;
				}
				string methodName = availableMethods[idx - 1];
				PaymentMethodFactory paymentFactory;
				PaymentMethod *newMethod = paymentFactory.createPaymentMethod(methodName);
				if (newMethod)
				{
					customer->addPaymentMethod(newMethod);
					cout << "\t\t\t\t\t Payment method added successfully!\n";
				}
				else
				{
					cout << "\t\t\t\t\t Error: Invalid payment method type.\n";
				}
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				auto methods = customer->getPaymentMethods();
				if (methods.empty())
				{
					cout << "\t\t\t\t\t No payment methods available to remove.\n";
					system("pause");
					break;
				}
				cout << "\n\t\t\t\t\t REMOVE PAYMENT METHOD\n\n";
				for (size_t i = 0; i < methods.size(); ++i)
				{
					cout << "\t\t\t\t\t " << i + 1 << ". " << methods[i]->getMethodName() << "\n";
				}
				cout << "\t\t\t\t\t ---------------------------------\n";
				cout << "\t\t\t\t\t " << "x. Back to menu\n";
				cout << "\t\t\t\t\t Choose payment method to remove (1-" << methods.size() << "): ";
				string input;
				getline(cin, input);
				if (input == "x" || input == "X")
				{
					break; // Back to menu
				}
				int choice = 0;
				try
				{
					choice = std::stoi(input);
				}
				catch (...)
				{
					cout << "\t\t\t\t\t Invalid input. Please enter a number.\n";
					system("pause");
					break;
				}

				if (choice < 1 || choice > methods.size())
				{
					cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
					system("pause");
					break;
				}
				// Remove payment method
				PaymentMethod *methodToRemove = methods[choice - 1];
				customer->removePaymentMethod(methodToRemove->getMethodName());
				cout << "\t\t\t\t\t Payment method removed successfully!\n";
				system("pause");
				break;
			}
			case 3:
			{
				quit = true;
				break;
			}
			}
		}
	}
}

//------------------------------------
// SELLER SECTION
//------------------------------------

void ApplicationController::handleSellerMenu(User *user)
{
	int option = 1;
	bool quit = false;
	while (!quit)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n\n";
		if (option == 1)
			cout << "\t\t\t\t\t      \x1B[33m  -*  ADD PRODUCTS  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t            ADD PRODUCTS\n\n";

		if (option == 2)
			cout << "\t\t\t\t\t      \x1B[33m  -* REMOVE PRODUCTS *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t           REMOVE PRODUCTS\n\n";

		if (option == 3)
			cout << "\t\t\t\t\t\t \x1B[33m  -*  BACK  *-\33[0m\n\n";
		else
			cout << "\t\t\t\t\t\t       BACK\n\n";
		cout << "\t\t\t\t\t -----------====***====-----------\n";

		// get option
		char key = _getch();
		if ((key == 'w' || key == KEY_UP) && option > 1)
		{
			option--;
		}
		else if ((key == 's' || key == KEY_DOWN) && option < 3)
		{
			option++;
		}
		else if (key == ' ' || key == KEY_ENTER)
		{
			switch (option)
			{
			case 1:
				handleAddProduct(user);
				break;
			case 2:
				handleRemoveProduct(user);
				break;
			case 3:
				quit = true;
				break;
			}
		}
	}
}

void ApplicationController::handleAddProduct(User *user)
{
	system("cls");
	cout << "\n\n";
	cout << "\t\t\t\t\t Enter product type: ";
	string productType;
	cin >> productType;
	cin.ignore();
	cout << "\t\t\t\t\t Enter product name: ";
	string productName;
	getline(cin, productName);
	cout << "\t\t\t\t\t Enter product description: ";
	string productDescription;
	getline(cin, productDescription);
	cout << "\t\t\t\t\t Enter product price: ";
	int productPrice;
	cin >> productPrice;
	cin.ignore();
	cout << "\t\t\t\t\t Enter product amount: ";
	int productAmount;
	cin >> productAmount;
	cin.ignore();

	ProductFactory productFactory;
	Product *newProduct = productFactory.createProduct(productType, productName, productDescription, productPrice);

	if (newProduct)
	{
		Seller *seller = dynamic_cast<Seller *>(user);
		if (seller)
		{
			seller->addProduct(newProduct, productAmount);
			cout << "\t\t\t\t\t Product added successfully!\n";
		}
		else
		{
			cout << "\t\t\t\t\t Error: User is not a seller.\n";
		}
	}
	else
	{
		cout << "\t\t\t\t\t Error: Invalid product type.\n";
	}
	system("pause");
}

void ApplicationController::handleRemoveProduct(User *user)
{
	system("cls");
	// Display seller's products
	Seller *seller = dynamic_cast<Seller *>(user);
	if (!seller)
	{
		cout << "\t\t\t\t\t Error: User is not a seller.\n";
		system("pause");
		return;
	}
	// get products details
	auto products = seller->getMyProductDetails();
	if (products.empty())
	{
		cout << "\t\t\t\t\t No products available to remove.\n";
		system("pause");
		return;
	}
	cout << "\n\t\t\t\t\t REMOVE PRODUCTS\n\n";
	for (size_t i = 0; i < products.size(); ++i)
	{
		cout << "\t\t\t\t\t " << i + 1 << ". " << products[i].first->getName() << " - "
			 << products[i].first->getType()
			 << " - Price: $" << products[i].first->getPrice() << "\n";
	}
	cout << "\t\t\t\t\t " << 'x' << ". Back to menu\n";
	cout << "\t\t\t\t\t Please select a product to remove (1-" << products.size() << "): ";
	string input;
	getline(cin, input);
	int choice = 0;
	try
	{
		choice = std::stoi(input);
	}
	catch (const std::invalid_argument &)
	{
		cout << "\t\t\t\t\t Invalid input. Please enter a number.\n";
		system("pause");
		return;
	}
	catch (const std::out_of_range &)
	{
		cout << "\t\t\t\t\t Number out of range. Please try again.\n";
		system("pause");
		return;
	}

	if (choice < 1 || choice > products.size() + 1)
	{
		cout << "\t\t\t\t\t Invalid choice. Please try again.\n";
		system("pause");
		return;
	}

	if (choice == 'x' || choice == 'X') // Back to menu
	{
		return;
	}

	// Remove the selected product
	string productName = products[choice - 1].first->getName();
	seller->removeProduct(productName);
	cout << "\t\t\t\t\t Product removed successfully!\n";
	system("pause");
}

//------------------------------------
// CONSTRUCTOR AND DESTRUCTOR
//------------------------------------

ApplicationController::ApplicationController()
{
	// load user
	fstream userFile("users.txt", ios::in);
	if (userFile.is_open())
	{
		string line;
		while (getline(userFile, line))
		{
			istringstream iss(line);
			string userType, username, password;
			iss >> userType >> username >> password;

			UserFactory userFactory;
			User *user = userFactory.createUser(userType, username, password);
			if (user)
			{
				users.push_back(user);
			}

			if (userType == "Customer")
			{
				// load customer's payment methods
				std::string paymentMethodsToken;
				while (iss >> paymentMethodsToken)
				{
					PaymentMethodFactory paymentFactory;
					PaymentMethod *paymentMethod = paymentFactory.createPaymentMethod(paymentMethodsToken);
					if (paymentMethod)
					{
						Customer *customer = dynamic_cast<Customer *>(user);
						if (customer)
						{
							customer->addPaymentMethod(paymentMethod);
						}
					}
				}
			}
		}
	}
	// load seller's products
	fstream productFile("products.txt", ios::in);
	if (productFile.is_open())
	{
		std::string line;
		while (std::getline(productFile, line))
		{
			std::istringstream iss(line);
			std::string userName, productType, name, description;
			int price, amount;

			if (!(iss >> userName >> productType >> std::quoted(name) >> std::quoted(description) >> price >> amount))
			{
				continue;
			}

			ProductFactory productFactory;
			Product *product = productFactory.createProduct(productType, name, description, price);
			if (product)
			{
				for (auto &user : users)
				{
					if (user->getUsername() == userName && user->getUserType() == "Seller")
					{
						Seller *seller = dynamic_cast<Seller *>(user);
						if (seller)
						{
							seller->addProduct(product, amount);
						}
					}
				}
			}
		}
		productFile.close();
	}
	// load customers' payment methods
}

ApplicationController::~ApplicationController()
{
	// save users to file
	fstream userFile("users.txt", ios::out);
	if (userFile.is_open())
	{
		for (const auto &user : users)
		{
			userFile << user->getUserType() << " " << user->getUsername() << " " << user->getPassword();
			if (user->getUserType() == "Customer")
			{
				Customer *customer = dynamic_cast<Customer *>(user);
				if (customer)
				{
					std::vector<PaymentMethod *> paymentMethods = customer->getPaymentMethods();
					for (const auto &method : paymentMethods)
					{
						userFile << " " << method->getMethodName();
					}
				}
			}
			userFile << "\n";
		}
	}
	userFile.close();

	// save products to file
	fstream productFile("products.txt", ios::out);
	if (productFile.is_open())
	{
		for (const auto &user : users)
		{
			if (user->getUserType() == "Seller")
			{
				Seller *seller = dynamic_cast<Seller *>(user);
				if (seller)
				{
					std::vector<std::pair<Product *, int>> products = seller->getMyProductDetails();
					for (const auto &product : products)
					{
						productFile << user->getUsername() << " " << product.first->getType() << " "
									<< std::quoted(product.first->getName()) << " "
									<< std::quoted(product.first->getDescription()) << " "
									<< product.first->getPrice() << " "
									<< product.second // amount
									<< "\n";
					}
				}
			}
		}
	}
	productFile.close();

	for (auto user : users)
	{
		delete user;
	}
	users.clear();
}

//------------------------------------
// MAIN APPLICATION RUN METHOD
//------------------------------------

void ApplicationController::run()
{
	int option = 1;

	bool quit = false;

	while (!quit)
	{
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

		// get option
		char key = _getch();

		if ((key == 'w' || key == KEY_UP) && option > 1)
		{
			option--;
		}
		else if ((key == 's' || key == KEY_DOWN) && option < 3)
		{
			option++;
		}
		else if (key == ' ' || key == KEY_ENTER)
		{
			switch (option)
			{
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