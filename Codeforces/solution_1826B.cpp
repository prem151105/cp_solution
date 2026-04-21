#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        long long g = 0;

        for(int i=0;i<n/2;i++){
            g = __gcd(g, abs(a[i] - a[n-i-1]));
        }

        cout<<g<<endl;
    }
}