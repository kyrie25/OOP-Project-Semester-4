#include "Product.h"

Product::Product(std::string _name, std::string _description, int _price) : name(name), description(_description), price(price) {}

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
