#include "User.h"
#include "../payments/PaymentMethod.h"
class Customer : public User
{
private:
    std::vector<PaymentMethod *> paymentMethods;

public:
    Customer(const std::string &username, const std::string &password);
    ~Customer();

    void addPaymentMethod(PaymentMethod *method);
    void removePaymentMethod(const std::string &methodName);

    std::string getUserType() const override;

    const std::vector<PaymentMethod *> &getPaymentMethods() const;
};