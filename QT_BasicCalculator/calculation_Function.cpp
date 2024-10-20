#include "calculation_Function.h"
#include <cmath>
#include <stdexcept>

double calculation_Function::add(double a, double b) {
    return a + b;
}

double calculation_Function::subtract(double a, double b) {
    return a - b;
}

double calculation_Function::multiply(double a, double b) {
    return a * b;
}

double calculation_Function::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}

double calculation_Function::sqrt(double a) {
    if (a < 0) {
        throw std::invalid_argument("Negative number cannot have a square root!");
    }
    return std::sqrt(a);
}

double calculation_Function::pi() {
    return M_PI;  // Pi constant from <cmath>
}

double calculation_Function::power(double base, double exp) {
    return std::pow(base, exp);
}

unsigned long long calculation_Function::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial of negative number is undefined!");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

