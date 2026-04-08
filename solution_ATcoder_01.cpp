// Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_i
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<vector<double>>dp(n+1,vector<double>(n+1,0));
    // Here dp[i][j] is the probability of getting j heads in tossing from 0 to i coins
    // base case : dp[0][0]=1;
    // transition eqn : dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1-p[i-1])
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]*(1-p[i-1]);
            }else{
                dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1-p[i-1]);
            }
        }
    }
    double ans=0;
    for(int i=0;i<=n;i++){
        if(i>n/2){
            ans+=dp[n][i];
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}