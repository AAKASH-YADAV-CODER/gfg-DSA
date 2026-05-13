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
 *
 * ---------- EFFICIENT (single pass) — Kadane-style idea ----------
 * Same spirit as Kadane's algorithm for max subarray SUM: here we track the
 * best valid subarray ENDING at the current index (curr = length), not a sum.
 * Walk the array once from left to right (index i = 1 .. n-1).
 * Keep "curr" = length of the alternating segment that ENDS at index i.
 * - If arr[i] and arr[i-1] have different parity (one even, one odd), the
 *   pattern continues: curr grows by 1 (like extending the same subarray).
 * - If they are BOTH even or BOTH odd, the old segment cannot continue;
 *   start fresh: curr = 1 (only arr[i] counts for the new segment).
 * "res" always stores the best curr we have seen so far.
 *
 * Time: O(n) — one loop.
 * Space: O(1).
 */

int maxEvenOddSubarrayNaive(int arr[], int n) {
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

// Efficient solution: Kadane-style — one left-to-right scan (same logic as naive, no inner loop).
int maxEvenOddSubarray(int arr[], int n) {
  // Best length seen anywhere (Kadane: global best). At least 1 when n >= 1.
  int res = 1;

  // Length of best alternating subarray that ENDS at current index (Kadane: best ending here).
  int curr = 1;

  // Start from i = 1: compare each element with its left neighbour arr[i-1].
  for (int i = 1; i < n; i++) {
    // Same check as naive: neighbours must be one even, one odd (either order).
    if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) ||
        (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)) {
      curr++;                    // Alternation continues: extend the running segment.
      res = max(res, curr);      // Maybe this longer segment is the new global best.
    } else {
      curr = 1;  // Pattern broke (two evens or two odds in a row). New segment is only arr[i].
    }
  }
  return res;
}

int main() {
  int arr[] = {6, 5, 4, 3, 2, 1,4};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum length of even odd subarray is " << maxEvenOddSubarray(arr, n) << endl;
  return 0;
}
