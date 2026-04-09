#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    vector<long long> fact;

    // precompute factorials up to 1e12
    long long f = 1;
    for(int i = 1; i <= 15; i++){
        f *= i;
        fact.push_back(f);
    }

    while(tc--){
        long long n;
        cin >> n;

        int ans = 60;

        int m = fact.size();

        // try all subsets of factorials
        for(int mask = 0; mask < (1 << m); mask++){
            long long sum = 0;
            int cnt = 0;

            for(int i = 0; i < m; i++){
                if(mask & (1 << i)){
                    sum += fact[i];
                    cnt++;
                }
            }

            if(sum > n) continue;

            long long remaining = n - sum;

            // count powers of 2 needed = number of set bits
            cnt += __builtin_popcountll(remaining);

            ans = min(ans, cnt);
        }

        cout << ans << "\n";
    }
}