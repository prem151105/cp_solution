#include <cstring>
#include <iostream>
#include <vector>
/* Intution is that we can use 3d dp to solve this problem
   dp[i][j][k] = total particles if there are i planes and starting age j and direction k
   where k = 0 means moving in positive direction and k = 1 means moving in negative direction
   Base Cases:
   dp[i][j][k] = 1 if j == 1
   dp[i][j][k] = 2 if i == 1
   Transition:
   dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][1-k] - 1
*/
using namespace std;

const int N = 1001;
const int K = 1001;

int n, k;
const int mod = 1e9 + 7;

int dp[N][K][2];

int solve(int curr, int k, int dir) {
    if (k == 1) {
        return 1;
    }

    if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2;  // me and my copy

    if (dir == 1) {
        if (curr < n)
            ans += solve(curr + 1, k, dir) - 1;

        ans %= mod;

        if (curr > 1)
            ans += solve(curr - 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1)
            ans += solve(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)
            ans += solve(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << endl;
    }
}