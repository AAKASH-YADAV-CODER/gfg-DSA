#include <iostream>
#include <vector>
using namespace std;

// Function to find indices of two numbers that add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    // Loop through each element
    for (int i = 0; i < nums.size(); i++) {
        // Loop through the rest of the elements after i
        for (int j = i + 1; j < nums.size(); j++) {
            // Check if the sum of the two elements equals the target
            if (nums[i] + nums[j] == target) {
                // If yes, return their indices
                return {i, j};
            }
        }
    }
    // If no such pair is found, return an empty vector
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the twoSum function
    vector<int> result = twoSum(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
