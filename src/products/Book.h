#pragma once
#include "Product.h"

class Book : public Product
{
public:
    
    Book(const std::string& _name, const std::string& _description, int _price);

    std::string getType() const;

    void display();
};