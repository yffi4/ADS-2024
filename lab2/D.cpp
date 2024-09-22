#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    map<int, int> dict;
    for (int  i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        if (dict.find(temp) == dict.end())
        {
            dict[temp] = 1;
        }else{
            dict[temp]++;
        }
        
    }
    pair<int, int> maxValue;
    int max = INT_MIN;
    for (const auto &entry  : dict)
    {
        if (max < entry.second)
        {
            max = entry.second;
            
        }
        
        
    }
    vector<int> modes;
    for (const auto &entry : dict)
    {
        if (entry.second == max)
        {
            modes.push_back(entry.first);
        }
        
        
    }
    reverse(modes.begin(), modes.end());
    for (int mode : modes)
    {
        cout << mode << " ";
    }
    
    
    
    return 0;
    
}