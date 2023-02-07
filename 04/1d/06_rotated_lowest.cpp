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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (nums[mid] < nums[next] && nums[mid] < nums[prev]) {
                return nums[mid];
            } else if (nums[mid] < nums[end]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return nums[0];
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

    cout << S.findMin(arr);

    return 0;
}

// == IN ==
// 7
// 4 5 6 7 0 1 2

// == OUT ==
// 0
