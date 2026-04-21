#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    const long long INF = 1e18;
    vector<long long> dp(x+1, INF);

    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INF){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if(dp[x] != INF) cout << dp[x];
    else cout << -1;
}