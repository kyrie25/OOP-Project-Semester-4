#include "PaymentMethodFactory.h"
#include "PaymentMethod.h" // Make sure this is included

PaymentMethod *PaymentMethodFactory::createPaymentMethod(const std::string &methodName)
{
    if (methodName == "CreditCard")
    {
        return new CreditCardPayment();
    }
    else if (methodName == "PayPal")
    {
        return new PayPalPayment();
    }
    else if (methodName == "BankTransfer")
    {
        return new BankTransferPayment();
    }

    std::cerr << "Unknown payment method: " << methodName << std::endl;
    return nullptr; 
}