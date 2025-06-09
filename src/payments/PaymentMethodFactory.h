#pragma once 

#include <string>
#include "PaymentMethod.h"



class PaymentMethodFactory
{
public:
    static PaymentMethod* createPaymentMethod(const std::string& methodName);
};