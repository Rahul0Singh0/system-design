// Product class representing any item in an e-commerce system.
class Product {
    constructor(
        public name: string,
        public price: number
    ) {}
}

// Violating SRP: ShoppingCart handles multiple responsibilities
class ShoppingCart {
    private products: Product[] = [];

    addProduct(product: Product): void {
        this.products.push(product);
    }

    getProducts(): Product[] {
        return this.products;
    }

    calculateTotal(): number {
        let total = 0;

        for (const product of this.products) {
            total += product.price;
        }

        return total;
    }

    printInvoice(): void {
        console.log("Shopping Cart Invoice");

        for (const product of this.products) {
            console.log(`${product.name} - Rs ${product.price}`);
        }

        console.log(`Total: Rs ${this.calculateTotal()}`);
    }

    saveToDatabase(): void {
        console.log("Saving shopping cart to database...");
    }
}

//  Client side

const cart = new ShoppingCart();

cart.addProduct(new Product("Laptop", 50000));
cart.addProduct(new Product("Mouse", 2000));

cart.printInvoice();
cart.saveToDatabase();