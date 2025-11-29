#include <iostream>
#include<vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        int p = (i - 1) / 2;
        if (i && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.size() == 0) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.size() == 0;
    }

    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
