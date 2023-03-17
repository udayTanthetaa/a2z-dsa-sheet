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
    int maxHeight(Node *currNode, int &diamter) {
        if (currNode == NULL) return 0;

        int leftHeight = maxHeight(currNode->left, diamter);
        int rightHeight = maxHeight(currNode->right, diamter);

        diamter = max(diamter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int getDiamter(Node *currNode) {
        int diameter = 0;
        maxHeight(currNode, diameter);
        return diameter;
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

    cout << S.getDiamter(root);

    return 0;
}

// == IN ==

// == OUT ==
// 6
