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

        stack<Node *> s1;
        stack<Node *> s2;

        s1.push(currNode);

        while (!s1.empty()) {
            currNode = s1.top();
            s1.pop();

            if (currNode->left != NULL) s1.push(currNode->left);
            if (currNode->right != NULL) s1.push(currNode->right);

            s2.push(currNode);
        }

        while (!s2.empty()) {
            traversal.push_back(s2.top()->data);
            s2.pop();
        }
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
// 4 8 5 2 6 9 10 7 3 1
