#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareFinish(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start and finish time:\n";
    for (int i = 0; i < n; i++)
        cin >> activities[i].start >> activities[i].finish;

    sort(activities.begin(), activities.end(), compareFinish);

    cout << "\nSelected activities:\n";

    int lastFinish = -1;
    bool selected = false;

    for (const Activity& activity : activities) {
        if (activity.start >= lastFinish) {
            cout << "(" << activity.start
                 << ", " << activity.finish << ")\n";

            lastFinish = activity.finish;
            selected = true;
        }
    }

    if (!selected)
        cout << "No activity selected.\n";

    return 0;
}
