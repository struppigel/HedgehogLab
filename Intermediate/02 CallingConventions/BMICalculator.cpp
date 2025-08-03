#include <iostream>

class Person {
private:
    int weight;  // in kilograms
    int height;  // in centimeters

public:
    // Constructor
    Person(int w, int h) : weight(w), height(h) {}

    // Method to calculate BMI
    double calculateBMI() const {
        double heightInMeters = height / 100.0;
        return weight / (heightInMeters * heightInMeters);
    }

    // Method to check if the BMI is in a healthy range
    bool isHealthyBMI() const {
        double bmi = calculateBMI();
        return bmi >= 18.5 && bmi <= 24.9;
    }

    // Method to print whether the BMI is healthy or not
    void printHealthStatus() const {
        if (isHealthyBMI()) {
            std::cout << "The BMI is in a healthy range." << std::endl;
        } else {
            std::cout << "The BMI is outside the healthy range." << std::endl;
        }
    }
};

int main() {
    // Creating a person object with weight 70kg and height 175cm
    Person person(70, 175);

    // Display BMI and health status
    std::cout << "BMI: " << person.calculateBMI() << std::endl;
    person.printHealthStatus();

    return 0;
}