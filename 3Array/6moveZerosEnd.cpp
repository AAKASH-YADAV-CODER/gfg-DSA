#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Navie Method in O(n^2)-T.C O(1)-S.C
/*
void moveZeroEnd(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    if (arr[i] == 0) {
      for (int j = i + 1; j < length; j++) {
        if (arr[j] != 0) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
}
*/

// Second Method Efficient way O(n)-T.C O(1)-S.C
void moveZeroEnd(int arr[], int length) {
  int stalker = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] != 0) {
      arr[stalker] = arr[i];
      stalker++;
    }
  }
  for (int i = stalker; i < length; i++) {
    arr[i] = 0;
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}
int main() {
  int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  moveZeroEnd(arr, n);
  cout << "Hi Aakash lets start with neovim" << endl;
  printArray(arr, n);
  return 0;
}
