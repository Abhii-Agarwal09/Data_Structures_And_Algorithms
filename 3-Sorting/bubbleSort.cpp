#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  
  // for rounds 1 to n - 1
  for (int i = 1; i < n; i++) {
    cout << "Round " << i << endl;

    int flag = 0;
    // fpr decreasing comparisons
    for (int j = 0; j < n-1; j++) {
      // swapping
      if (arr[j] > arr[j+1]) {
        cout << "Swapping" << endl;;
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = 1;
      }
    }
    cout << endl;
    if (flag == 0) {
      cout << "Array sorted, breaking out of loop" << endl;
      break;
    };
  }

}

int main() {

  int arr[10] = {17, 6, 45, 15, 26, 27, 18, 9, 87, 78};
  int arr2[5] = {1, 2, 3, 4, 5};
  bubbleSort(arr2, 5);
  for (int i = 0; i < 5; i++) {
    cout << arr2[i] << " ";
  }

  return 0;
}