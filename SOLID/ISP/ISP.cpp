#include <iostream>

class RideOperations {
public:
    virtual void acceptRide() = 0;
    virtual void completeRide() = 0;

    virtual ~RideOperations() = default;
};

class DocumentOperations {
public:
    virtual void uploadDocuments() = 0;

    virtual ~DocumentOperations() = default;
};

class DriverApproval {
public:
    virtual void approveDriver() = 0;

    virtual ~DriverApproval() = default;
};

class BikeDriver :
    public RideOperations,
    public DocumentOperations {

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
};

class Admin : public DriverApproval {

public:
    void approveDriver() override {
        std::cout << "Admin approved driver\n";
    }
};

int main() {

    BikeDriver bike;

    bike.acceptRide();
    bike.completeRide();
    bike.uploadDocuments();

    std::cout << std::endl;

    Admin admin;

    admin.approveDriver();

    return 0;
}