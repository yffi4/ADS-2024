#include <iostream>
#include <string>
using namespace std;

string elementsOfString(const string& s) {
    string result;
    for (char c : s) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back(); 
            }
        } else {
            result.push_back(c);  
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = elementsOfString(s1);
    string s4 = elementsOfString(s2);

    if (s3 == s4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
