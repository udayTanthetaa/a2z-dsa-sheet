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
    int maxConsecutiveOnes(const vector<int>& nums) {
        int n = nums.size();
        int maxOnes = 0;
        int currOnes = 0;

        for (int i = 0; i<n; i++) {
            if(nums[i] == 1) {
                currOnes++;
                maxOnes = max(maxOnes, currOnes);
            } else {
                currOnes = 0;
            }
        }

        return maxOnes;
    }
};


int main() {
	stayTORO();

    Solution S;

    int n;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout<<S.maxConsecutiveOnes(arr);

    return 0;
}

// == IN ==
// 5
// 1 2 3 4 0

// == OUT ==
// 5
