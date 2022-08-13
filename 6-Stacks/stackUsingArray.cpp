#include <iostream>
using namespace std;

class Stack {
  public:

  int * arr;
  int top;
  int size;

  // Constructor
  Stack(int size) {
    this -> size = size;
    arr = new int[size];
    top = -1;
  }

  // Empty function
  bool empty() {
    return top == -1;
  }
  // Top operation
  int peek() {
    if (top >= 0) {
    return arr[top];
    } else {
      cout << "Stack is empty!" << endl;
      return -1;
    }
  }
  // Push operation
  void push(int element) {
    if (size - top > 1) {
      top++;
      arr[top] = element;
    } else {
      cout << "Stack overflow!" << endl;
      return;
    }
  }
  // Pop operation
  void pop() {
    if (top >= 0) {
      top--;
    } else {
      cout << "Stack underflow!" << endl;
      return;
    }
  }
  // Destructor
  ~Stack() {
    delete [] arr;
  }
};

int main() {

  Stack st(5);
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  cout << "Top element: " << st.peek() << endl;
  st.pop();
  cout << "Top element: " << st.peek() << endl;
  cout << "Is stack empty: " << st.empty() << endl;
  st.push(50);
  cout << "Top element: " << st.peek() << endl;
  st.push(60);
  cout << "Top element: " << st.peek() << endl;
  st.push(70);
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  cout << "Top element: " << st.peek() << endl;

  return 0;
}