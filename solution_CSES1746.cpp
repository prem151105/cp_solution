#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(m+2, 0));

    // Base case
    if(a[0] == 0){
        for(int x = 1; x <= m; x++){
            dp[0][x] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }

    // Fill DP
    for(int i = 1; i < n; i++){
        for(int x = 1; x <= m; x++){
            if(a[i] != 0 && a[i] != x) continue;

            dp[i][x] = dp[i-1][x];
            if(x > 1) dp[i][x] = (dp[i][x] + dp[i-1][x-1]) % MOD;
            if(x < m) dp[i][x] = (dp[i][x] + dp[i-1][x+1]) % MOD;
        }
    }

    // Final answer
    int ans = 0;
    for(int x = 1; x <= m; x++){
        ans = (ans + dp[n-1][x]) % MOD;
    }

    cout << ans << "\n";
}