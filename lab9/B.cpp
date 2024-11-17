#include <iostream>
#include <vector>
using namespace std;

vector<int> createPrefixTable(const string &pattern){
    int m = pattern.length();
    vector<int> prefixTable(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while(j > 0 && pattern[i] != pattern[j]){
            j = prefixTable[j - 1];

        }
        if (pattern[i] == pattern[j])
        {
            j++;

        }
        prefixTable[i] = j;
        
    }
    return prefixTable;
    
}

int kmpSearch(const string &text, const string &pattern){
    vector<int> prefixTable = createPrefixTable(pattern);
    int n = text.length();
    int m = pattern.length();
    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while(j > 0 && text[i] != pattern[j]){
            j = prefixTable[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            count++;
            j = prefixTable[j - 1];
        }
        
        
    }
    return count;
}

int main(){
    string s = "";
    int n;
    cin >> s >> n;
    string t;
    cin >> t;
    int occurrences = kmpSearch(t, s);
    if (occurrences >= n)
    {
        cout << "YES";
    }else
        cout << "NO";

    return 0;
    
}