#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;

    const long long MOD = 1000000007;

    while(tc--){
        int n;
        cin>>n;

        vector<long long>a(n), b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<>());

        long long ans = 1;

        for(int i=0;i<n;i++){
            int num = a.size() - (upper_bound(a.begin(),a.end(),b[i]) - a.begin());
            ans = (ans * max(num - i, 0)) % MOD;
        }

        cout << ans << endl;
    }
}