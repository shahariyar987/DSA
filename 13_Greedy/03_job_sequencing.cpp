#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareProfit(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job ID, deadline and profit:\n";

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;

        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), compareProfit);

    vector<char> schedule(maxDeadline + 1, '-');
    vector<bool> used(maxDeadline + 1, false);

    int totalProfit = 0;

    for (const Job& job : jobs) {
        for (int slot = job.deadline; slot >= 1; slot--) {
            if (!used[slot]) {
                schedule[slot] = job.id;
                used[slot] = true;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "\nJob sequence: ";

    for (int i = 1; i <= maxDeadline; i++)
        if (used[i])
            cout << schedule[i] << " ";

    cout << "\nTotal profit = " << totalProfit << "\n";

    return 0;
}
