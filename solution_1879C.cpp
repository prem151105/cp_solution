#include<bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;

        int n = s.length();

        long long min_deletions = 0;
        long long ways = 1;

        int c = 1; // current group length

        for(int i = 1; i <= n; i++){
            if(i < n && s[i] == s[i-1]){
                c++;
            }
            else{
                // same logic as correct code
                min_deletions += (c - 1);
                ways = (ways * c) % MOD;
                c = 1;
            }
        }

        // multiply by factorial(min_deletions)
        long long fact = 1;
        for(int i = 1; i <= min_deletions; i++){
            fact = (fact * i) % MOD;
        }

        long long ans2 = (ways * fact) % MOD;

        cout << min_deletions << " " << ans2 << endl;
    }
}