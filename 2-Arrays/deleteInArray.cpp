#include <iostream>
using namespace std;

/*
Shift the forward elements one place backward
*/
void deleteFromIndex(int index, int array[], int length, int size) {
  if (index > size || index > length) {
    return;
  }
  for (int i = index; i < length; i++) {
    array[i] = array[i + 1];
  }
  return;
}

int main() {
  int arr[10] = {1,2,4,5,6};
  deleteFromIndex(3, arr, 5, 10);
  for (int i = 0; i < 4; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}