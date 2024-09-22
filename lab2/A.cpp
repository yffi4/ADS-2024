#include <iostream>
#include <limits>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr){}

    
};

int main(){
    int n, target;
    cin >> n;

    int firstValue;
    cin >> firstValue;
    Node* head = new Node(firstValue);
    Node* current = head;
    for (int i = 1; i < n; i++)
    {
        int value; cin>>value;
        current->next = new Node(value);
        current = current->next;
    }
    
    cin >> target;
    int minDiference = numeric_limits<int>::max();
    int closestIndex = 0;
    int currentIndex = 0;

    current = head;

    while (current != nullptr)
    {
        int diference = abs(current->value - target);

        if (diference < minDiference)
        {
            minDiference = diference;
            closestIndex = currentIndex;
        }
        
        current = current->next;
        currentIndex++;
    }
    cout << closestIndex;

    current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}