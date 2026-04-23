#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        vector<ll> a(n), r(n);
        for (auto &i : a) cin >> i;
        for (auto &i : r) cin >> i;

        map<ll, vector<pair<ll,ll>>> mp;

        auto isqrt = [&](ll x) {
            ll v = sqrtl(x);
            while ((v+1)*(v+1) <= x) v++;
            while (v*v > x) v--;
            return v;
        };

        for(int i = 0; i < n; i++) {
            ll aa = a[i], rr = r[i];
            for(ll x = aa - rr; x <= aa + rr; x++) {
                ll d = isqrt(rr*rr - (x-aa)*(x-aa));
                mp[x].push_back({-d, d});
            }
        }

        ll ans = 0;

        for(auto &[x, vec] : mp) {
            sort(vec.begin(), vec.end());

            ll L = vec[0].first, R = vec[0].second;

            for(int i = 1; i < vec.size(); i++) {
                if(vec[i].first <= R + 1) {
                    R = max(R, vec[i].second);
                } else {
                    ans += (R - L + 1);
                    L = vec[i].first;
                    R = vec[i].second;
                }
            }
            ans += (R - L + 1);
        }

        cout << ans << "\n";
    }
}