#pragma once

#include <iostream>
#include <string>

class PaymentMethod
{
protected:
    std::string methodName;

public:
    PaymentMethod(const std::string &name);

    std::string getMethodName();

    virtual bool processPayment(double amount) = 0;
};

class CreditCardPayment : public PaymentMethod {
public:
    CreditCardPayment() : PaymentMethod("CreditCard") {}
    bool processPayment(double amount) override {
        // Implement logic here
        return true;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    PayPalPayment() : PaymentMethod("PayPal") {}
    bool processPayment(double amount) override {
        // Implement logic here
        return true;
    }
};

class BankTransferPayment : public PaymentMethod {
public:
    BankTransferPayment() : PaymentMethod("BankTransfer") {}
    bool processPayment(double amount) override {
        // Implement logic here
        return true;
    }
};