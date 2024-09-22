#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

bool isBalancedString(string str){
    stack<char> steck;
    for (int i = 0; i < str.size(); i++) {
        if (!steck.empty() && str[i] == steck.top()) {
            steck.pop();  
        } else {
            steck.push(str[i]);  
        }
    }
    
    return steck.empty();
    
    
}
int main() {
    string str;
    cin >> str;

    if (isBalancedString(str))
    {
        cout << "YES";
    }else{
        cout << "NO";
    }
    

    return 0;
}