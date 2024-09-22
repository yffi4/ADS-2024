#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void findFirstNonRepeating(int n, string stream) {
    vector<int> count(26, 0);
    
    queue<char> q;
    
    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        
        count[ch - 'a']++;
        
        q.push(ch);
        
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;  
    
    while (T--) {
        int N;
        cin >> N;  
        string stream;
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ch;
            stream.push_back(ch);
        }
        
        findFirstNonRepeating(N, stream);
    }
    
    return 0;
}