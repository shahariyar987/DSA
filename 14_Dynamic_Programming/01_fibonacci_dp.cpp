#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "n must be non-negative.\n";
        return 0;
    }

    vector<long long> dp(n + 1);

    if (n >= 0)
        dp[0] = 0;

    if (n >= 1)
        dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << "Fibonacci(" << n << ") = " << dp[n] << "\n";

    cout << "DP table: ";
    for (int i = 0; i <= n; i++)
        cout << dp[i] << " ";

    cout << "\n";

    return 0;
}
