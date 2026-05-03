#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int mn = 0, mx = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '0') {
                i++;
                continue;
            }

            int ones = 0;   // total 1's in this group
            int runs = 0;   // number of blocks of consecutive 1's
            int span = 0;   // length after filling single-zero gaps

            while (true) {
                runs++;

                while (i < n && s[i] == '1') {
                    ones++;
                    span++;
                    i++;
                }

                int z = 0;
                int j = i;
                while (j < n && s[j] == '0') {
                    z++;
                    j++;
                }

                if (z == 1 && j < n && s[j] == '1') {
                    span++;   // that single zero can be turned into 1
                    i = j;    // continue with next 1-block
                } else {
                    i = j;    // stop this group
                    break;
                }
            }

            mn += (ones + runs + 1) / 2;
            mx += span;
        }

        cout << mn << " " << mx << '\n';
    }
}