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
    void traverse(vector<int> &traversal, Node *root) {
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                Node *currNode = q.front();
                q.pop();

                if (currNode->left != NULL) q.push(currNode->left);
                if (currNode->right != NULL) q.push(currNode->right);

                traversal.push_back(currNode->data);
            }
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
// 1 2 3 4 5 6 7 8 9 10
