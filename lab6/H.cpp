#include <iostream>
#include <vector>
using namespace std;

char findBalancedChar(const vector<char>& letters, char target) {
    int n = letters.size();
    int low = 0, high = n - 1;

    
    if (target >= letters[high]) {
        return letters[0];
    }

        while (low < high) {
        int mid = low + (high - low) / 2;
        if (letters[mid] > target) {
            high = mid;  
        } else {
            low = mid + 1;         }
    }

    return letters[low];  
}

int main() {
    int n;
    cin >> n;  

    vector<char> letters(n);
    for (int i = 0; i < n; ++i) {
        cin >> letters[i];    }

    char target;
    cin >> target;  
        cout << findBalancedChar(letters, target) << endl;

    return 0;
}