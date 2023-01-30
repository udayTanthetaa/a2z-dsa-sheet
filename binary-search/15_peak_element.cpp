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
    int peakElement(const vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
                (mid == arr.size() - 1 || arr[mid] < arr[mid + 1])) {
                break;
            }

            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return mid;
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

    cout << S.peakElement(arr);

    return 0;
}

// == IN ==
// 9
// 30 40 50 5 10 20 30 40 50

// == OUT ==
// 10
