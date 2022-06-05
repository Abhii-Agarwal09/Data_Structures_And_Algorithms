#include <iostream>
using namespace std;

/*
1. Tail recursion -> Recursive call is the last statement
Everything is performed at calling time only
Nothing is performed at returning time
*/
void tailRecursion(int n) {
  if (n > 0) {
    cout << n << " ";
    tailRecursion(n - 1);
  }
}

/*
2. Head recursion -> Recursive call is the first statement
Everything is performed at return time only
Nothing is performed at calling time
*/
void headRecursion(int n) {
  if (n > 0) {
    headRecursion(n - 1);
    cout << n << " ";
  }
}

/*
3. Tree Recusrion -> Function calling itself more than 1 time
Linear recursion -> Function calling itself only 1 time
*/
void treeRecursion(int n) {
  if (n > 0) {
    cout << n << " ";
    treeRecursion(n - 1);
    treeRecursion(n - 1);
  }
}

/*
4. Indirect Recursion -> More than 1 function calling each other in a circular manner.
*/
// void indirectRecursionFun1(int n) {
//   if (n > 0) {
//     cout << n << " ";
//     indirectRecursionFun2(n - 1);
//   }
// }

// void indirectRecursionFun2(int n) {
//   if (n > 1) {
//     cout << n << " ";
//     indirectRecursionFun1(n / 2);
//   }
// }

/*
5. Nested Recursion -> Recursive function will pass parameter as recursive call
*/
int nestedRecursion(int n) {
  if (n > 100) {
    return n - 10;
  } else {
    return nestedRecursion(nestedRecursion(n + 11));
  }
}

int main() {
  cout << "Different types of recursion" << endl;
  cout << "Tail recursion" << endl;
  tailRecursion(3);
  cout << endl;
  cout << "Head recursion" << endl;
  headRecursion(3);
  cout << endl;
  cout << "Tree recursion" << endl;
  treeRecursion(3);
  cout << endl;
  // cout << "Indirect recursion" << endl;
  // indirectRecursionFun1(20);
  cout << "Nested recursion" << endl;
  cout << nestedRecursion(95) << endl;
  return 0;
}