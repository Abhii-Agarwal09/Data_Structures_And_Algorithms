#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
  int i = 0;
  int j = n-1;

  while (i <= j) {
    swap(arr[i], arr[j]);
    i++;
    j--;
  }

}

int main() {
  int arr[11] = {21, 23, 12, 34, 43, 54, 11, 1, 2, 89, 90};
  reverseArray(arr, 11);

  for (int i = 0; i < 11; i++) {
    cout << arr[i] << " ";
  } cout << endl;

  return 0;
}