#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the first missing positive integer
int firstMissingPositive(vector<int>& nums) {
    // Step 1: Remove non-positive numbers (0 and negatives)
    nums.erase(remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }), nums.end());

    // Step 2: Sort the remaining numbers
    sort(nums.begin(), nums.end());

    int target = 1; // The smallest positive number we are looking for

    // Step 3: Go through the sorted list
    for (int n : nums) {
        if (n == target) {
            // If current number matches target, move to next target
            target++;
        } else if (n > target) {
            // If current number is greater, then target is missing
            return target;
        }
        // Ignore duplicates and smaller-than-target values
    }

    // Step 4: If all values till end are valid, return next expected number
    return target;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};

    // Call the function and print the result
    int missing = firstMissingPositive(nums);
    cout << "First missing positive integer: " << missing << endl;

    return 0;
}
