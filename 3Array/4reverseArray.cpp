#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void reverseArray(int arr[], int length) {
  int first = 0, last = length - 1;
  while (first < last) {
    int temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    first++;
    last--;
  }
}
int main() {
  int arr[] = {1, 2, 13, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  reverseArray(arr, size);
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }

  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
