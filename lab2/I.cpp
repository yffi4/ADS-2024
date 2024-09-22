#include <iostream>

using namespace std;

struct Node {
  Node *prev;
  Node *next;
  string val;
  Node(string _val) {
    prev = NULL;
    next = NULL;
    val = _val;
  }
};

Node *head = NULL;
Node *tail = NULL;
int cnt;

void add_back(string s) {
  Node *n = new Node(s);
  cnt++;
  if (tail == NULL) {
    head = tail = n;
  } else {
    tail->next = n;
    n->prev = tail;
    tail = n;
  }
}

void add_front(string s) {
  Node *n = new Node(s);
  cnt++;
  if (head == NULL) {
    head = tail = n;
  } else {
    n->next = head;
    head->prev = n;
    head = n;
  }
}

bool empty() { 
  return head == NULL; 
}

void pop_front() {
  if(head != NULL) {
    if(head == tail) {
      delete head;
      head = tail = NULL;
    } else {
      head = head -> next;
      head -> prev = NULL;
    }
    cnt--;
  }
}

void pop_back() {
  if(tail != NULL) {
    if(head == tail) {
      delete tail;
      head = tail = NULL;
    } else {
      tail = tail -> prev;
      tail -> next = NULL;
    }
    cnt--;
  }
}

string front() { return head->val; }

string back() { return tail->val; }

void clear() {
  Node * cur = head -> next;
  while (cur != NULL) {
    Node * temp = cur -> next;
    delete cur;
    cur = temp;
  }
  head = tail = NULL;
}

int main() {
  string s;
  while (cin >> s) {
    if (s == "add_front") {
      string t;
      cin >> t;
      add_front(t);
      cout << "ok" << endl;
    }
    if (s == "add_back") {
      string t;
      cin >> t;
      add_back(t);
      cout << "ok" << endl;
    }
    if (s == "erase_front") {
      if (empty()) {
        cout << "error" << endl;
      } else {
        cout << front() << endl;
        pop_front();
      }
    }
    if (s == "erase_back") {
      if (empty()) {
        cout << "error" << endl;
      } else {
        cout << back() << endl;
        pop_back();
      }
    }
    if (s == "front") {
      if (empty()) {
        cout << "error" << endl;
      } else {
        cout << front() << endl;
      }
    }
    if (s == "back") {
      if (empty()) {
        cout << "error" << endl;
      } else {
        cout << back() << endl;
      }
    }
    if (s == "clear") {
      if(!empty()) clear();
      cout << "ok" << endl;
    }
    if (s == "exit") {
      cout << "goodbye" << endl;
      break;
    }
  }
  return 0;
}