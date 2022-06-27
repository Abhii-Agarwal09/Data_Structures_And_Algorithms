#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n) {
  for (int i = 0; i < n-1; i+=2) {
    swap(arr[i], arr[i+1]);
  }
}

int main() {
  int arr[12] = {21, 23, 12, 34, 43, 54, 11, 1, 2, 89, 90, 21};

  swapAlternate(arr, 12); 
  for (int i = 0; i < 12; i++) {
    cout << arr[i] << " ";
  } cout << endl;

  return 0;
}