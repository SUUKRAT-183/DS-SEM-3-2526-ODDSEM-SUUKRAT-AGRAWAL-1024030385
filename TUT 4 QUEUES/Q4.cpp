#include <iostream>
using namespace std;

class Queue {
    char items[100]; 
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == 99;  
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(char element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        items[rear] = element;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return '\0';
        }
        char element = items[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    char peek() {
        if (!isEmpty())
            return items[front];
        return '\0';
    }
};

int main() {
    Queue Q;
    int n;
    cout << "Enter size of queue: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;

    int count[256] = {0}; 
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        Q.enqueue(ch);
        count[(int)ch]++;
    }

    bool found = false;
    while (!Q.isEmpty()) {
        char ch = Q.dequeue();
        if (count[(int)ch] == 1) {
            cout << "First non-repeating element is: " << ch << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No non-repeating elements" << endl;
    }

    return 0;
}
