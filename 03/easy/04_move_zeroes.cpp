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
    void moveZeroes(vector<int>& nums) {
        // i -> zero
        // j -> non-zero

        int i = 0;
        int j = INT_MAX;

        for (int k = 0; k < nums.size(); k++) {
            if(nums[k] == 0) {
                i = k;
                break;
            }
        }

        if(nums[i] == 0) {
            j = i + 1;
        }

        while(i < nums.size() && j < nums.size()) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};


int main() {
	stayTORO();

    Solution S;

    int n, rotations;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    S.moveZeroes(arr);

    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// == IN ==
// 5
// 0 1 0 3 2

// == OUT ==
// 1 3 2 0 0
