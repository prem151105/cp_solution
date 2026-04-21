#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    // here dp[x] is the number of ways to make sum x
    // Transition eqn : dp[x] =sum(dp[x-coins[j]]) for all j where x-coins[j]>=0
    // final subproblem is where i=x  and return dp[x]
    const long long MOD = 1e9+7;
    vector<long long> dp(x+1, 0);

    dp[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    if(dp[x] != 0) cout << dp[x];
    else cout << 0;
}