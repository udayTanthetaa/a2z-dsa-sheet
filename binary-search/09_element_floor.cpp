#include <bits/stdc++.h>

using namespace std;

void stayTORO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution {
   public:
    int elementFloor(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;
        int floor = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                return mid - 1;
            } else if (arr[mid] < search) {
                floor = max(floor, arr[mid]);
            }

            if (arr[mid] > search) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return floor;
    }
};

int main() {
    stayTORO();

    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int search;
    cin >> search;

    Solution S;

    cout << S.elementFloor(arr, search);

    return 0;
}

// == IN ==
// 6
// 5 10 20 30 40 50
// 21

// == OUT ==
// 20
