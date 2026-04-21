#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) cin >> a[i]; // a[i] = 1 if hard, 0 if easy

		// dp[i][turn]: minimum skips needed from position i to end
		// turn = 1 -> friend's turn (he pays for hard bosses)
		// turn = 0 -> your turn (you pay nothing)
		vector<vector<int>> dp(n + 1, vector<int>(2, 0));

		// Base cases when there are no bosses left
		dp[n][0] = 0;
		dp[n][1] = 0;
		// When exactly one boss left (i = n - 1)
		dp[n - 1][0] = 0;                  // your turn: you can kill it for free
		dp[n - 1][1] = a[n - 1];           // friend's turn: pay 1 if it's hard

		for (int i = n - 2; i >= 0; i--) {
			// Your turn: kill 1 or 2 bosses for free, then it's friend's turn
			dp[i][0] = min(dp[i + 1][1], dp[i + 2][1]);
			// Friend's turn: he kills 1 or 2 bosses and pays for each hard one
			dp[i][1] = min(
				dp[i + 1][0] + a[i],                // friend kills a[i]
				dp[i + 2][0] + a[i] + a[i + 1]      // friend kills a[i] and a[i+1]
			);
		}

		cout << dp[0][1] << '\n'; // Start at index 0 with friend's turn
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
			solve();
		}

		return 0;
}
