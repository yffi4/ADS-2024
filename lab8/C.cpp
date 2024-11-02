#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void rabinkarp(string text, string patt, vector<bool>& a) {
    int freq = 0;
    int prime = 101;
    int pattSize = patt.size();
    int textSize = text.size();

    long long pattHash = 0;
    long long textHash = 0;

    long long powerOfPrime = 1;

    for (int i = 0; i < pattSize - 1; i++) {
        powerOfPrime = (powerOfPrime * prime);
    }

    for (int i = 0; i < pattSize; i++) {
        pattHash = pattHash * prime + (patt[i] - 'a' + 1);
        textHash = textHash * prime + (text[i] - 'a' + 1);
    }

    for (int i = 0; i <= textSize - pattSize; i++) {
        if (pattHash == textHash) {
            for(int j = i; j < pattSize + i; j++){
                a[j] = true;
            }
        }

        if (i < textSize - pattSize) {
            textHash = (textHash - powerOfPrime * (text[i] - 'a' + 1)) * prime + (text[i + pattSize] - 'a' + 1);
        }
    }
}

int main(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<bool> a(s.size(), false);

    vector<string> tapes(n);

    for(int i = 0; i < n; i++){
        cin >> tapes[i];
    }

    for(int i = 0; i < n; i++){
        rabinkarp(s, tapes[i], a);
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] == false){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}