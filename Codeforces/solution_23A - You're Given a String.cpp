#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Try lengths from largest to smallest
    for (int len = n - 1; len >= 1; len--) {
        unordered_map<string, int> freq;

        // Generate all substrings of length len
        for (int i = 0; i + len <= n; i++) {
            string sub = s.substr(i, len);
            freq[sub]++;
        }

        // Check if any substring appears at least twice
        for (auto &it : freq) {
            if (it.second >= 2) {
                cout << len << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}