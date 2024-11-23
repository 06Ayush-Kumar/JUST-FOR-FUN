// code for solving taylor series problem

#include <iostream>
#include <cmath>
using namespace std;

// Function to compute factorial
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Generalized function to calculate Taylor series

double taylorSeries(double (*f)(int, double), double x, double a, int terms) {
    double result = 0.0;

    for (int n = 0; n < terms; ++n) {
        double nth_derivative_at_a = f(n, a);
        result += (nth_derivative_at_a * pow(x - a, n)) / factorial(n);
    }
    return result;
}

// Example: nth derivative of sin(x) at a
double sinDerivatives(int n, double a) {
    // Cycle through sin, cos, -sin, -cos
    switch (n % 4) {
        case 0: return sin(a);  // sin(a)
        case 1: return cos(a);  // cos(a)
        case 2: return -sin(a); // -sin(a)
        case 3: return -cos(a); // -cos(a)
    }
    return 0; // Fallback, shouldn't be hit
}

int main() {
    double x, a;
    int terms;

    // Input the point of expansion (a), the evaluation point (x), and the number of terms
    cout << "Enter the point of expansion (a): ";
    cin >> a;
    cout << "Enter the point to evaluate (x): ";
    cin >> x;
    cout << "Enter the number of terms in the Taylor series: ";
    cin >> terms;

    // Calculate Taylor series for sin(x)
    double result = taylorSeries(sinDerivatives, x, a, terms);

    // Output the result
    cout << "Approximation of sin(" << x << ") using Taylor series around " << a 
         << " with " << terms << " terms: " << result << endl;

    // Compare with actual value
    cout << "Actual value using sin(): " << sin(x) << endl;

    return 0;
}
