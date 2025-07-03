#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate total trapped rainwater
int trap(const vector<int>& height) {
    if (height.empty()) return 0;

    int left = 0;
    int right = height.size() - 1;

    int leftMax = height[left];    // Max height from the left side
    int rightMax = height[right];  // Max height from the right side
    int water = 0;                 // Total trapped water

    // Two-pointer approach
    while (left < right) {
        if (leftMax < rightMax) {
            // Move left pointer to the right
            left++;
            leftMax = max(leftMax, height[left]); // Update max on the left
            water += leftMax - height[left];      // Water trapped at current index
        } else {
            // Move right pointer to the left
            right--;
            rightMax = max(rightMax, height[right]); // Update max on the right
            water += rightMax - height[right];       // Water trapped at current index
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Call the function and print the result
    int totalWater = trap(height);
    cout << "Total trapped rainwater: " << totalWater << endl;

    return 0;
}
