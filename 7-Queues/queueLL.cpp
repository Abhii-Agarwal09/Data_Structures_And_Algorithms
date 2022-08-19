#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node * next;
  Node(int data) {
    this -> data = data;
    next = NULL;
  }
  // Destructor
  // ~Node() {
  //   int value = this -> data;
  //   if (this -> next != NULL) {
  //     delete next;
  //     this -> next = NULL;
  //   }
  //   cout << "Memory is free for node with data " << value << endl;
  // }
};

class Queue {
  int size;
  Node * front;
  Node * back;
  public:

  Queue() {
    front = NULL;
    back = NULL;
  }

  void enqueue(int data) {
    /*
    if (front == NULL && back == NULL) {
      Node * newNode = new Node(data);
      front = newNode;
      back = newNode;
      size++;
    }
    else {
      Node * newNode = new Node(data);
      newNode -> next = back;
      back = newNode;
    }
    */
    if (front == NULL && back == NULL){
      Node * newNode = new Node(data);
      front = newNode;
      back = newNode;
      size++;
    }
    else {
      Node * newNode = new Node(data);
      back -> next = newNode;
      back = newNode;
      size++;
    }
  }

  int dequeue() {
    if (front == NULL && back == NULL) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    else {
      Node * temp = front;
      int val = front -> data;
      front = front -> next;
      if (front == NULL) {
        back = NULL;
      }
      delete temp;
      return val;
    }
  }

  int getFront() {
    return front -> data;
  }
  int getBack() {
    return back -> data;
  }
  bool isEmpty() {
    return front == NULL && back == NULL;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.enqueue(2);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.enqueue(3);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.enqueue(4);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.dequeue();
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.dequeue();
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.dequeue();
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  q.dequeue();
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  return 0;
}