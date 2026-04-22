#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int>a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int>c(n);
    long long s = 0;

   
    for(int i=0;i<n;i++){
        c[i] = a[i]/b[i];
        s += c[i];
    }

   
    if(s < k){
        for(int i=0;i<n;i++) cout<<0<<" ";
        cout<<endl;
        return 0;
    }

    vector<int>ans(n,0);

    for(int i=n-1;i>=0;i--){
        if(k > 0){
            int take = min(c[i], k);
            ans[i] = take;
            k -= take;
        } else {
            ans[i] = 0;
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}