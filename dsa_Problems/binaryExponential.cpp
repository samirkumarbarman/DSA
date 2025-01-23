#include <iostream>
using namespace std;

// Function to calculate x^n using Exponentiation by Squaring
double power(double x, int n) {
    if (n == 0)
        return 1;
    double temp = power(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else {
        if (n > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

int main() {
    double x;
    int n;

    // Input base and exponent
    cout << "Enter base x: ";
    cin >> x;
    cout << "Enter exponent n: ";
    cin >> n;

    // Calculate x^n
    double result = power(x, n);

    // Output the result
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
