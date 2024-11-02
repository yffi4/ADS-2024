#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

long long mod = 1e9 + 7;
long long p = 11;

string hash1(string s) {
    long long h = 0;
    for (long long i = s.size() - 1; i >= 0; i--) {
        h = (h * p % mod + (s[i] - 47)) % mod;
    }
    return to_string(h);
}
void print(string key, string hash){
    cout<< "Hash of string \"" + key + "\" is " + hash << endl;
}
int main(){
    long long int n;
    cin>>n;
    vector<string> v;
    unordered_set<string> hashSet;
    pair<string,string> p[2*n];
    string s;
    for(long long int i=0; i<2*n;i++){     
        cin>>s;
        hashSet.insert(s);
        p[i].first = s;
        p[i].second = hash1(s);

    }
    int k = 0;
    for (long long int i = 0; i < 2 * n; i++) {
        unordered_set <string> :: iterator it = hashSet.find(p[i].second);
        if (it != hashSet.end()) {
            // hashSet.erase(it);
            // v.erase(strIt);
            print(p[i].first, p[i].second);
            k++;
            if (k == n)
                break;
        }
    }
}
 
