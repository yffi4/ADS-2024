// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> createPrefixTable(const string &pattern){
//     int m = pattern.length();
//     vector<int> prefixTable(m, 0);
//     int j = 0;
//     for (int i = 1; i < m; i++)
//     {
//         while (j > 0 && pattern[i] != pattern[j])
//         {
//             j = prefixTable[j - 1];
//         }
//         if (pattern[i] == pattern[j])
//         {
//             j++;
//         }
//         prefixTable[i] = j;
        
//     }
//     return prefixTable;
    
// }

// int kmpSearch(const string &text, const string &pattern){
//     vector<int> prefixTable = createPrefixTable(pattern);
//     int n = text.length();
//     int m = pattern.length();
//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         while (j > 0 && text[i] != pattern[j])
//         {
//             j = prefixTable[j - 1];
//         }
//         if (text[i] == pattern[j])
//         {
//             j++;
//         }
//         if (j == m)
//         {
//             return i - m + 1;
//         }
        
        
//     }
//     return -1;
    
// }
// int main(){
//     string first, second;
//     cin >> first >> second;
//     if (first.length() != second.length())
//     {
//         cout << -1 << endl;
//         return 0;
//     }
    
//     string doubled = first + first;

//     int shift = kmpSearch(doubled, second);
//     if (shift != -1 && shift < first.length())
//     {
//         cout << shift << endl;
//     }else
//         cout << -1 << endl;
    
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string& text, string& patt){
    if(patt.size() == 0){
        return 0;
    }
    vector<int> lps(patt.size(), 0);

    //lps implementation
    int prevLPS = 0, i = 1;
    while(i < patt.size()){
        if(patt[i] == patt[prevLPS]){
            lps[i] = prevLPS + 1;
            prevLPS += 1;
            i += 1;
        }
        else if(prevLPS == 0){
            lps[i] = 0;
            i += 1;
        }
        else{
            prevLPS = lps[prevLPS - 1];
        }
    }

    int i1 = 0; // iterator for text
    int i2 = 0; // iterator for pattern

    while(i1 < text.size()){
        if(text[i1] == patt[i2]){
            i1++;
            i2++;
        }
        else{
            if(i2 == 0){
                i1 += 1;
            }
            else{
                i2 = lps[i2- 1];
            }
        }
        if(i2 == patt.size()){
            return i1 - patt.size();
        }
    }

    return -1;
}

int main(){
    string text, patt;
    cin >> text >> patt;
    
    patt += patt;

    cout << kmp(patt, text);
}