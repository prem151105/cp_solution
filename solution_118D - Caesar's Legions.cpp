#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int dp[105][105][2];

int main(){
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    dp[0][0][0] = dp[0][0][1] = 1;

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){

            // place 0 (footman)
            for(int x=1; x<=k1 && i-x>=0; x++){
                dp[i][j][0] = (dp[i][j][0] + dp[i-x][j][1]) % MOD;
            }

            // place 1 (horseman)
            for(int x=1; x<=k2 && j-x>=0; x++){
                dp[i][j][1] = (dp[i][j][1] + dp[i][j-x][0]) % MOD;
            }
        }
    }

    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;
}