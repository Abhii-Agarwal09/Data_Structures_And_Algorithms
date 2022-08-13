#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node * next;

    // Constructor
    Node(int data) {
      this -> data = data;
      this -> next = NULL;
    }

    // Destructor
    ~Node() {
      int value = this -> data;
      if (this -> next != NULL) {
        delete next;
        this -> next = NULL;
      }
      cout << "Memory is free for node with data " << value << endl;
    }
};

// Print linked list
void print(Node * &tail) {
  Node * temp = tail;
  // cout << tail -> data << " " << endl;
  // while (tail -> next != temp) {
  //   cout << tail -> data << " " << endl;
  //   tail = tail -> next;
  // }
  do {
    cout << tail -> data << " ";
    tail = tail -> next;
  } while (tail != temp);
  cout << endl;
}

// Insert node 
void insertNode(Node * &tail, int element, int data) {
  if (tail == NULL) {
    Node * temp = new Node(data);
    tail = temp;
    temp -> next = temp;
    return;
  }
  Node * newNode = new Node(data);
  Node * curr = tail;
  while (curr -> data != element) {
    curr = curr -> next;
  }
  newNode -> next = curr -> next;
  curr -> next = newNode;
}

int main() {

  Node * tail = NULL;

  // print(tail);
  insertNode(tail, 5, 3);
  print(tail);
  insertNode(tail, 3, 5);
  insertNode(tail, 5, 7);
  print(tail);

  insertNode(tail, 5, 9);
  print(tail);

  return 0;
}