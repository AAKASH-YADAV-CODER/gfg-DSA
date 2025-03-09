#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void leaders(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] >= arr[i]) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      cout << arr[i] << endl;
    }
  }
}
int main() {
  int arr[] = {7, 10, 4, 10, 6, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  leaders(arr, n);

  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
