#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countAndDelete(int key) {
        int count = 0;

        // Case 1: Delete key nodes at the beginning (head)
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        // Case 2: Delete key nodes in the rest of the list
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->data == key) {
                count++;
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int n, value, key;

    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }

    cout << "Original List: ";
    list.display();

    cout << "Enter the key to count and delete: ";
    cin >> key;

    int count = list.countAndDelete(key);

    cout << "Occurrences of " << key << ": " << count << endl;
    cout << "List after deleting all " << key << ": ";
    list.display();

    return 0;
}
