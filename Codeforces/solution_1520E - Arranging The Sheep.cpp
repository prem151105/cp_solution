#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        vector<long long> pos;
 
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                pos.push_back(i);
            }
        }
 
        int k = pos.size();
 
        if (k <= 1) {
            cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < k; i++) {
            pos[i] -= i;
        }
 
        long long median = pos[k / 2];
 
        long long moves = 0;
        for (int i = 0; i < k; i++) {
            moves += abs(pos[i] - median);
        }
 
        cout << moves << '\n';
    }
 
    return 0;
}