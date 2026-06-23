#include <string>

class User {
    private:
        int id;
        std::string name;
        std::string phone;

    public:
        void bookRide();
};

class Driver {
    private:
        int id;
        std::string name;
        bool available;

    public:
        bool isAvailable();
        void acceptRide();
};

enum class RideStatus {
    REQUESTED,
    ACCEPTED,
    STARTED,
    COMPLETED,
    CANCELLED
};

class Ride {
    private:
        int rideId;
        User* user;
        Driver* driver;
        RideStatus status;

    public:
        void startRide();
        void completeRide();
};

class MatchingStrategy {
    public:
        virtual Driver* findDriver() = 0;
};

class NearestDriverStrategy : public MatchingStrategy {
    public:
        Driver* findDriver() override;
};

class RideManager {
    private:
        MatchingStrategy* strategy;

    public:
        Ride* createRide(User* user);
};