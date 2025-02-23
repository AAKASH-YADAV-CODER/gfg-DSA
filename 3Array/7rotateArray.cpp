#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void leftRotateArray(int arr[], int size) {
  int temp = arr[0];
  for (int i = 1; i < size; i++) {

    arr[i - 1] = arr[i];
  }

  arr[size - 1] = temp;
}
int main() {

  int arr[] = {1, 2, 3, 4, 56, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  leftRotateArray(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}

/* Explainatoins
 Left Rotate an array means counter clockwise

1> Example-Left rotate by one
 input -> arr[]={1,2,3,4,5};
 output -> arr[]={2,3,4,5,1};

2>Example - Left rotate by one
 input -> arr[]={20,30,40};
 output -> arr[]={30.40,20};

step 1> take first element into temp variable
step 2>traver upto array and put arr[i-1]=arr[i]
setp 3> arr[n-1]


 */
