#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Navie Solution Method 1>.
int maxProfit(int arr[], int start, int end) {
  if (start >= end)
    return 0;
  int profit = 0;
  for (int i = start; i < end; i++) {
    for (int j = i + 1; j <= end; j++) {
      if (arr[j] > arr[i]) {
        int curr_res = arr[j] - arr[i] + maxProfit(arr, start, i - 1) +
                       maxProfit(arr, j + 1, end);
        profit = max(profit, curr_res);
      }
    }
  }
  return profit;
}
int main() {
  int price[] = {100, 180, 260, 310, 40, 535, 695};
  int n = sizeof(price) / sizeof(price[0]);

  cout << maxProfit(price, 0, n - 1);

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
*/
