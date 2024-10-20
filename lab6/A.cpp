#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}


void merge(vector<char> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> L(n1), R(n2);

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

// Merge Sort function
void mergeSort(vector<char> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;  
    string s;
    cin >> s;  

    vector<char> vowels, consonants;

    
    for (char ch : s) {
        if (isVowel(ch))
            vowels.push_back(ch);
        else
            consonants.push_back(ch);
    }

    
    mergeSort(vowels, 0, vowels.size() - 1);
    mergeSort(consonants, 0, consonants.size() - 1);

    
    for (char v : vowels) cout << v;
    for (char c : consonants) cout << c;

    return 0;
}
