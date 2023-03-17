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
    Node *left;
    Node *right;

    Node(int _data) {
        data = _data;
        left = right = NULL;
    }
};

int main() {
    stayTORO();

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    return 0;
}

// == IN ==

// == OUT ==
