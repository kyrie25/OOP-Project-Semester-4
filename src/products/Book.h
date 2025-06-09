#pragma once
#include "Product.h"

class Book : public Product
{
private:
    std::string author;
    std::string publisher;
public:
    
    Book(const std::string& _name, const std::string& _description, int _price);

    void setAuthor(const std::string& _author);
    void setPublisher(const std::string& _publisher);

    std::string getAuthor() const;
    std::string getPublisher() const;
    std::string getType() const;

    void display();
};