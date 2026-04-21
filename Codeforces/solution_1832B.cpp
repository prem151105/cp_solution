#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n,k;
        cin>>n>>k;

        vector<long long>a(n);
        long long total=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            total+=a[i];
        }

        sort(a.begin(),a.end());

        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+a[i];
        }

        vector<long long> suf(n+1,0);
        for(int i=0;i<n;i++){
            suf[i+1]=suf[i]+a[n-1-i];
        }

        long long ans=0;

        for(int i=0;i<=k;i++){
            long long removed = pref[2*i] + suf[k-i];
            ans=max(ans,total-removed);
        }

        cout<<ans<<endl;
    }
}