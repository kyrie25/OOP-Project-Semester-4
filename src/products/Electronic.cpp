#include "Electronic.h"
#include <iostream>

Electronic::Electronic(const std::string& _name, const std::string& _description, int _price)
    : Product(_name, _description, _price) {}

std::string Electronic::getType() const {
    return "Electronic";
}

void Electronic::display() {
    std::cout << "Electronic Name: " << name << "\n"
              << "Description: " << description << "\n"
              << "Price: $" << price << "\n";
}