#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum number of chunks the array can be split into
// so that sorting each chunk individually and concatenating them results in a sorted array
int maxChunksToSorted(const vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;     // Count of valid chunks
    int diff = 0;    // Running difference between values and indices

    for (int i = 0; i < n; i++) {
        diff += arr[i] - i;

        // If the total difference is zero, it means the elements from 0 to i
        // can form a chunk that, when sorted, will be in the correct position.
        if (diff == 0) {
            cnt++;   // We can make a chunk here
        }
    }

    return cnt;
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 4};

    // Call the function and print the result
    int chunks = maxChunksToSorted(arr);
    cout << "Maximum number of chunks: " << chunks << endl;

    return 0;
}
