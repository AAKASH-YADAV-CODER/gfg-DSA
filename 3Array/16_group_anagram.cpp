#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Function to group anagrams together
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Map to store groups of anagrams
    unordered_map<string, vector<string>> res;

    for (const auto& s : strs) {
        // Create a frequency count for each letter (a to z)
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Convert frequency vector to a unique key string like "1,0,0,..."
        string key = to_string(count[0]);
        for (int i = 1; i < 26; ++i) {
            key += ',' + to_string(count[i]);
        }

        // Use this key to group anagrams in the map
        res[key].push_back(s);
    }

    // Extract grouped anagrams from the map into a result vector
    vector<vector<string>> result;
    for (const auto& pair : res) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Call the groupAnagrams function
    vector<vector<string>> grouped = groupAnagrams(input);

    // Print the grouped anagrams
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
