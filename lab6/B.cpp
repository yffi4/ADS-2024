#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}


void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


vector<int> findCommon(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    vector<int> common;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            common.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return common;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m);

    
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];

    
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];

    
    if (n > 0) mergeSort(arr1, 0, n - 1);
    if (m > 0) mergeSort(arr2, 0, m - 1);

    
    vector<int> common = findCommon(arr1, arr2);

   
    for (int num : common) {
        cout << num << " ";
    }

    return 0;
}
