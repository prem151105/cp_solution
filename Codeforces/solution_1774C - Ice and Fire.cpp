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

        int run = 1;  // length of current suffix of equal chars

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && s[i] == s[i - 1]) run++;
            else run = 1;

            int x = i + 2;              // number of players
            cout << x - run << " ";
        }
        cout << "\n";
    }
}