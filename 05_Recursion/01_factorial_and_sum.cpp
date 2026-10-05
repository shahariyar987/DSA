#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int sumToN(int n) {
    if (n == 0)
        return 0;

    return n + sumToN(n - 1);
}

int main() {
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    cout << "Factorial = " << factorial(n) << endl;
    cout << "Sum from 1 to " << n << " = " << sumToN(n) << endl;

    return 0;
}
