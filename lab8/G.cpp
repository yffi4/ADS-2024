#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void findFreq(string text, string patt) {
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
            freq++;
        }

        if (i < textSize - pattSize) {
            textHash = (textHash - powerOfPrime * (text[i] - 'a' + 1)) * prime + (text[i + pattSize] - 'a' + 1);
        }
    }
    cout << freq;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        string patt = s.substr(l - 1, r - l + 1);
        findFreq(s, patt);
        cout << endl;
    }

    return 0;
}
