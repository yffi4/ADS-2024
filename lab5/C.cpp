#include <iostream>
#include <vector>

using namespace std;

struct MaxHeap {
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
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(long long int index) {
        long long int maxIndex = index;

        long long int left = leftChild(index);
        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        long long int right = rightChild(index);
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (maxIndex != index) {
            swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    void insert(long long int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    long long int extractMax() {
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
};

int main() {
    long long int n, x; cin >> n >> x;

    MaxHeap heap;

    for (int i = 0; i < n; i++)
    {
        long long int value;
        cin >> value;
        heap.insert(value);
    }

    long long int totalRevenue = 0;

    for (int i = 0; i < x; i++)
    {
        int max = heap.extractMax();
        
        totalRevenue += max;

        max -= 1;

        if (max > 0) {
            heap.insert(max);
        }
    }

    cout << totalRevenue;

    return 0;
}