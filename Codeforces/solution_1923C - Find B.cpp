#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<long long> prefSum(n+1,0);
        vector<int> pref1(n+1,0);

        for(int i=0;i<n;i++){
            prefSum[i+1] = prefSum[i] + a[i];
            pref1[i+1] = pref1[i] + (a[i] == 1);
        }

        while(q--){
            int l,r;
            cin>>l>>r;   //  (removed k)
            l--; r--;

            int len = r - l + 1;

            if(len == 1){
                cout<<"NO\n";
                continue;
            }

            long long sum = prefSum[r+1] - prefSum[l];
            int ones = pref1[r+1] - pref1[l];

            if(sum - len >= ones) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}