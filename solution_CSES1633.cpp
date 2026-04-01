#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = 0;
    for (int i = 1; i <= 6; i++) {
        dp[n] += solve(n - i, dp);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int k = solve(n, dp);
    cout << k << endl;
}
