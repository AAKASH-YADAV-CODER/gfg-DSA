#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
int maxSubArray(const vector<int>& nums) {
    int res = nums[0];   // Initialize result with the first element
    int total = 0;       // Total is used to accumulate subarray sum

    for (int n : nums) {
        if (total < 0) {
            total = 0;   // If total is negative, reset it (starting fresh)
        }

        total += n;      // Add current number to the running total
        res = max(res, total);  // Update max if the new total is higher
    }

    return res;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Call the function and print the result
    int maxSum = maxSubArray(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}
