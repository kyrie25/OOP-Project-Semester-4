#pragma once

#include <string>
#include <vector>
class User
{
protected:
    std::string username;
    std::string password;
public:
    User(const std::string& username, const std::string& password);
    std::string getUsername();
    bool checkPassword(const std::string& password);
};