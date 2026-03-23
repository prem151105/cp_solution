#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_set<int> exited;
    int i = 0, ans = 0;

    for (int j = 0; j < n; j++) {
        if (b[j] == a[i]) {
            i++;
            while (i < n && exited.count(a[i])) {
                i++;
            }
        } else {
            ans++;
        }
        exited.insert(b[j]);
    }

    cout << ans << endl;
}