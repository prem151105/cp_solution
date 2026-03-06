#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        long long x;
        cin>>n>>x;

        vector<long long>a(n),b(n),c(n);

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];

        long long k = 0;

        for(int i=0;i<n;i++){
            if((a[i]|x)==x) k |= a[i];
            else break;
        }

        for(int i=0;i<n;i++){
            if((b[i]|x)==x) k |= b[i];
            else break;
        }

        for(int i=0;i<n;i++){
            if((c[i]|x)==x) k |= c[i];
            else break;
        }

        if(k==x) cout<<"Yes\n";
        else cout<<"No\n";
    }
}