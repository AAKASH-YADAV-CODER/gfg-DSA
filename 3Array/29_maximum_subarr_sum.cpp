#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int maxSubArrSum(int arr[], int n) {
  // int n = sizeof(arr) / sizeof(arr[0]);
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    int curr = 0;
    for (int j = i; j < n; j++) {
      curr = curr + arr[j];
      res = max(res, curr);
    }
  }
  return res;
};
int main() {
  int arr[] = {2, 3, -8, 7, -1, 2, 3};
  // int arr[] = {5, 8, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int maxarr = maxSubArrSum(arr, n);
  cout << "max subarray sum is ->" << maxarr << endl;
  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
