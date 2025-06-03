#include "User.h"

User::User(const std::string& _username, const std::string& _password) : username(_username), password(_password) {}

std::string User::getUsername()
{
    return username;
}

bool User::checkPassword(const std::string& password)
{
    return this->password == password;
}