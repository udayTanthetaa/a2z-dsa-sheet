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
    int getFirst(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        int candidate = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                candidate = mid;
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return candidate;
    }

    int getLast(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        int candidate = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                candidate = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return candidate;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getFirst(nums, target);
        int last = getLast(nums, target);

        return {first, last};
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

    vector<int> ans = S.searchRange(arr, search);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// == IN ==
// 6
// 5 7 7 8 8 10
// 8

// == OUT ==
// 3 4
