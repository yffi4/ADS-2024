#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;


int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;        

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n;
    cin >> n;  

    vector<int> points(n);
    
    
    for (int i = 0; i < n; ++i)
        cin >> points[i];


    quickSort(points, 0, n - 1);

    int minDiff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        int diff = abs(points[i] - points[i - 1]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (abs(points[i] - points[i - 1]) == minDiff) {
            cout << points[i - 1] << " " << points[i] << " ";
        }
    }

    return 0;
}
