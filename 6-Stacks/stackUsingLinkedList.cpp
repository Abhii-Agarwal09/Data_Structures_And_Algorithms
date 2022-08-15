#include <iostream>
using namespace std;

class Node{
  public:

  int data;
  Node * next;

  // Constructor
  Node(int data) {
    this -> data = data;
    next = NULL;
  }
};

class Stack{
  private:
  Node * top;
  public:
  int size;

  Stack() {
    top = NULL;
    size = 0;
  }

  int getSize() {
    return size;
  }

  bool isEmpty() {
    return size == 0;
  }

  void push(int data) {
    if (top == NULL) {
      Node * newNode = new Node(data);
      top = newNode;
      size++;
      return;
    }
    Node * newNode = new Node(data);
    newNode -> next = top;
    top = newNode;
    size++;
  }

  int pop() {
    int data = top -> data;
    Node * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return data;
  }

  void print() {
    Node * temp = top;
    while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
};

int main() {
  Stack s;
  cout << "Size of stack: " << s.getSize() << endl;
  s.push(10);
  cout << "Size of stack: " << s.getSize() << endl;
  s.push(20);
  cout << "Size of stack: " << s.getSize() << endl;
  s.push(30);
  cout << "Size of stack: " << s.getSize() << endl;
  s.print();
  cout << "Is stack empty? " << s.isEmpty() << endl;
  cout << "Element popped out: " << s.pop() << endl;
  s.print();
}