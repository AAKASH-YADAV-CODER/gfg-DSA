#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 * MAXIMUM CIRCULAR SUBARRAY SUM
 * --------------------------------------------------------
 * Circular means: after last index, we can wrap to index 0.
 *
 * Example: [5, -2, 3, 4]
 * A circular subarray can be [3, 4, 5] (wraps around end to start).
 *
 * We add two approaches:
 * 1) Naive: try all starts + lengths in circular way.  O(n^2)
 * 2) Efficient (Kadane-style): O(n)
 */

/*
 * NAIVE SOLUTION
 * --------------------------------------------------------
 * Idea in simple words:
 * - Pick every index as a starting point.
 * - From that start, keep extending the subarray up to n elements.
 * - Use modulo (%) to wrap around in a circular array.
 * - Track the best sum seen so far.
 *
 * Time  : O(n^2)
 * Space : O(1)
 */
int maxCircularSubarrayNaive(int arr[], int n) {
  // Best answer found so far. Start with first element (important for all-negative arrays).
  int res = arr[0];

  // Try every possible start index.
  for (int start = 0; start < n; start++) {
    int curr = 0;  // Running sum for subarray starting at "start".

    // Extend current subarray length from 1 to n.
    for (int len = 0; len < n; len++) {
      // Circular index: wraps back to 0 when crossing n-1.
      int idx = (start + len) % n;

      // Add next element in this circular walk.
      curr += arr[idx];

      // Update global maximum if this subarray is better.
      res = max(res, curr);
    }
  }
  return res;
}

/*
 * Helper: Kadane for normal (non-circular) maximum subarray sum.
 * Returns best sum of any contiguous subarray.
 */
int kadaneMax(int arr[], int n) {
  int best = arr[0];
  int endingHere = arr[0];

  for (int i = 1; i < n; i++) {
    // Either extend previous subarray or start new from arr[i].
    endingHere = max(endingHere + arr[i], arr[i]);
    best = max(best, endingHere);
  }
  return best;
}

/*
 * Helper: Kadane for minimum subarray sum.
 * Same flow, but with min() instead of max().
 */
int kadaneMin(int arr[], int n) {
  int best = arr[0];
  int endingHere = arr[0];

  for (int i = 1; i < n; i++) {
    // Either extend previous minimum-sum subarray or start new from arr[i].
    endingHere = min(endingHere + arr[i], arr[i]);
    best = min(best, endingHere);
  }
  return best;
}

/*
 * EFFICIENT SOLUTION (Kadane-style)
 * --------------------------------------------------------
 * Max circular answer can come from two cases:
 *
 * Case 1: Subarray does NOT wrap
 *   -> normal max subarray sum (Kadane max)
 *
 * Case 2: Subarray wraps around
 *   -> take totalSum - (minimum normal subarray sum)
 *      Why? Removing the minimum middle part leaves maximum wrapping part.
 *
 * Final answer = max(case1, case2)
 *
 * Important edge case:
 * - If all numbers are negative, case2 becomes 0 (invalid for this problem),
 *   so we must directly return case1.
 *
 * Time  : O(n)
 * Space : O(1)
 */
int maxCircularSubarrayEfficient(int arr[], int n) {
  // Case 1: best non-wrapping answer.
  int maxNormal = kadaneMax(arr, n);

  // If all are negative, maxNormal is the largest (least negative) element.
  // In this case, circular trick should not be used.
  if (maxNormal < 0) return maxNormal;

  // Compute total sum of array.
  int totalSum = 0;
  for (int i = 0; i < n; i++) totalSum += arr[i];

  // Minimum normal subarray sum (middle part to exclude in wrap case).
  int minNormal = kadaneMin(arr, n);

  // Case 2: wrapping answer.
  int maxCircular = totalSum - minNormal;

  // Best among non-wrap and wrap.
  return max(maxNormal, maxCircular);
}

int main() {
  int arr[] = {5, -2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Naive (O(n^2)) answer      -> " << maxCircularSubarrayNaive(arr, n)
       << endl;
  cout << "Efficient (O(n)) answer    -> " << maxCircularSubarrayEfficient(arr, n)
       << endl;

  return 0;
}
