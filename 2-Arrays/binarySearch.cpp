#include <iostream>
using namespace std;
/*
While low <= high
calculate mid = (low + high) / 2
check element
if element < array[mid] -> check in left side => high = mid - 1
if element > array[mid] -> check in right side => low = mid + 1
return index if element found
*/
int binarySearchUsingLoop(int element, int array[], int low, int high) {
  int l = low;
  int h = high;
  int mid;
  while (l <= h) {
    mid = (l + h) / 2;
    if (element == array[mid]) {
      return mid;
    }
    else if (element > array[mid]) {
      l = mid + 1;
    }
    else {
      h = mid - 1;
    }
  }
  return -1;
}

int binarySearchUsingRecursion(int element, int array[], int low, int high) {
  if (low <= high) {
    int mid = (low + high) / 2;
    if (element == array[mid]) {
      return mid;
    }
    else if (element > array[mid]) {
      return binarySearchUsingRecursion(element, array, mid + 1, high);
    }
    else {
      return binarySearchUsingRecursion(element, array, low, mid - 1);
    }
  }
  return -1;
}

int main() {
  int arr[10] = {1, 2, 4, 5, 6, 7, 8, 9};
  cout << "Loop: Element found at index: " << binarySearchUsingLoop(2, arr, 0, 7) << endl;
  cout << "Loop: Element found at index: " << binarySearchUsingLoop(3, arr, 0, 7) << endl;
  cout << "Recursion: Element found at index: " << binarySearchUsingRecursion(8, arr, 0, 7) << endl;
  cout << "Recursion: Element found at index: " << binarySearchUsingRecursion(3, arr, 0, 7) << endl;
  return 0;
}