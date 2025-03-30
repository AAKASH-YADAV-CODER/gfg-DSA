#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 1> Naive Method
// int maxdifference(int arr[], int size) {
//   int res = arr[1] - arr[0];
//   for (int i = 0; i < size; i++) {
//     for (int j = i + 1; j < size; j++) {
//       res = max(res, arr[j] - arr[i]);
//     }
//   }
//   return res;
// }

// 2> Efficient Method
int maxdifference(int arr[], int n) {
  int res = arr[1] - arr[0], minValue = arr[0];
  for (int i = 1; i < n; i++) {
    res = max(res, arr[i] - minValue);
    minValue = min(minValue, arr[i]);
  }
  return res;
}

int main() {

  int arr[] = {30, 10, 8, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Function calling
  cout << "Maximum difference is " << maxdifference(arr, n) << endl;
  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
/*
1>Naive  solution
Time Complexity : O(n^2)
Auxiliary Space : O(1)
Use two loops. In the outer loop, pick elements one by one and in the inner loop
calculate the difference of the picked element with every other element in the
array and compare the difference with the maximum difference calculated so far.
Below is the implementation of the above approach :

Desi bhasa->
1>find difference between first two element as per condition
res=arr[1]-arr[0];
2>Travse with two loops i and j, j always start from i+1 upto size
res=max(res,arr[j]-arr[i]);
3> return res;




2> Efficient Solution
Time Complexity : O(n)
Auxiliary Space : O(1)

Explaination:-
Method 2 (Tricky and Efficient)
In this method, instead of taking difference of the picked element with every
other element, we take the difference with the minimum element found so far. So
we need to keep track of 2 things: 1) Maximum difference found so far
(max_diff). 2) Minimum number visited so far (min_element).



Desi Bhasa->
1> again extracting the initial result as res=arr[1]-arr[0] for base case if
there is only two element then it would work. Now minValue=arr[0];
2>res=max(res,arr[i]-minValue) in this we find max between previous result and
comparing from travsing arr[i]-minValue; 3>update minValue=min(minValue,arr[i]);
4>return the result;



*/
