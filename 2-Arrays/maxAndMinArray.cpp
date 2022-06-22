#include <iostream>
using namespace std;

int * maxAndMinArray(int arr[], int n) {

  int max = INT_MIN;
  int min = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  int *res = new int[2];
  res[0] = max;
  res[1] = min;

  return res;
}

int main() {
  int arr[10] = {21, 23, 12, 34, 43, 54, 11, 1, 2, 89}; cout << endl;

  int * res = maxAndMinArray(arr, 10);

  cout << "Maximum element is: " << res[0] << endl;
  cout << "Minimum element is: " << res[1] << endl; cout << endl;

  delete [] res;
  
  return 0;
}