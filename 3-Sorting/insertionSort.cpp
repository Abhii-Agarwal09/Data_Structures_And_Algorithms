#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {

  for (int i = 1; i < n; i++) {
    int temp = arr[i];

    int j = i-1;
    for (; j >= 0; j--) {
      if (arr[j] > temp) {
        // shift
        arr[j+1] = arr[j];
      }
      else {
        break;
      }
    }
    arr[j+1] = temp;
  }
  
}

int main() {

  int arr[10] = {17, 6, 45, 15, 26, 27, 18, 9, 87, 78};
  insertionSort(arr, 10);
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}