#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> cnt(10, 0);
    for (char c : s) cnt[c - '0']++;

    // remove one 1,6,8,9
    cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;

    string res = "";

    // build number without zeros first
    for (int d = 1; d <= 9; d++) {
        while (cnt[d]--) res += (char)(d + '0');
    }

    int rem = 0;
    for (char c : res) {
        rem = (rem * 10 + (c - '0')) % 7;
    }

    int need = (7 - (rem * 4 % 7)) % 7;

    vector<string> perm = {
        "1869", "1968", "1689", "6198",
        "1698", "1986", "1896"
    };

    res += perm[need];

    // add zeros at end
    while (cnt[0]--) res += '0';

    cout << res << endl;
}