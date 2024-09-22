#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr){}
};

void printList(Node* head) {
    Node* current = head;  
    while (current != nullptr) {  
        cout << current->value << " ";  
        current = current->next;  
    }
    cout << endl;  
}
int main(){
    int n; cin >> n;
    int firstValue; cin >> firstValue;
    Node* head = new Node(firstValue);
    Node* current = head;
    Node* prev = nullptr;
    for (int i = 1; i < n; i++)
    {
        int value; cin >> value;
        current->next = new Node(value);
        current = current->next;
    }

    int currentIndex = 1;
    current = head;
    while (current != nullptr)
    {
        if (currentIndex % 2 == 0)
        {
            Node* delElemet = current;
            prev->next = current->next;
            current = current->next;
            delete delElemet;
        }else{
            prev = current;
            current = current->next;
        }
        
        currentIndex++;
        
    }
    printList(head);
    return 0;
}