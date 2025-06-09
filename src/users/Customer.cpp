#include "Customer.h"

Customer::Customer(const std::string& username, const std::string& password)
    : User(username, password) {}

void Customer::addPaymentMethod(PaymentMethod* method) {
    for (const auto& existingMethod : paymentMethods) {
        if (existingMethod->getMethodName() == method->getMethodName()) {
            delete method; 
            return;
        }
    }
    paymentMethods.push_back(method);
}

void Customer::removePaymentMethod(const std::string& methodName) {
    for (auto it = paymentMethods.begin(); it != paymentMethods.end(); ++it) {
        if ((*it)->getMethodName() == methodName) {
            delete *it; 
            paymentMethods.erase(it);
            return;
        }
    }
}

std::string Customer::getUserType() const {
    return "Customer";
}