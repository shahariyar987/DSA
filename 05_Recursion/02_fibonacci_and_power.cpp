#include <iostream>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long power(int base, int exponent) {
    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

int main() {
    int n, base, exponent;

    cout << "Enter Fibonacci position: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid Fibonacci position.\n";
    } else {
        cout << "Fibonacci(" << n << ") = "
             << fibonacci(n) << endl;
    }

    cout << "\nEnter base: ";
    cin >> base;

    cout << "Enter non-negative exponent: ";
    cin >> exponent;

    if (exponent < 0) {
        cout << "Invalid exponent.\n";
    } else {
        cout << base << "^" << exponent << " = "
             << power(base, exponent) << endl;
    }

    return 0;
}
