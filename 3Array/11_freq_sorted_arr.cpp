#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// Naive Method 1>
// void printFreq(vector<int> &arr, int N) {
//   int freq = 1, i = 1;
//   while (i < N) {
//     while (i < N && arr[i] == arr[i - 1]) {
//       freq++;
//       i++;
//     }
//     cout << "The element ->" << arr[i - 1] << " Appears " << freq << " times
//     "
//          << endl;
//     i++;
//     freq = 1;
//   }
//   if (N == 1 || arr[N - 1] != arr[N - 2]) {
//
//     cout << "The element ->" << arr[N - 1] << " Appears " << 1 << " times "
//          << endl;
//   }
// }
// Or By this way.
void printFreq(vector<int> &arr, int n) {
  int freq = 1;
  int idx = 1;
  int value = arr[0];
  while (idx < n) {

    // check if the current value is equal to
    // previous value.
    if (arr[idx - 1] == arr[idx]) {
      freq++;
      idx++;
    } else {
      cout << value << " " << freq << endl;
      value = arr[idx];
      idx++;

      // reset the frequency
      freq = 1;
    }
  }

  // print the last value and its frequency
  cout << value << " " << freq;
}
int main() {
  vector<int> arr = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
  int N = arr.size();

  // Function Call
  printFreq(arr, N);

  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}

/*
 Naive Approach: The simplest approach is to traverse the array and keep the
count of every element encountered in a HashMap and then, in the end, print the
frequencies of every element by traversing the HashMap. This approach is already
implemented here.

Time Complexity: O(N)
Auxiliary Space: O(N)



 */
