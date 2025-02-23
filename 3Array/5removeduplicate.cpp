#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Navie method O(n) T.C O(n)-S.C
/*
int removeduplicate(int arr[], int length) {
  int temp[length];
  temp[0] = arr[0];
  int res = 1;
  for (int i = 1; i < length; i++) {
    if (temp[res - 1] != arr[i]) {
      temp[res] = arr[i];
      res++;
    }
  }
  for (int i = 0; i < res; i++) {
    arr[i] = temp[i];
  }
  return res;
}
*/

// Efficient Method O(n) T.C O(1) S.C
int removeduplicate(int arr[], int length) {
  int res = 1;
  for (int i = 1; i < length; i++) {
    if (arr[i] != arr[res - 1]) {
      arr[res] = arr[i];
      res++;
    }
  }
  return res;
}

int main() {
  // this function used for sorted array not for unsorted array
  int arr[] = {1, 2, 2, 6, 6, 7, 7, 13};
  // int size = 8;
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
  // cout << removeduplicate(arr, size) << endl;

  size = removeduplicate(arr, size);
  cout << "Hi Aakash lets start with neovim" << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
