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

// Kadane's Algorithm

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        int start = 0;
        int currStart = 0;
        int end = 0;

        for (int i = 0; i < nums.size(); i++) {
            max_ending_here += nums[i];
            
            if(max_ending_here > max_so_far) {
                start = currStart;
                end = i;
                max_so_far = max_ending_here;
            }

            if(max_ending_here < 0) {
                currStart = i+1;
                max_ending_here = 0;
            }
        }

        vector<int> ans;
        for (int i = start; i <= end; i++) {
            ans.push_back(nums[i]);
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

    Solution S;
    vector<int> ans = S.maxSubArray(arr);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// == IN ==
// 9
// -2 1 -3 4 -1 2 1 -5 4
// 6

// == OUT ==
// 4 -1 2 1
