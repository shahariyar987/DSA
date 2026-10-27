#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

    void build(const vector<int>& arr,
               int node,
               int left,
               int right) {
        if (left == right) {
            tree[node] = arr[left];
            return;
        }

        int mid = (left + right) / 2;

        build(arr, node * 2, left, mid);
        build(arr, node * 2 + 1, mid + 1, right);

        tree[node] =
            tree[node * 2] +
            tree[node * 2 + 1];
    }

    void update(int node,
                int left,
                int right,
                int index,
                int value) {
        if (left == right) {
            tree[node] = value;
            return;
        }

        int mid = (left + right) / 2;

        if (index <= mid)
            update(node * 2, left, mid,
                   index, value);
        else
            update(node * 2 + 1, mid + 1, right,
                   index, value);

        tree[node] =
            tree[node * 2] +
            tree[node * 2 + 1];
    }

    long long query(int node,
                    int left,
                    int right,
                    int queryLeft,
                    int queryRight) {
        if (queryRight < left ||
            right < queryLeft)
            return 0;

        if (queryLeft <= left &&
            right <= queryRight)
            return tree[node];

        int mid = (left + right) / 2;

        return query(node * 2, left, mid,
                     queryLeft, queryRight)
             + query(node * 2 + 1, mid + 1, right,
                     queryLeft, queryRight);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void updateValue(int index, int value) {
        update(1, 0, n - 1, index, value);
    }

    long long rangeSum(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree tree(arr);

    int index, value;

    cout << "Enter index and new value: ";
    cin >> index >> value;

    if (index >= 0 && index < n) {
        tree.updateValue(index, value);

        int left, right;

        cout << "Enter range for sum query: ";
        cin >> left >> right;

        if (left >= 0 && right < n && left <= right)
            cout << "Updated range sum = "
                 << tree.rangeSum(left, right) << "\n";
        else
            cout << "Invalid range.\n";
    } else {
        cout << "Invalid index.\n";
    }

    return 0;
}
