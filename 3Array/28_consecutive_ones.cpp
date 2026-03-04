#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// it's navie solution with O(n2) T.C and O(1) A.S
/*
 * MAX CONSECUTIVE 1s IN A BINARY ARRAY
 * Given an array of 0s and 1s, we find the longest run of consecutive 1s.
 * Example: [1, 0, 1, 1, 1, 1, 0, 0] → answer is 4 (four 1s in a row).
 */
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

// Efficient approach: single pass. We keep a running count of consecutive 1s.
// When we see 0, we reset the count; when we see 1, we add to count and update
// max. Time: O(n), Space: O(1) BUG FIX: curr must be declared OUTSIDE the loop
// so it keeps its value between iterations. (Previously curr was inside the
// loop, so it reset to 0 every time and never went above 1.)
int maxConsecutiveEfficient(bool arr[], int n) {
  int res = 0;
  int curr =
      0; // current consecutive streak of on 1's(must live outside of loop)
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      curr = 0;
    } else {
      curr++;
      res = max(res, curr); // it's navie solution with O(n2) T.C and O(1) A.S
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
