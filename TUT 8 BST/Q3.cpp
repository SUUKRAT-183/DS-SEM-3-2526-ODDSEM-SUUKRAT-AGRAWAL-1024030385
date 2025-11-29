#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* searchNode(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;
    while (true) {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Min Element\n7. Max Element\n8. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            root = insertNode(root, val);
        }
        else if (choice == 2) {
            preorder(root);
            cout << "\n";
        }
        else if (choice == 3) {
            inorder(root);
            cout << "\n";
        }
        else if (choice == 4) {
            postorder(root);
            cout << "\n";
        }
        else if (choice == 5) {
            cout << "Enter value to search: ";
            cin >> val;
            if (searchNode(root, val)) cout << "Found\n";
            else cout << "Not Found\n";
        }
        else if (choice == 6) {
            Node* m = minNode(root);
            if (m) cout << "Min: " << m->data << "\n";
            else cout << "Tree empty\n";
        }
        else if (choice == 7) {
            Node* m = maxNode(root);
            if (m) cout << "Max: " << m->data << "\n";
            else cout << "Tree empty\n";
        }
        else if (choice == 8) break;
        else cout << "Invalid\n";
    }
    return 0;
}
