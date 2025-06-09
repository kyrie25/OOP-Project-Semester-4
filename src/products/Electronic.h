#pragma once 
#include "Product.h"
class Electronic : public Product
{
public:
    Electronic(const std::string& _name, const std::string& _description, int _price);

    std::string getType() const;

    void display();
};