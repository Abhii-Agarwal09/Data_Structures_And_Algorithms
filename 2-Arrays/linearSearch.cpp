#include <iostream>
using namespace std;

/*
Start from beginning and match each element against the element to be found
*/
int linearSearch(int element, int array[], int length, int size) {
  for (int i = 0; i < length; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[10] = {1,2,4,5,6};
  cout << "Element found at index: " << linearSearch(4, arr, 5, 10) << endl;
  cout << "Element found at index: " << linearSearch(3, arr, 5, 10) << endl;
  return 0;
}