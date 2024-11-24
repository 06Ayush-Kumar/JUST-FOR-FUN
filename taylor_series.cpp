// code for solving taylor series problem

#include <iostream>
#include <cmath>
using namespace std;

// Exponential function: exp(x)
double expDerivative(int n, double a) {
    return exp(a); // All derivatives of exp(x) are the same
}

// Sine function: sin(x)
double sinDerivative(int n, double a) {
    switch (n % 4) {
        case 0: return sin(a);
        case 1: return cos(a);
        case 2: return -sin(a);
        case 3: return -cos(a);
        default: return 0;
    }
}

// Cosine function: cos(x)
double cosDerivative(int n, double a) {
    switch (n % 4) {
        case 0: return cos(a);
        case 1: return -sin(a);
        case 2: return -cos(a);
        case 3: return sin(a);
        default: return 0;
    }
}

// Power function: x^n
double powerDerivative(int n, double a) {
    if (n == 0) return 1;  // 0th derivative of x^n is x^n = 1
    return pow(a, n); // nth derivative is a^n
}

// Logarithmic function: ln(x)
double lnDerivative(int n, double a) {
    if (n == 0) return log(a);  // 0th derivative of ln(x) is ln(x)
    if (n == 1) return 1 / a;   // 1st derivative of ln(x) is 1/x
    return -(n-1) * pow(a, -n); // Higher derivatives follow the pattern
}

// Square root function: sqrt(x)
double sqrtDerivative(int n, double a) {
    if (n == 0) return sqrt(a);    // 0th derivative of sqrt(x) is sqrt(x)
    if (n == 1) return 1 / (2 * sqrt(a));  // 1st derivative of sqrt(x) is 1/(2sqrt(x))
    return (n-1) * pow(a, -(n+1)/2.0);  // Higher derivatives
}

// Generic Taylor series function
double taylorSeries(double (*funcDerivative)(int, double), double a, double x, int terms) {
    double result = 0;
    for (int n = 0; n < terms; n++) {
        result += (funcDerivative(n, a) * pow(x - a, n)) / tgamma(n + 1); // n! = tgamma(n + 1)
    }
    return result;
}

int main() {
    double a, x;
    int terms, choice;

    // Prompt user to select function
    cout << "Select the function for Taylor Series expansion:" << endl;
    cout << "1. exp(x)" << endl;
    cout << "2. sin(x)" << endl;
    cout << "3. cos(x)" << endl;
    cout << "4. x^n" << endl;
    cout << "5. ln(x)" << endl;
    cout << "6. sqrt(x)" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    // Prompt for a point 'a' (around which to expand the series) and the point 'x' (where to approximate)
    cout << "Enter the point of expansion 'a': ";
    cin >> a;
    cout << "Enter the value 'x' to approximate at: ";
    cin >> x;

    // Prompt for number of terms in the Taylor series expansion
    cout << "Enter the number of terms to approximate (higher for better accuracy): ";
    cin >> terms;

    // Calculate and display the result based on the user's choice
    double result = 0;
    switch (choice) {
        case 1:
            result = taylorSeries(expDerivative, a, x, terms);
            cout << "Approximation of exp(" << x << ") around " << a << " is: " << result << endl;
            break;
        case 2:
            result = taylorSeries(sinDerivative, a, x, terms);
            cout << "Approximation of sin(" << x << ") around " << a << " is: " << result << endl;
            break;
        case 3:
            result = taylorSeries(cosDerivative, a, x, terms);
            cout << "Approximation of cos(" << x << ") around " << a << " is: " << result << endl;
            break;
        case 4:
            result = taylorSeries(powerDerivative, a, x, terms);
            cout << "Approximation of x^n for x = " << x << " around a = " << a << " is: " << result << endl;
            break;
        case 5:
            result = taylorSeries(lnDerivative, a, x, terms);
            cout << "Approximation of ln(" << x << ") around " << a << " is: " << result << endl;
            break;
        case 6:
            result = taylorSeries(sqrtDerivative, a, x, terms);
            cout << "Approximation of sqrt(" << x << ") around " << a << " is: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

