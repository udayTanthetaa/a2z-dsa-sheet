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
    int bitonicMax(const vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        int mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if ((arr[mid] == 0 || arr[mid] > arr[mid - 1]) &&
                (arr[mid] == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                break;
            }

            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return arr[mid];
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

    cout << S.bitonicMax(arr);

    return 0;
}

// == IN ==
// 6
// 1 3 8 12 4 2

// == OUT ==
// 12
