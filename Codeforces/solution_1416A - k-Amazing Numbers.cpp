#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) cin >> i; // read the array

		vector<vector<int>> pos(n + 1); // pos[x] stores 0-based indices where value x occurs
		for (int i = 0; i < n; i++) {
				pos[a[i]].push_back(i);
		}

		vector<int> ans(n, -1); // ans[k-1] will be the k-amazing number, -1 if none
		for (int i = 1; i <= n; i++) {
				if (pos[i].empty()) continue; // value i doesn't appear in the array

				// Compute the maximum gap between consecutive occurrences of i,
				// considering virtual boundaries before the array start and after the end.
				int mx = pos[i][0] + 1; // gap from start (index -1) to first occurrence
				for (int j = 1; j < (int)pos[i].size(); j++) {
						mx = max(mx, pos[i][j] - pos[i][j - 1]); // largest gap between consecutive positions
				}
				mx = max(mx, n - pos[i].back()); // gap from last occurrence to the end (index n)

				// For all k >= mx, value i appears in every subarray of length k.
				// Fill answers from position mx-1 onward until we hit an already set value
				// to ensure the minimal value is kept.
				for (int j = mx - 1; j < n; j++) {
						if (ans[j] != -1) break; // already filled by a smaller value
						ans[j] = i;
				}
		}

		for (auto i : ans) cout << i << ' ';
		cout << '\n';
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
