#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {

  int pivot = arr[s];
  int count = 0;

  for (int i = s+1; i <= e; i++) {
    if (arr[i] <= pivot) {
      count++;
    }
  }

  // place pivot at right position
  int pivotIndex = s + count;
  swap(arr[pivotIndex], arr[s]);

  // make all elements at left smaller than pivot and in right, greater than pivot
  int i = s, j = e;

  while (i < pivotIndex && j > pivotIndex) {
    
    while (arr[i] <= pivot) {
      i++;
    }

    while (arr[j] > pivot) {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i], arr[j]);
    }
    i++;
    j--;

  }

  return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

  // base case
  if (s >= e) return;

  // partition
  int p = partition(arr, s, e);

  // left sort
  quickSort(arr, s, p-1);

  // right sort
  quickSort(arr, p+1, e);

}


int main() {

  int arr[10] = {17, 6, 45, 15, 26, 27, 18, 9, 87, 78};
  quickSort(arr, 0, 9);
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}