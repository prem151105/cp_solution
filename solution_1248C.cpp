#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> f(n + 2);
    f[0] = 1;

    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * i) % m;

    long long ans = 0;

    for (int len = 1; len <= n; len++) {
        long long x = (n - len + 1);
        long long cur = (f[len] * f[n - len + 1]) % m;
        cur = (cur * x) % m;
        ans = (ans + cur) % m;
    }

    cout << ans << '\n';
}