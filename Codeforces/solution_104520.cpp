#include <bits/stdc++.h>
using namespace std;

/*
===== EXPLANATION: =====
Since the mex must be x, the numbers in [1, x-1] must be in the subarray.
For the median to be x, we must have x+1 in the subarray, along with x-2 other numbers.
There are (n-x-1)C(x-2) ways to choose these other numbers.
Once we have chosen the subarray of size 2x-2, there are
(n-2x+3) * (n-2x+2)! * (2x-2)!
permutations that contain this subarray.
Thus, the answer for any n and x is
(n-x-1)C(x-2) * (n-2x+3) * (n-2x+2)! * (2x-2)!
*/

using ll = long long;

const ll mod = 998244353, maxn = 2e5 + 5;

ll fact[maxn], inv[maxn];

ll modexp(ll a, ll b){
	ll res = 1;
	while (b){
		if (b & 1){
			res *= a;
			res %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
	}
	return res;
}

ll choose(ll n, ll k){
	if (n < k) return 0;
	return fact[n] * inv[k] % mod * inv[n-k] % mod;
}

void precomp(){
	fact[0] = 1;
	for (int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * i) % mod;
	for (int i = 0; i < maxn; i++) inv[i] = modexp(fact[i], mod-2);
}

void solve(){
	ll n;
	cin >> n;

	// code
	for (ll i = 1; i <= n; i++){
		ll ans = (i == 1 || 2*i-1 > n) ? 0 : (choose(n-i-1, i-2) * (n-2*i+3) % mod * fact[n-2*i+2] % mod * fact[2*i-2] % mod);
		cout << ans << ' ';
	}
	cout << '\n';
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	precomp();
	int t;
	cin >> t;
	while (t--) solve();
}