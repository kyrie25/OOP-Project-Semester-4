#include "UserFactory.h"

User* UserFactory::createUser(const std::string& userType, const std::string& username, const std::string& password) {
    if (userType == "Customer") {
        return new Customer(username, password);
    } else if (userType == "Seller") {
        return new Seller(username, password);
    }
    return nullptr; 
}