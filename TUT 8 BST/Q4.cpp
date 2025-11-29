#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->left->left = new Node(3);
    root1->left->right = new Node(7);
    cout << "Tree1 is BST: " << (isBST(root1) ? "YES" : "NO") << "\n";
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(8);
    root2->left->left = new Node(3);
    root2->left->right = new Node(12);
    cout << "Tree2 is BST: " << (isBST(root2) ? "YES" : "NO") << "\n";
    return 0;
}
