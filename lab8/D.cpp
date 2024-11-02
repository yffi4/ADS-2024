#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int findFreq(string text, string patt){
    int freq = 0;
    int prime = 101;
    int pattSize = patt.size();
    int textSize = text.size();

    long long pattHash = 0;
    long long textHash = 0;

    for(int i = 0; i < pattSize; i++){
        pattHash += (long long)pow(prime, i) * patt[i];
        textHash += (long long)pow(prime, i) * text[i];
    }

    for(int i = 0; i <= textSize - pattSize; i++){
        if(pattHash == textHash){
            bool match = true;
            for(int j = 0; j < pattSize; j++){
                if(text[i+j] != patt[j]){
                    match = false;
                    break;
                }
            }

            if(match){
                freq++;
            }
        }

        if(i < textSize - pattSize){
            textHash = (textHash - text[i]) / prime + text[i + pattSize] * (long long)pow(prime, pattSize - 1);
        }
    }
    return freq;
}

pair<int, vector<string>> findMaxFreq(vector<string> a, string text){
    string maxString = "";
    int maxFreq = 0;
    vector<string> res;
    vector<pair<string, int>> freqs;

    for(int i = 0; i < a.size(); i++){
        string s = a[i];
        int freq = findFreq(text, s);
        freqs.push_back(make_pair(s, freq));

        if(maxFreq < freq){
            maxFreq = freq;
            
        }
    }

    for(auto i : freqs){
        if(i.second == maxFreq){
            res.push_back(i.first);
        }
    }

    return make_pair(maxFreq, res);
}

int main(){
    int n = 1;
    vector<string> a;
    while(n != 0){
        cin >> n;
        if(n == 0) break;
        for(int i = 0 ; i < n; i++){
            string patt;
            cin >> patt;

            a.push_back(patt);
        }
        string text;
        cin >> text;

        pair<int, vector<string>> res = findMaxFreq(a, text);
        cout << res.first << endl;
        for(auto i : res.second){
            cout << i << endl;
        }
        a.clear();

    }
}