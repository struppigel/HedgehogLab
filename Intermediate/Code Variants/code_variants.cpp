#include <iostream>
#include <cstdlib>  
#include <ctime>    

#define USE_VARIANT1

#ifdef USE_VARIANT2
__declspec(noinline) int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    }
    else {
        std::cerr << "Modulus by zero error!" << std::endl;
        return 0;
    }
}
#endif

__declspec(noinline) int add(int a, int b) {
    return a + b;
}

__declspec(noinline) int subtract(int a, int b) {
    return a - b;
}

__declspec(noinline) int multiply(int a, int b) {
    return a * b;
}

__declspec(noinline) double divide(double a, double b) {
    if (b != 0.0) {
        return a / b;
    }
    else {
        std::cerr << "Division by zero error!" << std::endl;
        return 0;
    }
}

#ifdef USE_VARIANT1
int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));

    int a = std::rand() % 100; 
    int b = std::rand() % 100 + 1;  

    int sum = add(a, b);
    int difference = subtract(a, b);
    int product = multiply(a, b);
    double quotient = divide(static_cast<double>(a), static_cast<double>(b));

    std::cout << "Random number a: " << a << std::endl;
    std::cout << "Random number b: " << b << std::endl;
    std::cout << "Addition: " << a << " + " << b << " = " << sum << std::endl;
    std::cout << "Subtraction: " << a << " - " << b << " = " << difference << std::endl;
    std::cout << "Multiplication: " << a << " * " << b << " = " << product << std::endl;
    std::cout << "Division: " << a << " / " << b << " = " << quotient << std::endl;

    return 0;
}

#else
int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int c = std::rand() % 100 + 1;
    int a = std::rand() % 100;  
    int b = std::rand() % 100 + 1;  

    int mod = modulus(a, c);
    int sum = add(a, b);
    int difference = subtract(a, b);
    int product = multiply(a, b);
    double quotient = divide(static_cast<double>(a), static_cast<double>(b));
      
    std::cout << "Modulus: " << a << " % " << c << " = " << mod << std::endl;
    std::cout << "Random number a: " << a << std::endl;
    std::cout << "Random number b: " << b << std::endl;
    std::cout << "Addition: " << a << " + " << b << " = " << sum << std::endl;
    std::cout << "Subtraction: " << a << " - " << b << " = " << difference << std::endl;
    std::cout << "Multiplication: " << a << " * " << b << " = " << product << std::endl;
    std::cout << "Division: " << a << " / " << b << " = " << quotient << std::endl;
  
    return 0;
}
#endif