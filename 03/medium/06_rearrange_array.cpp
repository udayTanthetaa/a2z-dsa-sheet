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
    vector<int> rearrangeArray(const vector<int>& nums) {
        vector<int> newNums(nums.size(), 0);

        int i, j;
        i = 0;
        j = 1;

        for (int k = 0; k < nums.size(); k++) {
            int temp = nums[k];

            if(temp >= 0) {
                newNums[i] = temp;
                i = i + 2;
            }
            else
            {
                newNums[j] = temp;
                j = j + 2;
            }
        }

        return newNums;
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
    vector<int> ans = S.rearrangeArray(arr);

    for (int i = 0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// == IN ==
// 6
// 3 1 -2 -5 2 -4

// == OUT ==
// 3 -2 1 -5 2 -4 
