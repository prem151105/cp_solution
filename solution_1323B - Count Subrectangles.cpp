#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n), b(m);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		// fa[len] and fb[len] will finally store the number of all-ones subarrays of exact length 'len'
		vector<int> fa(n + 1, 0), fb(m + 1, 0);

		// Build frequency by current run-lengths for array a
		// For each 1, increase current run length c and increment fa[c]
		// Later suffix-sum will convert these into counts of exact-length segments
		int c = 0;
		for (int i = 0; i < n; i++) {
				if (a[i] == 1) {
						c++;
						fa[c]++;
				} else {
						c = 0;
				}
		}

		// Same for array b
		c = 0;
		for (int i = 0; i < m; i++) {
				if (b[i] == 1) {
						c++;
						fb[c]++;
				} else {
						c = 0;
				}
		}

		// Suffix accumulation: after this, fa[i] equals the total number of all-ones subarrays of exact length i
		// Intuition: each run of length L contributed 1 to fa[1..L]; suffix sums turn that into (L - i + 1)
		for (int i = n - 1; i > 0; i--) fa[i] += fa[i + 1];
		for (int i = m - 1; i > 0; i--) fb[i] += fb[i + 1];

		long long ans = 0;
		// Enumerate all factor pairs (i, j) of k -> rectangle dimensions i x j
		for (int i = 1; i * i <= k; i++) {
				if (k % i == 0) {
						int j = k / i;
						// Choose i consecutive rows of ones and j consecutive columns of ones
						if (i <= n && j <= m) ans += fa[i] * fb[j];
						// If i != j, also count the swapped orientation (j rows, i columns)
						if (i != j && j <= n && i <= m) ans += fa[j] * fb[i];
				}
		}

		cout << ans << '\n';
		return 0;
}

/*
Time Complexity (TC): O(n + m + sqrt(k))
Space Complexity (SC): O(n + m)
*/
