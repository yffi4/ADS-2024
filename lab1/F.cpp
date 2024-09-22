#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n) {
  
    
    if (n <= 1) {
        return false;
    }

   
    for (int i = 2; i < n; i++) {
      
       
        if (n % i == 0) {
            return false;
        }
    }

    
    return true;
}
int main(){
    int n; cin >> n;
    int counterOfPrimes = 0;
    int counter = 0;
    vector<int> superPrimes;
    while (counterOfPrimes != n)
    {
        if (isPrime(counter))
        {
            counterOfPrimes++;
            superPrimes.push_back

        }
        counter++;
        // if (counterOfPrimes == n)
        // {
        //    cout << counter - 1;
        // } 
        
        
    }
    return 0;
}