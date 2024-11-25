#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// void checkCanWalk(int x, int y, vector<vector<int>>& a, bool& isChanged, int& mushrooms) {
//     if(x == 0 || y == 0){
//         if(x + 1 < a.size() && a[x+1][y] == 1){
//             a[x+1][y] = 2;
//             isChanged = true;
//             mushrooms--;
//         }
//         if(y + 1 < a[0].size() && a[x][y+1] == 1){
//             a[x][y+1] = 2;
//             isChanged = true;
//             mushrooms--;
//         }
//     }
    
//     // cout << " checked x - 1 != 0" << endl;
    
//     if(x - 1 >= 0 && a[x-1][y] == 1){
//         a[x-1][y] = 2;
//         isChanged = true;
//         mushrooms--;
//         // cout << "x-1" << endl;
//     }
//     if(x + 1 < a.size() && a[x+1][y] == 1){
//         a[x+1][y] = 2;
//         isChanged = true;
//         mushrooms--;
//         // cout << "x+1" << endl;
//     }
//     if(y - 1 >= 0 && a[x][y-1] == 1){
//         // cout << "check y - 1" << endl;
//         a[x][y-1] = 2;
//         isChanged = true;
//         mushrooms--;
//         // cout << "y-1" << endl;
//     }
//     if(y + 1 < a[0].size() && a[x][y+1] == 1){
//         // cout << "check y + 1" << endl;
//         a[x][y+1] = 2;
//         isChanged = true;
//         mushrooms--;
//         // cout << "y+1" << endl;
//     }
// }

void bfs(queue<pair<int, int>> q, int marios, int mushrooms, vector<vector<int>> a, int n, int m){
    vector<vector<int>> visited(n, vector<int> (m, 0));

    visited[q.front().first][q.front().second] = 1;
    int cnt = 0;
    while(!q.empty()){
        int tempMarios = 0;
        bool isChanged = false;

        while(marios != 0){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x - 1 >= 0 && a[x-1][y] == 1 && visited[x-1][y] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x-1][y] = 1;
                q.push(make_pair(x-1, y));
            }
            if(x + 1 < a.size() && a[x+1][y] == 1 && visited[x+1][y] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x+1][y] = 1;
                q.push(make_pair(x+1, y));
            }
            if(y - 1 >= 0 && a[x][y-1] == 1 && visited[x][y-1] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x][y-1] = 1;
                q.push(make_pair(x, y-1));
            }
            if(y + 1 < m && a[x][y+1] == 1 && visited[x][y+1] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x][y+1] = 1;
                q.push(make_pair(x, y+1));
            }
            marios--;

        }
        if(isChanged == true){
            cnt++;
        }
        marios = tempMarios;
        // marios--;
    }
    if(mushrooms == 0) cout << cnt;
    else cout << -1;
}

// void print(vector<vector<int>> a){
//     for(int i = 0; i < a.size(); i++){
//         for(int j = 0; j < a[0].size(); j++){
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << endl;
// }

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a; 
    map<pair<int, int>, int> visited;
    queue<pair<int, int>> q;
    

    // int mario_i, mario_j;
    int mushrooms = 0, marios = 0;

    for (int i = 0; i < n; i++) {
        vector<int> tempRow;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            tempRow.push_back(temp);
            if(temp == 1){
                mushrooms++;
            }
            if(temp == 2){
                marios++;
                q.push(make_pair(i, j));
            }
        }
        a.push_back(tempRow);
    }

    if(mushrooms == 0){
        cout << 0;
        return 0;
    } 

    // bfs();
    bfs(q, marios, mushrooms, a, n, m);

    return 0;
}