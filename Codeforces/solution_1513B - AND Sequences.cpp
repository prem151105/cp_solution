#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
const int N = 2e5 + 5;
 
long long fact[N];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    // precompute factorial
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
 
        // compute global AND
        int global_and = a[0];
        for(int i = 1; i < n; i++){
            global_and &= a[i];
        }
 
        // count elements equal to global AND
        int k = 0;
        for(int x : a){
            if(x == global_and) k++;
        }
 
        if(k < 2){
            cout << 0 << "\n";
            continue;
        }
 
        long long ans = (1LL * k * (k - 1)) % MOD;
        ans = (ans * fact[n - 2]) % MOD;
 
        cout << ans << "\n";
    }
}