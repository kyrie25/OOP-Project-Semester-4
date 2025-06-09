#include "ProductFactory.h"

Product* ProductFactory::createProduct(const std::string& type, const std::string& name, const std::string& description, int price) {
    if (type == "Book") {
        return new Book(name, description, price);
    } else if (type == "Electronic") {
        return new Electronic(name, description, price);
    }
    return nullptr;
}
