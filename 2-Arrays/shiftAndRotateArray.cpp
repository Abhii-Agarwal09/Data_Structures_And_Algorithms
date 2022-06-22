#include <iostream>
using namespace std;

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  } cout << endl;
}

void leftShiftArray(int arr[], int n) {

  int i = 0;
  
  for (; i < n-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[i] = 0;
  cout << "After left shift: ";
  display(arr, n);
}

void rightShiftArray(int arr[], int n) {

  int i = n-1;
  
  for (; i > 0; i--) {
    arr[i] = arr[i-1];
  }
  arr[i] = 0;

  cout << "After right shift: ";
  display(arr, n);
}

void leftRotateArray(int arr[], int n) {

  int el = arr[0];
  int i = 0;
  
  for (; i < n-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[i] = el;

  cout << "After left rotate: ";
  display(arr, n);
}

void rightRotateArray(int arr[], int n) {

  int el = arr[n-1];
  int i = n-1;
  
  for (; i > 0; i--) {
    arr[i] = arr[i-1];
  }
  arr[i] = el;

  cout << "After right rotate: ";
  display(arr, n);
}

int main() {
  int arr[11] = {21, 23, 12, 34, 43, 54, 11, 1, 2, 89, 90};

  cout << "Original array: ";
  display(arr,11);

  leftShiftArray(arr, 11);
  rightShiftArray(arr, 11);
  leftRotateArray(arr, 11);
  rightRotateArray(arr, 11);
  
  return 0;
}