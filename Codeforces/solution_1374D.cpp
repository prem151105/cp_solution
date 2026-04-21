#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, k;
		cin >> n >> k;

		map<int, int> fr; // fr[delta] = count of elements needing this exact addition to become divisible by k
		int cnt = 0;      // number of elements not already divisible by k

		for (int i = 0; i < n; i++) {
				int temp;
				cin >> temp;
				if (temp % k) {                  // if not divisible by k
						fr[k - temp % k]++;        // delta needed to reach next multiple of k
						cnt++;
				}
		}

		if (cnt == 0) {                       // already all divisible
				cout << 0 << '\n';
				return;
		}

		int ma = 0;                            // max frequency of a particular delta
		int rem = 0;                           // the delta achieving that max
		for (auto [x, y] : fr) {
				// pick the delta with the highest frequency; on ties, pick the larger delta (<= ensures that)
				if (ma <= y) {
						ma = y;
						rem = x;
				}
		}

		// For a delta 'rem' appearing 'ma' times, required x values are:
		// rem, rem + k, rem + 2k, ..., rem + (ma - 1)k. The last needed x is rem + (ma - 1)k.
		// Number of moves equals last x + 1 (since x starts from 0 and we count moves).
		cout << 1LL * (ma - 1) * k + rem + 1 << '\n';
}

int main() {
		ios::sync_with_stdio(false); // faster I/O
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(logn)
*/
