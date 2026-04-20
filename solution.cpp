#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<int> closest(n);
        closest[0] = 1;
        closest[n-1] = n-2;

        for(int i=1;i<n-1;i++){
            if(a[i]-a[i-1] < a[i+1]-a[i]) closest[i]=i-1;
            else closest[i]=i+1;
        }

        // forward prefix
        vector<long long> pref(n,0);
        for(int i=0;i<n-1;i++){
            if(closest[i] == i+1) pref[i+1] = pref[i] + 1;
            else pref[i+1] = pref[i] + (a[i+1] - a[i]);
        }

        // backward prefix
        vector<long long> suf(n,0);
        for(int i=n-1;i>0;i--){
            if(closest[i] == i-1) suf[i-1] = suf[i] + 1;
            else suf[i-1] = suf[i] + (a[i] - a[i-1]);
        }

        int m;
        cin>>m;
        while(m--){
            int l,r;
            cin>>l>>r;
            l--; r--;

            if(l < r){
                cout << pref[r] - pref[l] << "\n";
            } else {
                cout << suf[r] - suf[l] << "\n";
            }
        }
    }
}