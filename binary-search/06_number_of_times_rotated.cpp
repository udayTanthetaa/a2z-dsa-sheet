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
    int numOfTimesRotated(const vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (arr[mid] < arr[next] && arr[mid] < arr[prev]) {
                return mid;
            } else if (arr[0] < arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return 0;
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

    Solution S;

    cout << S.numOfTimesRotated(arr);

    return 0;
}

// == IN ==
// 6
// 4 5 6 1 2 3

// == OUT ==
// 3
