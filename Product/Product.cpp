#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Product {
private:
    std::string name;
    double price;

public:
    Product(const std::string& name_val, double price_val) : name(name_val), price(price_val) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void setName(const std::string& name_val) {
        name = name_val;
    }

    void setPrice(double price_val) {
        price = price_val;
    }

    bool operator==(const Product& other) const {
        return (name == other.name && price == other.price);
    }
};

class Dish {
private:
    std::string name;
    std::vector<Product> products;

public:
    Dish(const std::string& name_val) : name(name_val) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(const Product& product) {
        auto it = std::find(products.begin(), products.end(), product);
        if (it != products.end()) {
            products.erase(it);
        }
    }

    double calculateTotalPrice() const {
        double totalPrice = 0.0;
        for (const auto& product : products) {
            totalPrice += product.getPrice();
        }
        return totalPrice;
    }

    const std::vector<Product>& getProducts() const {
        return products;
    }

    std::string getName() const {
        return name;
    }

    bool operator==(const Dish& other) const {
        return (name == other.name);
    }
};

class Beverage {
private:
    std::string name;
    std::vector<Product> fruits;

public:
    Beverage(const std::string& name_val) : name(name_val) {}

    void addFruit(const Product& fruit) {
        fruits.push_back(fruit);
    }

    void removeFruit(const Product& fruit) {
        auto it = std::find(fruits.begin(), fruits.end(), fruit);
        if (it != fruits.end()) {
            fruits.erase(it);
        }
    }

    double calculateTotalPrice() const {
        double totalPrice = 0.0;
        for (const auto& fruit : fruits) {
            totalPrice += fruit.getPrice();
        }
        return totalPrice;
    }

    const std::vector<Product>& getFruits() const {
        return fruits;
    }

    std::string getName() const {
        return name;
    }

    bool operator==(const Beverage& other) const {
        return (name == other.name);
    }
};

class Order {
private:
    int tableNumber;
    std::vector<Dish> dishes;
    std::vector<Beverage> beverages;

public:
    Order(int tableNumber_val) : tableNumber(tableNumber_val) {}

    void addDish(const Dish& dish) {
        dishes.push_back(dish);
    }

    void removeDish(const Dish& dish) {
        auto it = std::find(dishes.begin(), dishes.end(), dish);
        if (it != dishes.end()) {
            dishes.erase(it);
        }
    }

    void addBeverage(const Beverage& beverage) {
        beverages.push_back(beverage);
    }

    void removeBeverage(const Beverage& beverage) {
        auto it = std::find(beverages.begin(), beverages.end(), beverage);
        if (it != beverages.end()) {
            beverages.erase(it);
        }
    }

    double calculateTotalPrice() const {
        double totalPrice = 0.0;
        for (const auto& dish : dishes) {
            totalPrice += dish.calculateTotalPrice();
        }
        for (const auto& beverage : beverages) {
            totalPrice += beverage.calculateTotalPrice();
        }
        return totalPrice;
    }

    const std::vector<Dish>& getDishes() const {
        return dishes;
    }

    const std::vector<Beverage>& getBeverages() const {
        return beverages;
    }
};

int main() {
    Product tomato("Tomato", 1.5);
    Product potato("Potato", 2.0);
    Product apple("Apple", 1.0);
    Product orange("Orange", 1.5);

    Dish salad("Salad");
    salad.addProduct(tomato);
    salad.addProduct(potato);

    Dish fruitSalad("Fruit Salad");
    fruitSalad.addProduct(apple);
    fruitSalad.addProduct(orange);

    Beverage juice("Juice");
    juice.addFruit(apple);
    juice.addFruit(orange);

    Order order(1);
    order.addDish(salad);
    order.addDish(fruitSalad);
    order.addBeverage(juice);

    std::cout << "Total price of the order: $" << order.calculateTotalPrice() << std::endl;

    std::cout << "Details of the order:\n";
    for (const auto& dish : order.getDishes()) {
        std::cout << "Dish: " << dish.getName() << ", Price: $" << dish.calculateTotalPrice() << std::endl;
        std::cout << "Products:\n";
        for (const auto& product : dish.getProducts()) {
            std::cout << "- " << product.getName() << ": $" << product.getPrice() << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Beverages in the order:\n";
    for (const auto& beverage : order.getBeverages()) {
        std::cout << "Beverage: " << beverage.getName() << ", Price: $" << beverage.calculateTotalPrice() << std::endl;
        std::cout << "Fruits:\n";
        for (const auto& fruit : beverage.getFruits()) {
            std::cout << "- " << fruit.getName() << ": $" << fruit.getPrice() << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
