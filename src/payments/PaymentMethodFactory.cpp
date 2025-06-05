#include "PaymentMethodFactory.h"

PaymentMethod* PaymentMethodFactory::createPaymentMethod(const std::string& methodName) {
    if (methodName == "CreditCard") {
        //return new CreditCardPayment();
    } else if (methodName == "PayPal") {
        //return new PayPalPayment();
    } else if (methodName == "BankTransfer") {
        //return new BankTransferPayment();
    } 
}