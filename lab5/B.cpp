#include <iostream>
using namespace std;
class MaxHeap
{
private:
    int* heapArray;
    int capacity;
    int heapSize;
public:
    MaxHeap(int capacity){
        this->capacity = capacity;
        heapArray = 0;
        heapSize = 0;
    }
    int parent(int i)  {return (i - 1) / 2;}
    int left(int i) {return i * 2 + 1;}
    int right(int i) {return i * 2 + 2;}

    void insertKey(int key){
        if (heapSize == capacity){
            return;
        }

        heapSize++;
        int i = heapSize - 1;
        heapArray[i] = key;
        
        while (i != 0 && heapArray[parent(i)] < heapArray[i])
        {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
        
    }

    int exctractMax(){
        if (heapSize <= 0){
            return 0;
        }
        if (heapSize == 1)
        {
            heapSize--;
            return heapArray[0];
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        
        heapify(0);
        return root;
    }

    void heapify(int i){
        int largest = i;
        int l = left(i);
        int r = right(i);

        if(l < heapSize && heapArray[l] > heapArray[largest]){
            largest = l;

        }
        if (r < heapSize && heapArray[r] > heapArray[largest])
            largest = r;
        
        
        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            
            
            heapify(largest);
        }

    }


};

int main() {
    int n;
    cin >> n;
    
    MaxHeap heap(n);
    
    
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        heap.insertKey(weight);  
    }
    
    
    while (n > 1) {
    
        int first = heap.exctractMax();
        int second = heap.exctractMax();
        
        
        if (first != second) {
            heap.insertKey(first - second);
        }
        n--;
    }
    
    
    int result = heap.exctractMax();
    cout << result << endl;
    
    return 0;
}

