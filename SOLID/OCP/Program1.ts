// Product class representing any item in eCommerce.
class Product {
    constructor(
        public name: string,
        public price: number
    ) {}
}

// ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
    private products: Product[] = [];

    addProduct(product: Product): void {
        this.products.push(product);
    }

    getProducts(): Product[] {
        return this.products;
    }

    calculateTotal(): number {
        return this.products.reduce((total, product) => total + product.price, 0);
    }
}

// ShoppingCartPrinter: Only responsible for printing invoices.
class ShoppingCartPrinter {
    constructor(private cart: ShoppingCart) {}

    printInvoice(): void {
        console.log("Shopping Cart Invoice:");

        for (const product of this.cart.getProducts()) {
            console.log(`${product.name} - Rs ${product.price}`);
        }

        console.log(`Total: Rs ${this.cart.calculateTotal()}`);
    }
}

// Abstract class
abstract class Persistence {
    abstract save(cart: ShoppingCart): void;
}

// SQL implementation
class SQLPersistence extends Persistence {
    save(cart: ShoppingCart): void {
        console.log("Saving shopping cart to SQL Database...");
    }
}

// MongoDB implementation
class MongoPersistence extends Persistence {
    save(cart: ShoppingCart): void {
        console.log("Saving shopping cart to MongoDB...");
    }
}

// File implementation
class FilePersistence extends Persistence {
    save(cart: ShoppingCart): void {
        console.log("Saving shopping cart to File...");
    }
}

const cart = new ShoppingCart();

cart.addProduct(new Product("Laptop", 50000));
cart.addProduct(new Product("Mouse", 2000));

const printer = new ShoppingCartPrinter(cart);
printer.printInvoice();

const sql: Persistence = new SQLPersistence();
const mongo: Persistence = new MongoPersistence();
const file: Persistence = new FilePersistence();

sql.save(cart);
mongo.save(cart);
file.save(cart);