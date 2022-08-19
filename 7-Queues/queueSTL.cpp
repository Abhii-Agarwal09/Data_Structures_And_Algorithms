#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  cout << "Size of queue: " << q.size() << endl;
  cout << "Front element: " << q.front() << endl;
  cout << "Back element: " << q.back() << endl;
  q.pop();
  q.pop();
  cout << "After 2 pop operations" << endl;
  cout << "Size of queue: " << q.size() << endl;
  cout << "Front element: " << q.front() << endl;
  cout << "Back element: " << q.back() << endl;
  cout << "Is queue empty? " << q.empty() << endl;
  return 0;
}