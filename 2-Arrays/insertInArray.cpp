#include <iostream>
using namespace std;

/*
Start from i = length, and shift each element till i = index, then assign element to that index
*/
void insertElementAtIndex(int element, int index, int array[], int length, int size) {
  if (index > size) {
    return;
  }
  int i;
  for (i = length; i > index; i--) {
    array[i] = array[i - 1];
  }
  array[i] = element;
}

int main() {
  int arr[10] = {1,2,4,5,6};
  insertElementAtIndex(3, 2, arr, 5, 10);
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}