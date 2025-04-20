#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Naive Solution Method 1>.
// int maxProfit(int arr[], int start, int end) {
//   if (start >= end)
//     return 0;
//   int profit = 0;
//   for (int i = start; i < end; i++) {
//     for (int j = i + 1; j <= end; j++) {
//       if (arr[j] > arr[i]) {
//         int curr_res = arr[j] - arr[i] + maxProfit(arr, start, i - 1) +
//                        maxProfit(arr, j + 1, end);
//         profit = max(profit, curr_res);
//       }
//     }
//   }
//   return profit;
// }

// 2> Efficient sol. also simple and easy.
int maxProfit(int arr[], int start, int end) {
  int profit = 0;
  for (int i = start; i <= end;
       i++) { // here i have done mistake which is i start traversing from 1
              // element(0th index) which is totally wrong because before 1
              // element(0th index) there is 0 value and minus 1 element with 0
              // will also add up like in this case here the first element is
              // 100 - 0 = 100 then the result i got 100+ value.
    if (arr[i] > arr[i - 1]) {
      profit += arr[i] - arr[i - 1];
    }
  }
  return profit;
}
int main() {
  int price[] = {100, 180, 260, 310, 40, 535, 695};
  int n = sizeof(price) / sizeof(price[0]);
  cout << n << "<-size of the array" << endl;
  cout << maxProfit(price, 1, n - 1);

  cout << "Hi Aakash lets start with neovim" << endl;
  return 0;
}
/*
1) Naive Approach

A simple approach is to try buying the stocks and selling them every single day
when profitable and keep updating the maximum profit so far.

Follow the steps below to solve the problem:

-Try to buy every stock from start to end – 1
-After that again call the maxProfit function to calculate answer
-curr_profit = price[j] – price[i] + maxProfit(start, i – 1) + maxProfit(j + 1,
end) -profit = max(profit, curr_profit)
Time Complexity: O(n2), Trying to buy every stock and exploring all
possibilities. Auxiliary Space: O(1)

2) Efficient Approach (Valley Peak Approach):

In this approach, we just need to find the next greater element and subtract it
from the current element so that the difference keeps increasing until we reach
a minimum. If the sequence is a decreasing sequence, so the maximum profit
possible is 0.

Follow the steps below to solve the problem:

-maxProfit = 0
-if price[i] > price[i – 1]
  maxProfit = maxProfit + price[i] – price[i – 1]
Time Complexity: O(n), Traversing over the array of size n
Auxiliary Space: O(1)

*/
