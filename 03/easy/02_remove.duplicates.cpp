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
    void removeDuplicates(vector<int> &arr) {
        int i = 0;
        for (int j = 0; j < arr.size(); j++) {
            if(arr[i] != arr[j]) {
                i++;
                arr[i] = arr[j];
            }
        }

        arr.resize(i + 1);
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

    S.removeDuplicates(arr);

    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// == IN ==
// 8
// 1 1 2 2 2 3 3 3

// == OUT ==
// 1 2 3 
