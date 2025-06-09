#pragma once 
#include "users/User.h"
#include "products/Product.h"
#include <string>
#include <vector>

class ApplicationController 
{
private:
    std::vector<User*> users;

    std::vector<Product*> loadSellerProducts();

    void handleLogin();
    void handleRegister();

    void handleCustomerMenu(User* user); //view shop, buy product, manage payment methods
    void handleShopMenu(User* user); //view products, buy products
    void handlePaymentMethod(User* user); //add or remove payment methods, (Xuan tri's task)

    void handleSellerMenu(User* user); //view products, add or remove products, view orders
    void handleAddProduct(User* user); //add or remove products
    void handleRemoveProduct(User* user); //remove products
    void handleViewProducts(User* user); //view products
    void handleOrder(User* user); //view orders.

public:
    ApplicationController();
    ~ApplicationController();

    void run();  
};