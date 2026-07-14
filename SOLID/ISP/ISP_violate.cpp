#include <iostream>

class Driver {
public:
    virtual void acceptRide() = 0;
    virtual void completeRide() = 0;
    virtual void uploadDocuments() = 0;
    virtual void approveDriver() = 0;

    virtual ~Driver() = default;
};

class BikeDriver : public Driver {
public:
    void acceptRide() override {
        std::cout << "Bike Driver accepted ride\n";
    }

    void completeRide() override {
        std::cout << "Bike Driver completed ride\n";
    }

    void uploadDocuments() override {
        std::cout << "Bike Driver uploaded documents\n";
    }

    void approveDriver() override {
        std::cout << "❌ Bike Driver should never approve drivers!\n";
    }
};

int main() {
    BikeDriver driver;

    driver.acceptRide();
    driver.completeRide();
    driver.uploadDocuments();
    driver.approveDriver();   // Doesn't make sense

    return 0;
}