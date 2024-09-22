#include <iostream>
using namespace std;

struct Node
{
    string value;
    Node *next;
    Node(string val) : value(val), next(nullptr){}

};

Node* createList(int n){
    string word;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        Node* newNode = new Node(word);
        if (head==nullptr)
        {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

        
    }
    return head;
    
}

void printList(Node* head){

    Node* current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

}

Node* cyclic(Node* head, int k, int n){
    if (n == 0 || k == 0 || k % n == 0) {
        return head;  
    }
    Node* tail = head;
    int count = 0;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        
    }
    tail->next = head;

    k = k % n;
    
    Node* newTail = head;
    for (int i = 0; i < k - 1; i++) {
        newTail = newTail->next;
    }

    
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
    
}
int main(){
    int n, k; cin >> n >> k;
    Node* head = createList(n);
    head = cyclic(head, k, n);
    printList(head);

    
     
}
