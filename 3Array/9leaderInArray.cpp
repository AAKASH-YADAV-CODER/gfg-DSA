#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Method 1 Naive Solution
// void leaders(int arr[], int n) {
//   for (int i = 0; i < n; i++) {
//     bool flag = true;
//     for (int j = i + 1; j < n; j++) {
//       if (arr[j] >= arr[i]) {
//         flag = false;
//         break;
//       }
//     }
//     if (flag == true) {
//       cout << arr[i] << endl;
//     }
//   / }

// Method 2 Efficient Solution
void leaders(int arr[], int n) {
  int ans = arr[n - 1];
  cout << ans << endl;
  for (int i = n - 2; i >= 0; i--) {
    if (ans < arr[i]) {
      ans = arr[i];
      cout << ans << endl;
    }
  }
}
int main() {
  int arr[] = {16, 17, 4, 3, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  leaders(arr, n);

  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
/*
For example:

Input: arr[] = {16, 17, 4, 3, 5, 2},
Output: 17, 5, 2

Input: arr[] = {1, 2, 3, 4, 5, 2},
Output: 5, 2

Naive Approach:
Time Complexity: O(N * N)
Auxiliary Space: O(1):-

Use two loops. The outer loop runs from 0 to size – 1 and one by one pick all
elements from left to right. The inner loop compares the picked element to all
the elements on its right side. If the picked element is greater than all the
elements to its right side, then the picked element is the leader.


Method 2 Efficient Approach:
Time Complexity: O(n)
Auxiliary Space: O(1):-

Find Leader by finding suffix maximum:

The idea is to scan all the elements from right to left in an array and keep
track of the maximum till now. When the maximum changes its value, print it. Let
the array be arr[] = {16, 17, 4, 3, 5, 2}

arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 2 , ans[] = { 2 }
arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 5 , ans[] = { 2, 5 }
arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 5 , ans[] = { 2, 5 }
arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 5 , ans[] = { 2, 5 }
arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 17 , ans[] = { 2, 5, 17 }
arr[] = {16, 17, 4, 3, 5, 2} , max_from_right = 17 , ans[] = { 2, 5, 17 }


*/
