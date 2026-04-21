#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;

    vector<int>a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // dp[rem][prev]
    vector<vector<ll>> dp(k+1, vector<ll>(n, INF)), newdp;

    dp[0][0] = 0;

    for(int i = 1; i < n; i++){

        newdp.assign(k+1, vector<ll>(n, INF));

        for(int rem = 0; rem <= k; rem++){
            for(int p = 0; p < i; p++){

                if(dp[rem][p] == INF) continue;

                // 1️⃣ delete i
                if(rem + 1 <= k){
                    newdp[rem+1][p] = min(newdp[rem+1][p], dp[rem][p]);
                }

                // 2️⃣ keep i
                ll cost = 1LL * b[p] * (a[i] - a[p]);

                newdp[rem][i] = min(newdp[rem][i],
                                   dp[rem][p] + cost);
            }
        }

        dp = newdp;
    }

    ll ans = INF;

    for(int rem = 0; rem <= k; rem++){
        for(int p = 0; p < n; p++){
            if(dp[rem][p] == INF) continue;

            ans = min(ans,
                dp[rem][p] + 1LL * b[p] * (l - a[p]));
        }
    }

    cout << ans << '\n';
}