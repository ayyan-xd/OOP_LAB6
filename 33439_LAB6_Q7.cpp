#include <iostream>
using namespace std;

class Vehicle {
protected:
    string registrationNo;
    string brand;
    double dailyRate;
    public :
    Vehicle(string regNo, string b, double rate) : registrationNo(regNo), brand(b), dailyRate(rate) {}
    virtual void displayVehicle() {
        cout << "Registration No : " << registrationNo << endl;
        cout << "Brand : " << brand << endl;
        cout << "Daily Rate : $" << dailyRate << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(string regNo, string b, double rate, int doors) : Vehicle(regNo, b, rate), numDoors(doors) {}
    void displayVehicle() override {
        Vehicle :: displayVehicle();
        cout << "Number of Doors : " << numDoors << endl;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;
public:
    ElectricCar(string regNo, string b, double rate, int doors, double capacity) : Car(regNo, b, rate, doors), batteryCapacity(capacity) {}
    void displayVehicle() override {
        Car :: displayVehicle();
        cout << "Battery Capacity : " << batteryCapacity << " kWh" << endl;
    }
    double calculateRentalCost(int days) {
        double totalCost = dailyRate * days;
        return totalCost *  0.85;
    }
};

class Truck : private Vehicle {
private:
    double loadCapacity;
    public:
    Truck(string regNo, string b, double rate, double capacity) : Vehicle(regNo, b, rate), loadCapacity(capacity) {}
    void displayTruck() {
        Vehicle :: displayVehicle();
        cout << "Load Capacity : " << loadCapacity << " tons" << endl;
    }
    /* registrationNo is 'protected' in Vehicle, so it IS accessible inside Truck's 
       member functions. However, because we used 'private inheritance', 
       all public members of Vehicle (like displayVehicle) become private 
       in Truck and cannot be called directly from main() */
};

int main() {
    Car car1("ABC123", "Toyota", 50.0, 4);
    ElectricCar eCar1("XYZ789", "Tesla", 100.0, 4, 75.0);
     Truck truck1("LMN456", "Ford", 80.0, 10.0);
    car1.displayVehicle();
    cout << endl;
    eCar1.displayVehicle();
     cout << "7-Day Rental Cost (with 15% discount): $" << eCar1.calculateRentalCost(7) << endl;
    cout << endl;
    truck1.displayTruck();
    return 0;
}
