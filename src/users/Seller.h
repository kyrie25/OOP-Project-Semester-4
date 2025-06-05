#pragma once

#include "User.h"
#include "../products/Product.h"

class Seller : public User
{
private:
    std::vector<std::pair<Product*, int>> myProduct;
public:
    void addProduct(Product* product, int amount);
    void removeProduct(std::string name);

    std::vector<Product*> getMyProduct();
};