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
    void nextPermutation(vector<int>& nums) {
        int breakpoint = -1;
        int justMax;

        // Finding breakpoint
        for (int k = nums.size() - 2; k >= 0; k--)
        {
            if(nums[k] < nums[k+1]) {
                breakpoint = k;
                break;
            }
        }

        if(breakpoint == -1) {
            // Reversing
            reverse(nums.begin(), nums.end());
        } else {
            // Finding just max element than breakpoint
            for (int k = nums.size() - 1; k >= 0; k--)
            {
                if(nums[k] > nums[breakpoint]) {
                    justMax = k;
                    break;
                }
            } 

            // Swapping
            swap(nums[breakpoint], nums[justMax]);

            // Reversing
            reverse(nums.begin() + breakpoint + 1, nums.end());
        }
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
    S.nextPermutation(arr);

    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// == IN ==
// 3
// 1 2 3

// == OUT ==
// 1 3 2
