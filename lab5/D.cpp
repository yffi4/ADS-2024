#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    vector<long long int> heap;

    long long int parent(long long int i) {
        return (i - 1) / 2;
    }

    long long int leftChild(long long int i) {
        return 2 * i + 1;
    }

    long long int rightChild(long long int i) {
        return 2 * i + 2;
    }

    void heapifyUp(long long int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(long long int index) {
        long long int minIndex = index;

        long long int left = leftChild(index);
        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }

        long long int right = rightChild(index);
        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }

        if (minIndex != index) {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

    void insert(long long int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    long long int extractMin() {
        if (heap.size() == 0) {
            throw out_of_range("heap is empty");
        }

        long long int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }

        return result;
    }

    bool isEmpty() {
        return heap.empty();
    }

    long long int size() {
        return heap.size();
    }

    int top() {
        if (heap.empty()) {
            throw out_of_range("heap is empty");
        }
        return heap[0];
    }
};

int main() {
    long long int n, m; cin >> n >> m;

    MinHeap heap;

    for (int i = 0; i < n; i++)
    {
        long long int value;
        cin >> value;
        heap.insert(value);
    }

    int numOfOper = 0;

    while (heap.size() >= 2 && heap.top() < m) {
        long long int first = heap.extractMin();
        long long int second = heap.extractMin();
        
        int d = first + 2 * second;
        heap.insert(d);
        numOfOper++;
    }

    if (heap.top() < m) {
        cout << "-1";
    } else {
        cout << numOfOper;
    }

    return 0;
}