#include<bits/stdc++.h>
using namespace std;

void solve(){
     int n; cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        long long a=v[0],b=v[n-1];
        long long deno=1LL*n*n-1;
        if(abs(n*a-b)%deno!=0){
            cout<<"NO"<<endl;
            return;
        }
        long long y=(n*a-b)/deno;
        long long x=a-n*y;
        if(x<0 || y<0){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            long long check=x*(i+1)+y*(n-i);
            if(check!=v[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
       solve();
    }
}