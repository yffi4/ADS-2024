#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

Node* insertToPosition(Node* head, int position, int data){
    Node* newNode = new Node(data);
    if (position == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
void printList(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }

}
int main(){
    int n; cin >> n;
    int firstValue; cin >> firstValue;
    Node* head = new Node(firstValue);
    Node* current = head;
    for (int i = 1; i < n; i++){
        int value; cin >> value;
        current->next = new Node(value);
        current = current->next;
    }
    int insertionValue; cin >> insertionValue;
    int position; cin >> position;
    head = insertToPosition(head, position, insertionValue);
    printList(head);
    return 0;
}