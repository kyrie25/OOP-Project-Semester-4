#pragma once
#include "users/User.h"
#include "users/Seller.h"
#include "products/Product.h"
#include <string>
#include <vector>

enum
{
    KEY_UP = 72,
    KEY_DOWN = 80,
    KEY_LEFT = 75,
    KEY_RIGHT = 77,
    KEY_ENTER = 13,
    KEY_ESC = 27
};

class ApplicationController
{
private:
    std::vector<User *> users;

    std::vector<std::pair<Seller*, std::pair<Product*, int>>> loadSellerProducts();

    void handleLogin();
    void handleRegister();

    void handleCustomerMenu(User *user);  // view shop, buy product, manage payment methods
    void handleShopMenu(User *user);      // view products, buy products
    void handlePaymentMethod(User *user); // add or remove payment methods, (Xuan tri's task)

    void handleSellerMenu(User *user);    // view products, add or remove products, view orders
    void handleAddProduct(User *user);    // add or remove products
    void handleRemoveProduct(User *user); // remove products

public:
    ApplicationController();
    ~ApplicationController();

    void run();
};