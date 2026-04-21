#include<bits/stdc++.h>
using namespace std;
int main(){
int n,x;
cin>>n>>x;
vector<int>a(n);
vector<int>b(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}
// here dp[i] is the maximum number of pages in the i amout of money
// Transition eqn : dp[i] = max(dp[i-1], dp[i-1]+b[i])
// final subproblem is where i=n and return dp[n]
vector<long long>dp(x+1,0);
for(int i=0;i<n;i++){
    for(int j=x;j>=a[i];j--){
        dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
    }
}
cout<<dp[x];
}