#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int LIMIT = 100005;

    vector<bool> is_prime(LIMIT + 1, true);
    vector<int> primes;
    vector<int> superprimes;

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= LIMIT; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < primes.size(); ++i) {
        int index = i + 1; 
        if (is_prime[index]) {
            superprimes.push_back(primes[i]);
            if (superprimes.size() == n) {
                cout << superprimes[n - 1] << endl;
                return 0;
            }
        }
    }

    return 0;
}