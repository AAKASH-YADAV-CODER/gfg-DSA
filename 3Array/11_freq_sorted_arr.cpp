#include <bits/stdc++.h>
#include <iostream>
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
// void printFreq(vector<int> &arr, int n) {
//   int freq = 1;
//   int idx = 1;
//   int value = arr[0];
//   while (idx < n) {
//
//     // check if the current value is equal to
//     // previous value.
//     if (arr[idx - 1] == arr[idx]) {
//       freq++;
//       idx++;
//     } else {
//       cout << value << " " << freq << endl;
//       value = arr[idx];
//       idx++;
//
//       // reset the frequency
//       freq = 1;
//     }
//   }
//
//   // print the last value and its frequency
//   cout << value << " " << freq;
// }

// Efficient Method
void printFreq(vector<int> &arr, int N) {

  // Stores the frequency of an element
  int freq = 1;

  // Traverse the array arr[]
  for (int i = 1; i < N; i++) {

    // If the current element is equal
    // to the previous element
    if (arr[i] == arr[i - 1]) {

      // Increment the freq by 1
      freq++;
    }

    // Otherwise,
    else {
      cout << "Frequency of " << arr[i - 1] << " is: " << freq << endl;
      // Update freq
      freq = 1;
    }
  }

  // Print the frequency of the last element
  cout << "Frequency of " << arr[N - 1] << " is: " << freq << endl;
}
int main() {
  vector<int> arr = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
  int N = arr.size();

  // Function Call
  printFreq(arr, N);

  cout << "Hi Aakash lets start with neovim" << endl;
  if constexpr (true) { // 'if constexpr' is a C++17 feature
    std::cout << "Compiled with C++17 or higher!" << std::endl;
  }
  return 0;
}

/*
 Naive Approach: The simplest approach is to traverse the array and keep the
count of every element encountered in a HashMap and then, in the end, print the
frequencies of every element by traversing the HashMap. This approach is already
implemented here.

Time Complexity: O(N)
Auxiliary Space: O(N)


Efficient Approach: The above approach can be optimized in terms of space used
based on the fact that, in a sorted array, the same elements occur
consecutively, so the idea is to maintain a variable to keep track of the
frequency of elements while traversing the array. Follow the steps below to
solve the problem:

Initialize a variable, say freq as 1 to store the frequency of elements.
Iterate in the range [1, N-1] using the variable i and perform the following
steps: If the value of arr[i] is equal to arr[i-1], increment freq by 1. Else
print value the frequency of arr[i-1] obtained in freq and then update freq
to 1. Finally, after the above step, print the frequency of the last distinct
element of the array as freq.

 */
