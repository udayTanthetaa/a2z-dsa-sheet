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

// Extended Moore's Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            } else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> ans;

        count1 = count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate1) {
                count1++;
            }

            if(nums[i] == candidate2) {
                count2++;
            }
        }

        if (count1 > floor(nums.size() / 3))
        {
            ans.push_back(candidate1);
        }

        if(count2 > floor(nums.size()/3)) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};

int main() {
	stayTORO();

    int n;
    cin>>n;

    vector<int> arr(n, 0);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    Solution S;
    vector<int> ans = S.majorityElement(arr);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// == IN ==
// 3
// 3 2 3

// == OUT ==
// 3
