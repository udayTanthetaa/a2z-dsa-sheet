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
    bool isValid(const vector<int> &arr, const int maxStudents,
                 const int check) {
        int currStudents = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > check) {
                return false;
            }

            if (currSum + arr[i] > check) {
                currStudents++;
                currSum = 0;

                if (currStudents > maxStudents) {
                    return false;
                }
            } else {
                currSum += arr[i];
            }
        }

        return true;
    }

    int minimumPages(const vector<int> &arr, const int n) {
        int start = INT_MIN;
        int end = 0;

        int ans = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            start = max(start, arr[i]);
            end += arr[i];
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(arr, n, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
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

    int students;
    cin >> students;

    Solution S;

    cout << S.minimumPages(arr, students);

    return 0;
}

// == IN ==
// 4
// 12 34 67 90
// 2

// == OUT ==
// 113
