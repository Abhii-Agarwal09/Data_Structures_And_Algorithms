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

// Delete a node in linked list
void deleteNode(Node * &head, int position) {
  
  // Deleting first node
  if (position == 1) {
    Node * temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
    return;
  }

  Node * curr = head;
  Node * prev = NULL;
  for (int i = 1; i < position; i++) {
    prev = curr;
    curr = curr -> next;
  }
  prev -> next = curr -> next;
  curr -> next = NULL;
  delete curr;

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

// Reverse Linked list approach 1
void reverseLinkedList(Node * &head) {
  if (head == NULL || head -> next == NULL) {
    return;
  }
  Node * curr = head;
  Node * prev = NULL;
  Node * forward = NULL;

  while (curr != NULL) {
    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward; 
  }
  head = prev;
}

// Reverse linked list approach 2 (recursive 1)
void reverseLinkedListRecursiveOne(Node * &head, Node * curr, Node * prev) {

  if (curr == NULL) {
    head = prev;
    return;
  }
  Node * forward = curr -> next;
  reverseLinkedListRecursiveOne(head, forward, curr);
  curr -> next = prev;

}

// Reverse linked list recursive 2
Node * reverseLinkedListRecursiveTwo(Node * head) {
  if (head == NULL || head -> next == NULL) {
    return head;
  }
  Node * newHead = reverseLinkedListRecursiveTwo(head -> next);
  head -> next -> next = head;
  head -> next = NULL;
  return newHead;
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

  // deleteNode(head, 3);
  // reverseLinkedList(head);
  // Node * curr = head;
  // Node * prev = NULL;
  // reverseLinkedListRecursiveOne(head, curr, prev);

  Node * newHead = reverseLinkedListRecursiveTwo(head);

  print(newHead);

  return 0;
}