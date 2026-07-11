abstract class PaymentMethod {
    abstract pay(amount: number): void;
}

class UpiPayment extends PaymentMethod {
    pay(amount: number): void {
        console.log(`Paid ₹${amount} using UPI`);
    }
}

class CardPayment extends PaymentMethod {
    pay(amount: number): void {
        console.log(`Paid ₹${amount} using Card`);
    }
}

class WalletPayment extends PaymentMethod {
    pay(amount: number): void {
        console.log(`Paid ₹${amount} using Wallet`);
    }
}

class CheckoutService {
    processPayment(payment: PaymentMethod, amount: number): void {
        payment.pay(amount);
    }
}

const checkout = new CheckoutService();

const upi: PaymentMethod = new UpiPayment();
const card: PaymentMethod = new CardPayment();
const wallet: PaymentMethod = new WalletPayment();

checkout.processPayment(upi, 500);
checkout.processPayment(card, 750);
checkout.processPayment(wallet, 250);