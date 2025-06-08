#pragma once 
#include "users/User.h"
#include <string>
#include <vector>
class ApplicationController 
{
private:
    std::vector<User*> users;

    void handleLogin();
    void handleRegister();

    void handleCustomerMenu(User* user);
    void handlePaymentMethod(User* user);

    void handleSellerMenu(User* user);
public:
    //ApplicationController();
    void run();  
};