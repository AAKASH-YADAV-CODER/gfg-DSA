#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to encode a list of strings into a single string
string encode(vector<string>& strs) {
    if (strs.empty()) return "";

    vector<int> sizes;
    string res = "";

    // Step 1: Store sizes of each string
    for (string& s : strs) {
        sizes.push_back(s.size());
    }

    // Step 2: Add sizes followed by comma (e.g., "4,3,5,")
    for (int sz : sizes) {
        res += to_string(sz) + ',';
    }

    // Step 3: Add delimiter '#' to separate sizes and actual strings
    res += '#';

    // Step 4: Append all strings back-to-back
    for (string& s : strs) {
        res += s;
    }

    return res;
}

// Function to decode the encoded string back into original strings
vector<string> decode(string s) {
    if (s.empty()) return {};

    vector<int> sizes;
    vector<string> res;
    int i = 0;

    // Step 1: Parse sizes until '#' is found
    while (s[i] != '#') {
        string cur = "";
        while (s[i] != ',') {
            cur += s[i];
            i++;
        }
        sizes.push_back(stoi(cur)); // convert string to integer size
        i++; // skip the comma
    }

    i++; // skip the '#'

    // Step 2: Extract strings using stored sizes
    for (int sz : sizes) {
        res.push_back(s.substr(i, sz));
        i += sz;
    }

    return res;
}

int main() {
    vector<string> input = {"leet", "code", "is", "fun"};

    // Encode the strings
    string encoded = encode(input);
    cout << "Encoded string: " << encoded << endl;

    // Decode the encoded string
    vector<string> decoded = decode(encoded);
    cout << "Decoded strings:" << endl;
    for (const string& s : decoded) {
        cout << s << endl;
    }

    return 0;
}
