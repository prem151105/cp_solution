
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    // dp[len][x] = number of sequences of length len ending at x
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
 
    // Base case: length = 1
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
 
    // Build DP
    for (int len = 2; len <= k; len++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                dp[len][j] = (dp[len][j] + dp[len - 1][i]) % MOD;
            }
        }
    }
 
    // Final answer = sum of sequences of length k
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[k][i]) % MOD;
    }
 
    cout << ans << "\n";
    return 0;
}