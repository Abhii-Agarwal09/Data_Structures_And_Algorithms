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
};

// Insert at head of list
void insertAtHead(Node * &head, int data) {

  Node * temp = new Node(data);
  temp -> next = head;
  head = temp;

}

// Insert at tail of list
void insertAtTail(Node * &head, int data) {

  Node * newNode = new Node(data);
  Node * temp = head;

  while (temp -> next != NULL) {
    temp = temp -> next;
  }

  temp -> next = newNode;

}

// Insert at specific position in list
void insertAtPosition(Node * &head, int data, int position) {

  // insert at head edge case
  if (position == 1) {
    insertAtHead(head, data);
    return;
  }

  Node * newNode = new Node(data);
  Node * temp = head;

  for (int i = 1; i < position - 1; i++) {
    temp = temp -> next;
  }

  newNode -> next = temp -> next;
  temp -> next = newNode;

}

// Print linked list
void print(Node * &head) {

  Node * temp = head;

  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;

}

int main() {
  
  Node * node1 = new Node(10);
  // cout << node1 -> data << endl;
  // cout << node1 -> next << endl; 

  Node * head = node1;
  insertAtHead(head, 12);
  insertAtHead(head, 14);
  insertAtHead(head, 16);

  insertAtTail(head, 23);
  insertAtTail(head, 25);
  insertAtTail(head, 27);

  insertAtPosition(head, 45, 3);
  insertAtPosition(head, 47, 9);

  print(head);

  return 0;
}