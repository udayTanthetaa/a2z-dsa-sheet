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
    int maxProfit(vector<int>& prices) {
        int min_so_far, max_so_far, max_profit;
        min_so_far = max_so_far = prices[0];
        max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if(prices[i] > max_so_far) {
                max_so_far = prices[i];
                max_profit = max(max_profit, max_so_far - min_so_far);
            }

            if(prices[i] < min_so_far) {
                min_so_far = max_so_far = prices[i];
            }
        }

        return max_profit;
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
    cout<<S.maxProfit(arr);

    return 0;
}

// == IN ==
// 6
// 7 1 5 3 6 4 

// == OUT ==
// 5
