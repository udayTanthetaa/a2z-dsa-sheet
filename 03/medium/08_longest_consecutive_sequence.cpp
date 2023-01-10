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
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> ump;

        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]] = true;
        }

        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            int currNum = nums[i];
            int currLongest = 0;

            if(ump[currNum - 1] == false) {
                while(ump[currNum] == true) {
                    currNum += 1;
                    currLongest++;
                }
            }

            longest = max(longest, currLongest);
        }

        return longest;
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
    cout<<S.longestConsecutive(arr);

    return 0;
}

// == IN ==
// 6
// 100 4 200 1 3 2

// == OUT ==
// 4
