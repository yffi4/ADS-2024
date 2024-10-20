#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& column, int low, int high) {
    int pivot = column[high];  
    int i = low - 1;          

    for (int j = low; j <= high - 1; ++j) {
        if (column[j] > pivot) {  
            i++;
            swap(column[i], column[j]);
        }
    }
    swap(column[i + 1], column[high]);
    return i + 1;
}


void quickSort(vector<int>& column, int low, int high) {
    if (low < high) {
        int pi = partition(column, low, high);  
        quickSort(column, low, pi - 1);  
        quickSort(column, pi + 1, high);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    for (int col = 0; col < m; ++col) {
        vector<int> column(n);
        for (int row = 0; row < n; ++row) {
            column[row] = matrix[row][col];
        }
        
        quickSort(column, 0, n - 1);
        
        for (int row = 0; row < n; ++row) {
            matrix[row][col] = column[row];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
