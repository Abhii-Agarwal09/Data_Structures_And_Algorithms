#include <iostream>
using namespace std;

// a XOR a = 0, a XOR 0 = a
int findUnique(int *arr, int size) {
    
  int ans;
    
  for (int i = 0; i < size; i++) {
    ans ^= arr[i];
  }
    
  return ans;
}

int main() {
  int arr[5] = {2, 2, 1, 1, 3};
  int res = findUnique(arr, 5);
  cout << "Unique element is: " << res << endl;
  return 0;
}