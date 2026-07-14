#include <iostream>

class PaymentMethod {

public:
    virtual void pay(double amount) = 0;

    virtual ~PaymentMethod() = default;
};

class CardPayment : public PaymentMethod {

public:

    void pay(double amount) override {

        std::cout << "Paid ₹"
                  << amount
                  << " using Card\n";
    }
};

class UpiPayment : public PaymentMethod {

public:

    void pay(double amount) override {

        std::cout << "Paid ₹"
                  << amount
                  << " using UPI\n";
    }
};

class WalletPayment : public PaymentMethod {

public:

    void pay(double amount) override {

        std::cout << "Paid ₹"
                  << amount
                  << " using Wallet\n";
    }
};

class CheckoutService {

public:

    void checkout(PaymentMethod* payment,
                  double amount) {

        payment->pay(amount);
    }
};

int main() {

    CheckoutService checkout;

    PaymentMethod* card = new CardPayment();
    PaymentMethod* upi = new UpiPayment();
    PaymentMethod* wallet = new WalletPayment();

    checkout.checkout(card, 500);
    checkout.checkout(upi, 800);
    checkout.checkout(wallet, 1000);

    delete card;
    delete upi;
    delete wallet;

    return 0;
}