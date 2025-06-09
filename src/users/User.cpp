#include "User.h"

User::User(const std::string& _username, const std::string& _password) : username(_username), password(_password) {}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return password;
}

bool User::checkPassword(const std::string& password)
{
    return this->password == password;
}

