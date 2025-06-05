#include "PaymentMethod.h"
#include <iostream>

PaymentMethod::PaymentMethod(const std::string& name) : methodName(name) {}

std::string PaymentMethod::getMethodName() {
    return methodName;
}