#include <iostream>
#include <vector>
using namespace std;

vector<int> createPrefixTable(const string &pattern) {
    int m = pattern.length();
    vector<int> prefixTable(m, 0);
    int j = 0; 
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefixTable[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefixTable[i] = j;
    }
    return prefixTable;
}


bool kmpSearch(const string &text, const string &pattern) {
    vector<int> prefixTable = createPrefixTable(pattern);
    int n = text.length();
    int m = pattern.length();
    int j = 0; 
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixTable[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return true;
        }
    }
    return false;
}


int minRepeats(string A, string B) {
    string repeatedA = A;
    int count = 1;
    
    
    while (repeatedA.length() < B.length()) {
        repeatedA += A;
        count++;
    }

    
    if (kmpSearch(repeatedA, B)) {
        return count;
    }
    
    
    repeatedA += A;
    count++;
    if (kmpSearch(repeatedA, B)) {
        return count;
    }
    
    return -1; 
}

int main() {
    string A, B;
    cin >> A >> B;
    cout << minRepeats(A, B) << endl;
    return 0;
}
