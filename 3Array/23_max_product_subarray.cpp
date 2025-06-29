#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum product subarray
int maxProduct(const vector<int>& nums) {
    // Step 1: Initialize result with the maximum number in the array
    int res = *max_element(nums.begin(), nums.end());

    // Step 2: Initialize current max and min products (start from 1)
    int curMax = 1, curMin = 1;

    for (int n : nums) {
        int temp = curMax * n;

        // Step 3: Update curMax and curMin considering three possibilities:
        // - Current number alone (starting new subarray)
        // - Extend previous max product
        // - Extend previous min product (in case negative * negative becomes positive)
        curMax = max({temp, curMin * n, n});
        curMin = min({temp, curMin * n, n});

        // Step 4: Update result with the current max product
        res = max(res, curMax);
    }

    return res;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    // Call the function and print the result
    int maxProd = maxProduct(nums);
    cout << "Maximum product subarray: " << maxProd << endl;

    return 0;
}
