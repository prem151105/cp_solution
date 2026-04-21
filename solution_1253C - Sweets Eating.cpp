#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    vector<long long>pref(n);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }

    vector<long long>dp(n,0);

    for(int i=0;i<n;i++){
        dp[i] = pref[i];
        if(i >= m){
            dp[i] += dp[i-m];
        }
    }

    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return 0;
}