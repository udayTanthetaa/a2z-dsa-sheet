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

// Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                candidate = nums[i];
            }
            if(nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
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
    int ans = S.majorityElement(arr);

    cout << ans;

    return 0;
}

// == IN ==
// 7
// 2 2 1 1 1 2 2

// == OUT ==
// 2
