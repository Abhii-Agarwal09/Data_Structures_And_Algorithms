#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {

  for (int i = 0; i < n-1; i++) {
    int minIndex = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }

}

int main() {

  int arr[10] = {17, 6, 45, 15, 26, 27, 18, 9, 87, 78};
  selectionSort(arr, 10);
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}