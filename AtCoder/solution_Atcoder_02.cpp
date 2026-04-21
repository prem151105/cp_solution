#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long W;
    cin >> n >> W;

    vector<int> w(n+1), v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    int maxV = 100000;

    vector<vector<long long>> dp(n+1, vector<long long>(maxV+1, 1e18));

    // base case
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= maxV; j++){
            // don't take
            dp[i][j] = dp[i-1][j];

            // take
            if(j >= v[i]){
                dp[i][j] = min(dp[i][j], dp[i-1][j - v[i]] + w[i]);
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= maxV; j++){
        if(dp[n][j] <= W){
            ans = j;
        }
    }

    cout << ans << "\n";
}