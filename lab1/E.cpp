#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> boris;
    queue<int> nursik;
    for (int i = 0; i < 5; i++)
    {
        int temp; cin >> temp;
        boris.push(temp);
    }
    
    for (int i = 0; i < 5; i++)
    {
        int temp; cin >> temp;
        nursik.push(temp);
    }
    
    int count = 0;

    while (!boris.empty() && !nursik.empty()) {
        int card1 = boris.front(); 
        int card2 = nursik.front();

        nursik.pop();
        boris.pop();

        if (card1 > card2) {
            if (card1 == 9 && card2 == 0) {
                nursik.push(card1); 
                nursik.push(card2);      
            } else {
                boris.push(card1); 
                boris.push(card2);  
            }
        } else {
            if (card2 == 9 && card1 == 0) {
                boris.push(card1); 
                boris.push(card2);      
            } else {
                nursik.push(card1); 
                nursik.push(card2);   
            }
        }

        count++;

        if (count > 1000000) {
            cout << "blin nichya" << endl;
            return 0;
        }
    }

    (!boris.empty()) ? cout << "Boris " << count : cout << "Nursik " << count;

    return 0;

}