#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node * prev;
    Node * next;

    // Constructor
    Node(int data) {
      this -> data = data;
      this -> prev = NULL;
      this -> next = NULL;
    }

    // Destructor
    ~Node() {
      int value = this -> data;
      if (next != NULL) {
        delete next;
        next = NULL;
      }
      cout << "Memory freed for node with data: " << value << endl;
    }
};

// Handle if head and tail both are NULL edge cases

// Print linked list
void print(Node * &head) {

  Node * temp = head;

  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;

}

// Get length of a linked list
int getLength(Node * &head) {

  Node * temp = head;

  int len = 0;
  while (temp != NULL) {
    temp = temp -> next;
    len++;
  }
  return len;

}

// Insert at head of list
void insertAtHead(Node * &head, int data) {

  Node * newNode = new Node(data);
  newNode -> next = head;
  head -> prev = newNode;
  head = newNode;

}

// Insert at tail of list
void insertAtTail(Node * &head, int data) {

  Node * temp = head;

  while (temp -> next != NULL) {
    temp = temp -> next;
  }

  Node * newNode = new Node(data);
  temp -> next = newNode;
  newNode -> prev = temp;

}

// Insert at any position in linked list
void insertAtPosition(Node * &head, int data, int position) {

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
  temp -> next -> prev = newNode;
  newNode -> prev = temp;

}

// Delete a node from linked list 
void deleteNode(Node * &head, int position) {

  Node * temp = head;
  // deleting from positionn 1
  if (position == 1) {
    temp -> next -> prev = NULL;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
    return;
  }

  Node * curr = head;
  Node * previ = NULL;

  for (int i = 1; i < position; i++) {
    previ = curr;
    curr = curr -> next;
  }

  curr -> prev = NULL;
  previ -> next = curr -> next;
  curr -> next -> prev = previ;
  curr -> next = NULL;
  delete curr;
}
int main() {   

  Node * node1 = new Node(10);
  Node * head = node1;
  print(head);

  // cout << "Length of linked list: " << getLength(head) << endl;

  insertAtHead(head, 12);
  print(head);
  insertAtHead(head, 14);
  print(head);
  insertAtHead(head, 16);
  print(head);
  // cout << "Length of linked list: " << getLength(head) << endl;

  insertAtTail(head, 20);
  print(head);
  insertAtTail(head, 22);
  print(head);
  insertAtTail(head, 24);
  print(head);

  insertAtPosition(head, 40, 3);
  print(head);
  insertAtPosition(head, 42, 5);
  print(head);
  insertAtPosition(head, 44, 10);

  print(head);
  deleteNode(head, 1);
  print(head);

  deleteNode(head, 2);
  print(head);

  return 0;
}