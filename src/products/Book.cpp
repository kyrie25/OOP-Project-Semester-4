#include "Book.h"
#include <iostream>

Book::Book(const std::string& _name, const std::string& _description, int _price)
    : Product(_name, _description, _price) {}

std::string Book::getType() const {
    return "Book";
}

void Book::display() {
    std::cout << "Book Name: " << name << "\n"
              << "Description: " << description << "\n"
              << "Price: $" << price << "\n";
}
