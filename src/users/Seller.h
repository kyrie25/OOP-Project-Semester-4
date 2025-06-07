#pragma once

#include "User.h"
#include "../products/Product.h"

class Seller : public User
{
private:
    std::vector<std::pair<Product*, int>> myProduct;
public:
    Seller(const std::string& username, const std::string& password);

    void addProduct(Product* product, int amount);
    void removeProduct(std::string name);
    
    std::string getUserType() const;

    std::vector<Product*> getMyProduct();
};