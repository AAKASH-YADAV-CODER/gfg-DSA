#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// This is First Method Naive Solution
/*
int largestNumIndex(int arr[], int size) {
  int firstEle = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[firstEle]) {
      firstEle = i;
    }
  }
  return firstEle;
}

int SecondlargestNumIndex(int arr[], int n) {
  int LargNum = largestNumIndex(arr, n);
  int SecNum = -1;
  for (int i = 0; i < n; i++) {

  //here i done mistake which is i compare largnum with directly with secondlarg
number if (LargNum != i) { if (SecNum == -1) { SecNum = i; } else if (arr[i] >
arr[SecNum]) { SecNum = i;
      }
    }
  }
  return SecNum;
}
*/

// Second Method Efficient one O(n^2)
int SecondlargestNumIndex(int arr[], int length) {
  int LarN = 0, SecN = -1;
  for (int i = 1; i < length; i++) {
    if (arr[i] > arr[LarN]) {
      SecN = LarN;
      LarN = i;
    } else if (arr[i] < arr[LarN]) {
      if (SecN == -1) {
        SecN = i;
      } else if (arr[i] > arr[SecN]) {
        SecN = i;
      }
    }
  }
  return SecN;
}
int main() {
  int arr[] = {1, 2, 32, 45, 5, 65};
  int n = sizeof(arr) / sizeof(arr[0]);
  // cout << largestNumIndex(arr, n) << endl;
  cout << SecondlargestNumIndex(arr, n) << endl;

  return 0;
}
