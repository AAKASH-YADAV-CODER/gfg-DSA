#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// 1> Naive Method
/*
void leftRotateByOne(int arr[], int n) {
  int temp = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
}
void leftRotateByD(int arr[], int n, int d) {
  for (int i = 0; i < d; i++) {
    leftRotateByOne(arr, n);
  }
}
*/

// 2> Efficient Method
/*
void leftRotateByD(int arr[], int size, int d) {
  int temp[d];
  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }
  for (int i = d; i < size; i++) {
    arr[i - d] = arr[i];
  }
  for (int i = 0; i < d; i++) {
    arr[size - d + i] = temp[i];
  }
}
*/

// 3>Efficient Method (reverse alogrithm)
void reverse(int arr[], int low, int high) {
  while (low < high) {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
    low++;
    high--;
  }
}
void leftRotateByD(int arr[], int size, int d) {
  reverse(arr, 0, d - 1);
  reverse(arr, d, size - 1);
  reverse(arr, 0, size - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int d = 4;
  leftRotateByD(arr, n, d);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}

/*
In this we have to left rotate upto given number of d

Example 1
arr[]={1,2,3,4,5,6,7,8};
d=4
output:- arr[]={5,6,7,8,1,2,3,4}
T.C - theta(nd) A.S=0(1)

Naive Method 1>
left rotate array by one(leftRotateByone)
upto given number of d i'm calling this lefRotateByOne function


Efficient Method 2>
T.C-> theta(n+d-d+d)->theta(n+d)->if d<=n->theta(n)
A.S->theta(d)
a)put 0 to d element into temp array
b)now put in index 0 to d the remaining element of an array
c)now insert d to n temp element into array value


3 Efficient Method> (Reverse algorithm)
T.C->theta(n)
A.S->theta(d)
a)reverse first d element of array
b)reverse d to n-1 element of array
c)reverse 0 to n-1 element of array

*/
