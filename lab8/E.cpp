#include <iostream>
#include <vector>

using namespace std;

long long powerOfTwo(long long power){
    if (power == 0) return 1;
    long long res = 1;
    for (int i = 0; i < power; i++) {
        res *= 2;
    }
    return res;
}

char fromHashToString(long long n, int i){
    char c = char((n / powerOfTwo(i)) + 97);
    return c;
}

int main(){
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    string res = "";
    // res += fromHashToString(7, 0);
    // cout << res;
    long long preSum = 0;

    for(int i = 0; i < n; i++){
        res += fromHashToString(a[i] - preSum, i);
        preSum = a[i];
    }

    cout << res;
}