#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate total trapped rainwater with O(n2):-T.C
// int trap(const vector<int>& height) {
//     if (height.empty()) return 0;
//
//     int left = 0;
//     int right = height.size() - 1;
//
//     int leftMax = height[left];    // Max height from the left side
//     int rightMax = height[right];  // Max height from the right side
//     int water = 0;                 // Total trapped water
//
//     // Two-pointer approach
//     while (left < right) {
//         if (leftMax < rightMax) {
//             // Move left pointer to the right
//             left++;
//             leftMax = max(leftMax, height[left]); // Update max on the left
//             water += leftMax - height[left];      // Water trapped at current
//             index
//         } else {
//             // Move right pointer to the left
//             right--;
//             rightMax = max(rightMax, height[right]); // Update max on the
//             right water += rightMax - height[right];       // Water trapped
//             at current index
//         }
//     }
//
//     return water;
// }

// Naive solution in theta(n):- time complexity
int trapWater(vector<int> &height) {
  int n = height.size();
  int water = 0;
  int lmax[n];
  int rmax[n];
  lmax[0] = height[0];
  rmax[n - 1] = height[n - 1];
  for (int i = 1; i < n; i++)
    lmax[i] = max(height[i], lmax[i - 1]);
  for (int i = n - 2; i >= 0; i--)
    rmax[i] = max(height[i], rmax[i + 1]);
  for (int i = 1; i < n - 1; i++)
    water = water + (min(lmax[i], rmax[i]) - height[i]);
  return water;
}

int trapNaive(vector<int> &height) {
  int n = height.size();
  int waterTrapped = 0; // Initialize water trapped to 0

  // Loop through each bar
  for (int i = 0; i < n; i++) {
    // Find the maximum height on the left
    int leftMax = 0;
    for (int j = 0; j <= i; j++) {
      leftMax = max(leftMax, height[j]); // Update leftMax
    }

    // Find the maximum height on the right
    int rightMax = 0;
    for (int j = i; j < n; j++) {
      rightMax = max(rightMax, height[j]); // Update rightMax
    }

    // Water trapped on top of the current bar is:
    waterTrapped +=
        min(leftMax, rightMax) - height[i]; // Calculate trapped water
  }

  return waterTrapped;
}

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  // Call the function and print the result
  int totalwater = trapWater(height);
  // int totalWater = trapNaive(height);
  cout << "Total trapped rainwater: " << totalwater << endl;

  return 0;
}
