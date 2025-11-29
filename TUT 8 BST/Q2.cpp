#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchItr(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int maxElement(Node* root) {
    if (!root) throw runtime_error("Empty tree");
    while (root->right) root = root->right;
    return root->data;
}

int minElement(Node* root) {
    if (!root) throw runtime_error("Empty tree");
    while (root->left) root = root->left;
    return root->data;
}

Node* inorderSuccessor(Node* root, Node* n) {
    if (!root || !n) return NULL;
    if (n->right) {
        Node* t = n->right;
        while (t->left) t = t->left;
        return t;
    }
    Node* succ = NULL;
    while (root) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data) root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if (!root || !n) return NULL;
    if (n->left) {
        Node* t = n->left;
        while (t->right) t = t->right;
        return t;
    }
    Node* pred = NULL;
    while (root) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data) root = root->left;
        else break;
    }
    return pred;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals) root = insert(root, v);
    cout << "BST In-order: ";
    inorderPrint(root);
    cout << "\n";
    int keys[] = {50, 20, 80, 40};
    for (int k : keys) {
        Node* r = searchRec(root, k);
        cout << "searchRec " << k << ": " << (r ? "Found" : "Not Found") << "\n";
        r = searchItr(root, k);
        cout << "searchItr " << k << ": " << (r ? "Found" : "Not Found") << "\n";
    }
    cout << "Min element: " << minElement(root) << "\n";
    cout << "Max element: " << maxElement(root) << "\n";
    Node* node50 = searchRec(root, 50);
    Node* succ = inorderSuccessor(root, node50);
    Node* pred = inorderPredecessor(root, node50);
    cout << "Node 50 successor: " << (succ ? to_string(succ->data) : string("None")) << "\n";
    cout << "Node 50 predecessor: " << (pred ? to_string(pred->data) : string("None")) << "\n";
    Node* node20 = searchRec(root, 20);
    succ = inorderSuccessor(root, node20);
    pred = inorderPredecessor(root, node20);
    cout << "Node 20 successor: " << (succ ? to_string(succ->data) : string("None")) << "\n";
    cout << "Node 20 predecessor: " << (pred ? to_string(pred->data) : string("None")) << "\n";
    return 0;
}
