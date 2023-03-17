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

struct Node {
    int data;
    Node *left, *right;

    Node(int _data) {
        data = _data;
        left = right = NULL;
    }
};

class Solution {
   public:
    int maxSum(Node *currNode, int &sum) {
        if (currNode == NULL) return 0;

        int leftSum = max(0, maxSum(currNode->left, sum));
        int rightSum = max(0, maxSum(currNode->right, sum));

        sum = max(sum, currNode->data + leftSum + rightSum);

        return currNode->data + max(leftSum, rightSum);
    }

    int maxSumPath(Node *currNode) {
        int sum = INT_MIN;
        maxSum(currNode, sum);
        return sum;
    }
};

int main() {
    stayTORO();

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    Solution S;

    cout << S.maxSumPath(root);

    return 0;
}

// == IN ==

// == OUT ==
// 36
