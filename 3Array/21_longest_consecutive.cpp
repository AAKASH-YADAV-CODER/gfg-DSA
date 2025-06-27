#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to find the length of the longest consecutive elements sequence
int longestConsecutive(vector<int>& nums) {
    int res = 0;

    // Step 1: Use a set for O(1) lookups
    unordered_set<int> store(nums.begin(), nums.end());

    // Step 2: Check for each number
    for (int num : nums) {
        int streak = 0;
        int curr = num;

        // Count how many consecutive numbers exist starting from 'curr'
        while (store.find(curr) != store.end()) {
            streak++;
            curr++;
        }

        // Update the maximum streak found
        res = max(res, streak);
    }

    return res;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Call the function and print result
    int longestStreak = longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << longestStreak << endl;

    return 0;
}
