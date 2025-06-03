#pragma once 
#include "users/User.h"
#include <string>
#include <vector>
class ApplicationController 
{
private:
    std::vector<User*> users;

    void showMainMenu();
    void handleLogin();
    void handleRegister();
    void handleCustomerMenu();
    void handleSellerMenu();
public:
    ApplicationController();
    void run();  
};