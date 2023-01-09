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
    void missingAndRepeating(const vector<int>& nums) {
        // a -> missing
        // b -> repeating

        int a, b;

        int n;
        n = nums.size();

        int Sn = (n * (n+1)) / 2;
        int Sn2 = (n * (n+1) * (2 * n + 1)) / 6;

        int arrSn = 0;
        int arrSn2 = 0;

        // bma = b - a
        // bpa - b + a
        int bma = 0;
        int bpa = 0;

        for (int i = 0; i<n; i++) {
            bma += nums[i];
            bpa += (nums[i] * nums[i]);
        }

        bma = bma - Sn;
        bpa = (bpa - Sn2) / bma;

        b = (bma + bpa) / 2;
        a = (bpa - bma) / 2;

        cout << a << " " << b;
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

    S.missingAndRepeating(arr);

    return 0;
}

// == IN ==
// 5
// 1 2 2 3 4

// == OUT ==
// 5 2
