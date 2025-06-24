#include <iostream>
#include <vector>
using namespace std;

// Function to return a vector where each element is the product of all other elements except itself
vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);

    // For each index, calculate the product of all elements except the current one
    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                prod *= nums[j];  // Multiply all elements except nums[i]
            }
        }
        res[i] = prod;  // Store result for current index
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    // Call the function
    vector<int> result = productExceptSelf(nums);

    // Print the result
    cout << "Product of array except self:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
