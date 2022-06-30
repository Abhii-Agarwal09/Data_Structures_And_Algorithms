#include <iostream>
using namespace std;

/* Function overloading can be achieved by changing the number of parameters */ 

class A {
  public:
    int a;
    int b;
    // Function overloading
    void sayHello() {
      cout << "Hello from A" << endl;
    }

    void sayHello(int n) {
      cout << "Hello from A " << n << endl;
    }

    // Operator overloading
    void operator + (A &obj) {
      int value1 = this -> a;
      int value2 = obj.a;

      cout << "Output: value2 - value1 = " << value2 - value1 << endl;
    }
};

int main() {

  A obj1;
  A obj2;
  obj1.sayHello();

  obj1.a = 4;
  obj2.a = 7;

  obj1 + obj2;

}