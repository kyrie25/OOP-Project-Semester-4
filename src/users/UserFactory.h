#pragma once

#include "Customer.h"
#include "Seller.h" 
class UserFactory
{
public:
    User* createUser(const std::string& userType, const std::string& username, const std::string& password);
};