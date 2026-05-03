#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 * MAXIMUM SUBARRAY SUM - Naive (Brute Force) Approach
 * -----------------------------------------------
 * Problem: Find the largest sum we can get from any contiguous subarray.
 *
 * Simple idea: Try EVERY possible subarray and see which one has the biggest sum.
 * - A subarray is just a contiguous slice of the array (e.g. [7, -1, 2] from the array).
 * - We use two loops:
 *   1. Outer loop (i): "Where does the subarray START?"
 *   2. Inner loop (j): "Where does the subarray END?" (from i to end)
 * - For each start i, we extend the subarray one element at a time (j = i, i+1, ... n-1),
 *   add that element to curr, and update our best result (res) if curr is bigger.
 *
 * Time Complexity:  O(n^2)
 *   - For each of n starting positions i, we may run the inner loop up to n times.
 *   - So total iterations ≈ n * n = n^2.
 * Space Complexity: O(1) — we only use a few variables (res, curr, i, j)
 * 

 What “contiguous” means

Contiguous = one continuous block in the array. You’re allowed only to take a segment of the array: some start index and some end index, with no gaps in between.
So for:

Index:  0   1    2   3    4   5   6
Array: [2,  3,  -8,  7,  -1,  2,  3]
✅ Contiguous: [7, -1, 2, 3] (indices 3,4,5,6 — next to each other).
❌ Not contiguous: [2, 7, 3] (we skipped -8, -1, 2 — so there are gaps).
 */

int maxSubArrSum(int arr[], int n) {
  // Start with the first element as our best sum so far (in case array has one element or all negative)
  int res = arr[0];

  // Try every possible START of a subarray (index i)
  for (int i = 0; i < n; i++) {
    int curr = 0;  // Sum of the current subarray [i ... j]

    // Extend the subarray from start i to every possible END (index j).
    for (int j = i; j < n; j++) {
      curr = curr + arr[j];           // Add next element to current subarray sum
      res = max(res, curr);           // Update best result if this subarray is better
    }
  }
  return res;
}

int main() {
  int arr[] = {2, 3, -8, 7, -1, 2, 3};
  // int arr[] = {5, 8, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int maxarr = maxSubArrSum(arr, n);
  cout << "max subarray sum is -> " << maxarr << endl;
  return 0;
}
