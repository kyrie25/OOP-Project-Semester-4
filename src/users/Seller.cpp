#include "Seller.h"
#include <algorithm>

Seller::Seller(const std::string &username, const std::string &password)
    : User(username, password) {}

void Seller::addProduct(Product *product, int amount)
{
    for (auto &item : myProduct)
    {
        if (item.first->getName() == product->getName())
        {
            item.second += amount;
            delete product;
            return;
        }
    }

    myProduct.push_back({product, amount});
}

void Seller::removeProduct(std::string name)
{
    for (auto it = myProduct.begin(); it != myProduct.end(); ++it)
    {
        if (it->first->getName() == name)
        {
            delete it->first;
            myProduct.erase(it);
            return;
        }
    }
}

void Seller::sellProduct(std::string name, int amount)
{
    for (auto &item : myProduct)
    {
        if (item.first->getName() == name)
        {
            if (item.second >= amount)
            {
                item.second -= amount;
                if (item.second <= 0)
                {
                    delete item.first;
                    myProduct.erase(std::remove(myProduct.begin(), myProduct.end(), item), myProduct.end());
                }
            }
            return;
        }
    }
}

std::vector<Product *> Seller::getMyProduct()
{
    std::vector<Product *> products;
    for (const auto &item : myProduct)
    {
        products.push_back(item.first);
    }
    return products;
}

std::vector<std::pair<Product *, int>> Seller::getMyProductDetails()
{
    return myProduct;
}

std::string Seller::getUserType() const
{
    return "Seller";
}
