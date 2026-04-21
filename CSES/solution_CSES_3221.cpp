#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    deque<pair<long long, int>> dq; 
    long long ans = 0;

    for (int i = 0; i < n; i++) {
       
        long long curr = x;

      
        while (!dq.empty() && dq.back().first >= curr) {
            dq.pop_back();
        }

        dq.push_back({curr, i});

       
        if (!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            ans ^= dq.front().first;
        }

       
        x = (a * x + b) % c;
    }

    cout << ans << "\n";
    return 0;
}