#include "Product.h"

Product::Product(const std::string &_name, const std::string &_description, int _price)
    : name(_name), description(_description), price(_price) {}

std::string Product::getName()
{
    return name;
}

int Product::getPrice()
{
    return price;
}

std::string Product::getDescription()
{
    return description;
}
