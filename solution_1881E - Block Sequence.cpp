#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
       // here dp[i] is the minimum number of deletion required to make array from (i to n-1 ) beautiful
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> dp(n + 1, 0); // dp[n] = 0 already

        for(int i = n - 1; i >= 0; i--){
            // Option 1: delete
            dp[i] = 1 + dp[i + 1];

            // Option 2: keep and jump
            int jump = i + a[i] + 1;
            if(jump <= n){
                dp[i] = min(dp[i], dp[jump]);
            }
        }

        cout << dp[0] << "\n";
    }
}