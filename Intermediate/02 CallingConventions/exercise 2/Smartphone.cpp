#include <iostream>
#include <string>

class Smartphone {

public:
    std::string brand;
    std::string model;
    int batteryCapacity;  // in mAh
    int storageCapacity;  // in GB
    int ram;              // in GB
    double screenSize;     // in inches

    // Constructor to initialize a smartphone
    Smartphone(std::string b, std::string m, int battery, int storage, int ramSize, double screen) {
        brand = b;
        model = m;
        batteryCapacity = battery;
        storageCapacity = storage;
        ram = ramSize;
        screenSize = screen;
    }

    // Method to calculate remaining battery after use
    __declspec(noinline) void useBattery(int usage) {
        if (usage > batteryCapacity) {
            std::cout << "Not enough battery for this usage." << std::endl;
        }
        else {
            batteryCapacity -= usage;
            std::cout << "Battery after usage: " << batteryCapacity << " mAh" << std::endl;
        }
    }

    // Method to check if the phone has enough storage for a new app
    __declspec(noinline) bool canInstallApp(int appSize) {
        if (appSize <= storageCapacity) {
            std::cout << "You can install the app." << std::endl;
            return true;
        }
        else {
            std::cout << "Not enough storage to install the app." << std::endl;
            return false;
        }
    }
};

int main() {
    // Create a new smartphone object
    Smartphone phone("Samsung", "Galaxy S21", 4000, 128, 8, 6.2);

    // Display the smartphone's details
    std::cout << "Brand: " << phone.brand << std::endl;
    std::cout << "Model: " << phone.model << std::endl;
    std::cout << "Battery Capacity: " << phone.batteryCapacity << " mAh" << std::endl;
    std::cout << "Storage Capacity: " << phone.storageCapacity << " GB" << std::endl;
    std::cout << "RAM: " << phone.ram << " GB" << std::endl;
    std::cout << "Screen Size: " << phone.screenSize << " inches" << std::endl;
    std::cout << std::endl;

    // Use some battery and check remaining
    phone.useBattery(500);

    // Check if an app can be installed
    phone.canInstallApp(50);

    return 0;
}
