#include <iostream>
using namespace std;

class Ride
{
protected:
    string passengerName;
    int rideID;
    double baseFare;

public:
    Ride(string name, int id, double fare)
    {
        passengerName = name;
        rideID = id;
        baseFare = fare;
    }

    void displayRideDetails()
    {
        cout << "Passenger: " << passengerName << endl;
        cout << "Ride ID: " << rideID << endl;
    }
};

class EconomyRide : public Ride
{
    double distanceKm;

public:
    EconomyRide(string name, int id, double fare, double dist)
        : Ride(name, id, fare)
    {
        distanceKm = dist;
    }

    double calculateFare()
    {
        return baseFare + (distanceKm * 8);
    }

    void show()
    {
        displayRideDetails();
        cout << "Final Fare: " << calculateFare() << endl << endl;
    }
};

class LuxuryRide : public Ride
{
    double distanceKm;
    double serviceCharge;

public:
    LuxuryRide(string name, int id, double fare, double dist, double charge)
        : Ride(name, id, fare)
    {
        distanceKm = dist;
        serviceCharge = charge;
    }

    double calculateFare()
    {
        return baseFare + (distanceKm * 12) + serviceCharge;
    }

    void show()
    {
        displayRideDetails();
        cout << "Final Fare: " << calculateFare() << endl << endl;
    }
};

int main()
{
    EconomyRide e1("Sara", 201, 100, 15);
    LuxuryRide l1("Ahmad", 305, 120, 10, 80);

    e1.show();
    l1.show();

    return 0;
}