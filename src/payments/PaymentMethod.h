#pragma once

#include <string>

class PaymentMethod
{
protected:
    std::string methodName;
public:
    PaymentMethod(const std::string& name);

    std::string getMethodName();

    virtual bool processPayment(double amount) = 0;
};