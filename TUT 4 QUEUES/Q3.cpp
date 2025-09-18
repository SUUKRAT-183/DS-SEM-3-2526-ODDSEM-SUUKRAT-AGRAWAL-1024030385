#include <iostream>
using namespace std;

class Queue {
    int items[6];   
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == 5;  
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        items[rear] = value;
    }

void interleave() {
    if (rear - front + 1 != 6) {
        cout << "Interleave only works for exactly 6 elements." << endl;
        return;
    }

    int half[3];

    for (int i = 0; i < 3; i++) {
        half[i] = items[front + i];
    }

    int secondHalfIndex = front + 3;
    int halfIndex = 0;
    int index = front;

    while (halfIndex < 3 && secondHalfIndex <= rear) {
        items[index++] = half[halfIndex++];
        items[index++] = items[secondHalfIndex++];
    }

    rear = index - 1; 
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
};

int main() {
    Queue q;

    cout << "Enter 6 elements for the queue:" << endl;
    for(int i = 0; i < 6; i++) {
        int val;
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original ";
    q.display();

    q.interleave();

    cout << "After interleaving ";
    q.display();

    return 0;
}
