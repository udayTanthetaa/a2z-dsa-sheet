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
    void traverse(vector<int> &traversal, Node *currNode) {
        if (currNode == NULL) {
            return;
        }

        traversal.push_back(currNode->data);
        traverse(traversal, currNode->left);
        traverse(traversal, currNode->right);
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
    vector<int> traversal;

    S.traverse(traversal, root);

    for (int i = 0; i < traversal.size(); i++) {
        cout << traversal[i] << " ";
    }

    return 0;
}

// == IN ==

// == OUT ==
// 1 2 4 5 8 3 6 7 9 10
