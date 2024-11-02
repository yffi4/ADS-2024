#include <iostream>
#include <string> 
#include <vector> 
#include <limits.h>
#include <set>
#include <unordered_set>

using namespace std;

void rabinkarp2(string s){
    long long prime = 31;
    long long mod = 1000000000000000007;

    long long n = s.size();

    unordered_set<long long> hashSet;

    for(long long i = 0; i < n; i++){
        long long hash = 0;
        for(long long j = i; j < n; j++){
            hash = (hash * prime + (s[j] - 'a' + 1)) % mod;
            if(hashSet.find(hash) == hashSet.end()){
                hashSet.insert(hash);
            }
        }
    }
    cout << hashSet.size();
}

int main(){
    
    string s;
    cin >> s;
    rabinkarp2(s);


}