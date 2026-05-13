#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 * Problem (simple words):
 * Find the LONGEST contiguous part of the array where EVEN and ODD numbers
 * ALTERNATE one after another (even-odd-even-odd... or odd-even-odd-even...).
 *
 * Naive idea:
 * Try every possible START index i. From there, walk to the right (j) and
 * count how long the alternating pattern stays valid. Keep the best length.
 *
 * Time: O(n^2) in worst case (nested loops).
 * Space: O(1).
 */

int maxEvenOddSubarray(int arr[], int n) {
  // At least one element counts as a subarray of length 1 (single number is "trivially" ok).
  int res = 1;

  // Outer loop: fix the START of the subarray at index i.
  for (int i = 0; i < n; i++) {
    // Length of the alternating subarray that starts at i (starts with just arr[i], so 1).
    int curr = 1;

    // Inner loop: extend the subarray to the right, comparing neighbours arr[j-1] and arr[j].
    for (int j = i + 1; j < n; j++) {
      // We need one EVEN and one ODD next to each other (order can be either way).
      // Case A: arr[j] is even AND arr[j-1] is odd   -> good, pattern continues.
      // Case B: arr[j] is odd   AND arr[j-1] is even -> good, pattern continues.
      // arr[j] % 2 == 0 means even; arr[j] % 2 != 0 means odd (works for negatives too).
      if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) ||
          (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
        curr++;  // Still alternating: grow current length by 1.
      else
        break;  // Pattern broke: stop extending from this start i (no point going further right).
    }
    // Best answer so far = max of old best and what we got starting at i.
    res = max(res, curr);
  }
  return res;  // Longest alternating even-odd subarray length found.
}

int main() {
  int arr[] = {6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum length of even odd subarray is " << maxEvenOddSubarray(arr, n) << endl;
  return 0;
}
