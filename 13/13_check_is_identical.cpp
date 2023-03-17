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
    bool isIdentical(Node *currNode1, Node *currNode2) {
        if (currNode1 == NULL && currNode2 == NULL)
            return true;
        else if (currNode1 == NULL || currNode2 == NULL)
            return false;

        return (currNode1->data == currNode2->data) &&
               isIdentical(currNode1->left, currNode2->left) &&
               isIdentical(currNode1->right, currNode2->right);
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

    cout << S.isIdentical(root, root);

    return 0;
}

// == IN ==

// == OUT ==
// 1
