#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values:\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter target amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int current = 1; current <= amount; current++) {
        for (int coin : coins) {
            if (coin <= current &&
                dp[current - coin] != INT_MAX) {
                dp[current] =
                    min(dp[current],
                        dp[current - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        cout << "Amount cannot be formed.\n";
    else
        cout << "Minimum coins required = "
             << dp[amount] << "\n";

    return 0;
}
