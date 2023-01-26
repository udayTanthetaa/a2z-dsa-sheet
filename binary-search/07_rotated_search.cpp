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
    int rotatedSearch(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                return mid;
            } else if (arr[start] < arr[mid]) {
                if (arr[start] < search) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (search < arr[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }

        return -1;
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

    cout << S.rotatedSearch(arr, search);

    return 0;
}

// == IN ==
// 6
// 4 5 6 1 2 3
// 5

// == OUT ==
// 1
