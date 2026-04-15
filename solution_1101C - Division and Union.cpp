#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;

		vector<vector<int>> a(n); // each element is {l, r, original_index}
		for (int i = 0; i < n; i++) {
				int l, r;
				cin >> l >> r;
				a[i] = {l, r, i}; // store segment along with its original position
		}

		sort(a.begin(), a.end()); // sort by l, then r, then index (default lexicographical)

		vector<int> ans(n, 2); // default all segments to group 2
		int mx = a[0][1];      // rightmost endpoint of the current merged prefix (group 1)
		bool split_found = false; // becomes true once we find a gap to split groups

		for (int i = 0; i < n; i++) {
				if (a[i][0] > mx) {      // found a gap: next segment starts after current coverage
						split_found = true;  // we can split here: prefix in group 1, rest in group 2
						break;               // remaining segments stay as group 2 (already set)
				}
				ans[a[i][2]] = 1;        // assign this segment (by original index) to group 1
				mx = max(mx, a[i][1]);   // extend coverage with this segment's right end
		}

		if (!split_found) {
				cout << "-1\n"; // no gap means all segments intersect in a chain; impossible to split
		} else {
				for (auto v : ans) cout << v << ' '; // print groups in the original input order
				cout << '\n';
		}
}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}

		return 0;
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
