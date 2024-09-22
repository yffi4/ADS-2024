#include <iostream>
using namespace std;
struct Node{
    string value;
    Node *next;
    Node(string val) : value(val), next(nullptr){}
};
struct LinkedList
{
    Node* head;
    Node* tail;
    
    LinkedList() : head(nullptr), tail(nullptr) {}
    
    void printList(){
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            
            count++;
            current = current->next;
        }
        cout << "All in all: " << count << endl;
        cout << "Students:" << endl;
        current = head;
        while (current != nullptr)
        {
            cout << current->value << endl;  
            current = current->next;
        }
        
    }

    void append(const string& name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode; 
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};
Node* removeElements(Node* head){
    Node* current = head;
    while (current && current->next){
            
        if (current->value == current->next->value)
        {
            Node* delElement = current->next;
            current->next = current->next->next;
            delete delElement;
        }else{
            current = current->next;
        }
            
    }
    return head;
}
Node* reverse(Node* head){
    if (head == nullptr || head->next == nullptr) return head;

    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur->next; 
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}
int main(){
    int n; cin >> n;
    LinkedList list;
    
    
    for (int i = 0; i < n; i++)
    {
        string name; cin >> name;
        list.append(name);
    
    }
    
    list.head = removeElements(list.head);
    list.head = reverse(list.head);
    list.printList();
    list.clearList();
    return 0;
    
}
