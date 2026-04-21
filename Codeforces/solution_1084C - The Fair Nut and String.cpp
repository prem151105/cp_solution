#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    long long ans = 1;
    long long cnt = 0; // count of consecutive 'a'

    for (char c : s) {
        if (c == 'a') {
            cnt++;
        } 
        else if (c == 'b') {
            if (cnt > 0) {
                ans = (ans * (cnt + 1)) % MOD;
                cnt = 0;
            }
        }
        // ignore other characters
    }

    // last group of 'a'
    if (cnt > 0) {
        ans = (ans * (cnt + 1)) % MOD;
    }

    // remove empty sequence
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << endl;
}