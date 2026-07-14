#include <iostream>

class CardPayment {
public:
    void pay(double amount) {
        std::cout << "Paid ₹" << amount
                  << " using Card\n";
    }
};

class CheckoutService {

private:
    CardPayment payment;

public:

    void checkout(double amount) {
        payment.pay(amount);
    }
};

int main() {

    CheckoutService checkout;

    checkout.checkout(500);

    return 0;
}