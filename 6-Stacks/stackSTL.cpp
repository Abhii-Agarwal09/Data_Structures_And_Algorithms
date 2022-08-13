#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s;
  s.push(2);
  s.push(4);
  s.push(6);
  s.push(8);
  cout << "Top element: " << s.top() << endl;
  s.pop();
  cout << "Top element: " << s.top() << endl;
  
  cout << "Is stack empty? " << s.empty() << endl;
  // s.pop();
  // s.pop();
  // s.pop();
  // cout << "Is stack empty? " << s.empty() << endl;

  cout << "Size of stack: " << s.size() << endl;

  return 0;
}