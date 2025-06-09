#include "Book.h"
#include <iostream>

Book::Book(const std::string& _name, const std::string& _description, int _price)
    : Product(_name, _description, _price), author(""), publisher("") {}

void Book::setAuthor(const std::string& _author) {
    author = _author;
}

void Book::setPublisher(const std::string& _publisher) {
    publisher = _publisher;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}

std::string Book::getType() const {
    return "Book";
}

void Book::display() {
    std::cout << "Book Name: " << name << "\n"
              << "Description: " << description << "\n"
              << "Price: $" << price << "\n"
              << "Author: " << author << "\n"
              << "Publisher: " << publisher << "\n";
}
