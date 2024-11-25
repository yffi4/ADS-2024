#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <iterator> 
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// vector<int> res;
// map<int, int> hashSet;

// struct Node{
//     int val;
//     int level;
// };

int minOperations(int a, int b, vector<int>& path){
    set<int> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(a);
    parent[a] = -1;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        if(temp == b){
            while(temp != -1){
                path.push_back(temp);
                temp = parent[temp];
            }
            reverse(path.begin(), path.end());
            return path.size() - 1;
            
        }

        // visited.insert(temp);
        


        // if(temp.val * 2 == b){
        //     return temp.level + 1;
        // }
        // if(temp.val - 1 == b){
        //     return temp.level + 1;
        // }

        if(temp - 1 >= 0 && parent.find(temp - 1) == parent.end()){
            
            q.push(temp-1);
            parent[temp-1] = temp;
        }

        if(parent.find(temp * 2) == parent.end() && temp * 2 <= 20000){
            q.push(temp*2);
            parent[temp*2] = temp;
        }
    }

    return 0;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<int> path;
    cout << minOperations(a, b, path);
    cout << endl;

    for(int i = 1; i < path.size(); i++){
        cout << path[i] << " ";
    }
    // cout << endl;

    // map<int, int>::iterator it;

    // int temp;
    // vector<int> seconds;
    // if(!hashSet.empty()){
    //     temp = hashSet.begin()->second;
    //     seconds.push_back(temp);
    // }


    // for(it = hashSet.begin(); it != hashSet.end(); it++){
    //     // if(it->first == temp){
    //     //     seconds.push_back(it->first);
    //     //     temp = it->second;
    //     // }

    //     cout << it->first << " " << it->second << endl;
    // }

    // for(int i = seconds.size() - 1; i >= 0; i--){
    //     cout << seconds[i] << " ";
    // }

    // for(int i = 0; i < seconds.size(); i++){
    //     cout << seconds[i] << " "; 
    // }
    // cout << 5061;
}