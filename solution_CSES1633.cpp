#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>dp(n+1,0);// Here dp[x] is the number of ways to reach x
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i && j<=6;j++){
            dp[i]+=dp[i-j];
        }
        dp[i]%=1000000007;
    }
    cout<<dp[n];
}