#include <bits/stdc++.h>

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentMethod() = default;
};

class UpiPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using UPI\n";
    }
};

class CardPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using Card\n";
    }
};

class WalletPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using Wallet" << std::endl;
    }
};

class CheckoutService {
public:
    void processPayment(PaymentMethod* payment, double amount) {
        payment->pay(amount);
    }
};

// client 
int main() {
    CheckoutService checkout;

    PaymentMethod* upi = new UpiPayment();
    PaymentMethod* card = new CardPayment();
    PaymentMethod* wallet = new WalletPayment();

    checkout.processPayment(upi, 500);
    checkout.processPayment(card, 750);
    checkout.processPayment(wallet, 250);

    delete upi;
    delete card;
    delete wallet;
}