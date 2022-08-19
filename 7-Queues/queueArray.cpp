#include <iostream>
using namespace std;

class Queue{
  int * arr;
  int front;
  int back;
  int size;
  public: 
  Queue(int size) {
    this -> size = size;
    arr = new int[size];
    front = 0;
    back = 0;
  }
  void enqueue(int element) {
    if (back == size) {
      cout << "Queue is full!" << endl;
      return;
    }
    else {
      arr[back] = element;
      back++;
    }
  }
  int dequeue() {
    if (front == back) {
      cout << "Queue is empty!" << endl;
      return -1;
    }
    else {
      int val = arr[front];
      arr[front] = -1;
      front++;
      if (front == back) {
        front = 0;
        back = 0;
      }
      return val;
    }
  }
  int getFront() {
    return arr[front];
  }
  int getBack() {
    return arr[back - 1];
  }
  bool isEmpty() {
    return front == back;
  }
};

int main() {
  Queue q(5);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  cout << "Is queue empty?" << q.isEmpty() << endl;

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
  q.enqueue(5);
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  cout << "Is queue empty?" << q.isEmpty() << endl;

  q.enqueue(6);
  cout << "Element popped: " << q.dequeue() << endl;
  cout << "Element popped: " << q.dequeue() << endl;
  cout << "Front: " << q.getFront() << endl;
  cout << "Back: " << q.getBack() << endl;
  cout << "Is queue empty?" << q.isEmpty() << endl;

  return 0;
}