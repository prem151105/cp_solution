#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if ((i & (n - 1 - i)) == 0) {
            ans ^= a[i];
        }
    }

    cout << ans << endl;
}