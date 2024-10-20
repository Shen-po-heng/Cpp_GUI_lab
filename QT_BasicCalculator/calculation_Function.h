#ifndef CALCULATION_FUNCTION_H
#define CALCULATION_FUNCTION_H



class calculation_Function{
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
    static double sqrt(double a);         // Square root function
    static double pi();                   // Returns the value of pi
    static double power(double base, double exp);  // Power function
    static unsigned long long factorial(int n);    // Factorial function
};

#endif // CALCULATION_FUNCTION_H
