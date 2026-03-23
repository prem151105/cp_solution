#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int t=n-k+1;
    long long s=0,ans=0;

    for(int i=0;i<k;i++) s+=a[i];
    ans=s;

    for(int i=1;i<t;i++){
        s=s-a[i-1]+a[i+k-1];
        ans+=s;
    }

    double f=(double)ans/t;
    cout<<fixed<<setprecision(10)<<f;
}