#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to return top K frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count the frequency of each number using a hash map
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    // Step 2: Move (frequency, number) pairs into a vector
    vector<pair<int, int>> freqVec;
    for (const auto& p : count) {
        freqVec.push_back({p.second, p.first}); // {frequency, number}
    }

    // Step 3: Sort the vector in descending order based on frequency
    sort(freqVec.rbegin(), freqVec.rend()); // rbegin() = reverse begin

    // Step 4: Collect the top K elements from the sorted vector
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(freqVec[i].second); // second = the original number
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Call the function to get top K frequent elements
    vector<int> topK = topKFrequent(nums, k);

    // Print the result
    cout << "Top " << k << " frequent elements: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
