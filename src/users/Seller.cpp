#include "Seller.h"

Seller::Seller(const std::string& username, const std::string& password) : User(username, password) {}

void Seller::addProduct(Product* product, int amount)
{
    for (auto& item : myProduct) {
        if (item.first->getName() == product->getName()) {
            item.second += amount; 
            delete product;
            return;
        }
    }

    myProduct.push_back({product, amount});
}

void Seller::removeProduct(std::string name)
{
    for (auto it = myProduct.begin(); it != myProduct.end(); ++it) {
        if (it->first->getName() == name) {
            delete it->first; 
            myProduct.erase(it);
            return;
        }
    }
}

std::vector<Product*> Seller::getMyProduct()
{
    std::vector<Product*> products;
    for (const auto& item : myProduct) {
        products.push_back(item.first);
    }
    return products;
}