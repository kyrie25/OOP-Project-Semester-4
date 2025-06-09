#pragma once

#include <string>

class Product
{
protected:
    std::string name;
    std::string description;
    int price;
public:
    Product(std::string _name, std::string _description, int _price);

    std::string getDescription();
    std::string getName();
    int getPrice();

    virtual std::string getType() const = 0;
    virtual void display() = 0;
};