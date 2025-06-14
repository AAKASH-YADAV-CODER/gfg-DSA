#include <iostream>
#include <vector>
using namespace std;

bool hasDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; // You can modify this to test other cases

    if (hasDuplicate(nums)) {
        cout << "Duplicates found!" << endl;
    } else {
        cout << "No duplicates." << endl;
    }

    return 0;
}
