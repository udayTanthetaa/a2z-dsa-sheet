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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);

        map<int, bool> mp;

        for (int i = 0; i < nums.size(); i++) {
            if(mp[target - nums[i]] == true) {
                ans[0] = nums[i];
                ans[1] = target - nums[i];
            } else {
                mp[nums[i]] = true;
            }
        }

        return ans;
    }
};

int main() {
	stayTORO();

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    vector<int> ans(2);

    Solution S;
    ans = S.twoSum(arr, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}

// == IN ==
// 4
// 2 7 11 15
// 9

// == OUT ==
// 7 2
