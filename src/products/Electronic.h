#pragma once 
#include "Product.h"
class Electronic : public Product
{
private:
    std::string brand;
public:
    Electronic(const std::string& _name, const std::string& _description, int _price);

    void setBrand(const std::string& _brand);

    std::string getBrand() const;
    std::string getType() const;

    void display();
};