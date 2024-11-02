#include <iostream>
#include <algorithm>

using namespace std;

void rabinkarp(string text, string text2, string patt) {
    int freq = 0;
    int prime = 101;
    int pattSize = patt.size();
    int textSize = text.size();
    int text2Size = text2.size();

    long long pattHash = 0;
    long long textHash = 0;
    long long text2Hash = 0;

    long long powerOfPrime = 1;

    for (int i = 0; i < pattSize - 1; i++) {
        powerOfPrime = (powerOfPrime * prime);
    }

    for (int i = 0; i < pattSize; i++) {
        pattHash = pattHash * prime + (patt[i] - 'a' + 1);
        textHash = textHash * prime + (text[i] - 'a' + 1);
        text2Hash = text2Hash * prime + (text2[i] - 'a' + 1);
    }

    for (int i = 0; i <= textSize - pattSize; i++) {
        if (pattHash == textHash && pattHash == text2Hash) {
            freq++;
        }

        if (i < textSize - pattSize && i < text2Size - pattSize) {
            textHash = (textHash - powerOfPrime * (text[i] - 'a' + 1)) * prime + (text[i + pattSize] - 'a' + 1);
            text2Hash = (text2Hash - powerOfPrime * (text2[i] - 'a' + 1)) * prime + (text2[i + pattSize] - 'a' + 1);
        }
    }
    cout << freq;
}

int main() {
    string s1, s2, parasiteWord; 
    cin >> s1 >> s2 >> parasiteWord;
    rabinkarp(s1, s2, parasiteWord);
}