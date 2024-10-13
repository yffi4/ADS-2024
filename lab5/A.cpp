#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long minCost(vector<long long> arr, int n){
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++){
        minHeap.push(arr[i]);
    }
    long long totalCost = 0;

    while(minHeap.size() > 1){
        long long first = minHeap.top(); minHeap.pop(); 
        long long second = minHeap.top(); minHeap.pop();

        long long cost = first + second;
        totalCost += cost;

        minHeap.push(cost);
    }
    return totalCost;
}
int main(){
    int n; cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long result = minCost(arr, n);
    cout << result;
    

}