#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// ways[d] = number of digit triples (x,y,z) with 0<=x,y,z<=9 and x+y+z = d (i.e., no carry)
	vector<int> ways(10, 0);
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				// Only sums < 10 produce no carry at this digit
				if (i + j + k < 10) ways[i + j + k]++;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		string n;
		cin >> n; // read as string to access base-10 digits directly

		ll ans = 1;
		for (char ch : n) {
			// For each digit d of n, multiply by the number of no-carry triples summing to d
			ans *= ways[ch - '0'];
		}

		cout << ans << '\n';
	}

	return 0;
}

/*
Time Complexity (per test case): O(#digits of n) = O(log_10 n)
Space Complexity (per test case): O(1)
*/
