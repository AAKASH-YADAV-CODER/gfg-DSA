#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// it's navie solution with O(n2) T.C and O(1) A.S
int maxConsecutive(bool arr[], int n) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int curr = 0;
    for (int j = i; j < n; j++) {
      if (arr[j] == 1) {
        curr++;
      } else {
        break;
      }
    }
    res = max(res, curr);
  }
  return res;
}

// Efficient Solution in O(n) T.C and O(1) A.S
int maxConsecutiveEfficient(bool arr[], int n) {
  int res = 0;
  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      curr = 0;
    } else {
      curr++;
      res = max(res, curr);
    }
  }
  return res;
}
int main() {
  bool arr[] = {1, 0, 1, 1, 1, 1, 0, 0};
  int size = sizeof(arr) / sizeof(arr[0]);
  // int maxCons = maxConsecutive(arr, size);
  int maxCons = maxConsecutiveEfficient(arr, size);
  cout << "Hi Aakash lets start with neovim" << endl << maxCons << endl;
  return 0;
}
