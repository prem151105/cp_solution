#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // pa[i] = a[0] + ... + a[i-1]
    vector<int64> pa(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pa[i + 1] = pa[i] + a[i];
    }

    // ppa[i] = pa[0] + pa[1] + ... + pa[i-1]
    vector<int64> ppa(n + 2, 0);
    for (int i = 0; i <= n; i++) {
        ppa[i + 1] = ppa[i] + pa[i];
    }

    // start[i] = total number of elements before block i
    // block i = subarray sums starting at index i (0-based)
    vector<int64> start(n + 1, 0);
    vector<int64> blockPref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        start[i + 1] = start[i] + (n - i);

        // Sum of full block i:
        // s(i,i) + s(i,i+1) + ... + s(i,n-1)
        int64 fullBlock = (ppa[n + 1] - ppa[i + 1]) - 1LL * (n - i) * pa[i];
        blockPref[i + 1] = blockPref[i] + fullBlock;
    }

    auto partialBlock = [&](int i, int len) -> int64 {
        // First len elements of block i:
        // s(i,i) + s(i,i+1) + ... + s(i,i+len-1)
        if (len <= 0) return 0;
        return (ppa[i + len + 1] - ppa[i + 1]) - 1LL * len * pa[i];
    };

    auto prefB = [&](int64 k) -> int64 {
        // sum of first k elements of b
        if (k <= 0) return 0;

        int64 pos = k - 1; // last included position in b, 0-based
        int idx = int(upper_bound(start.begin(), start.end(), pos) - start.begin()) - 1;

        int64 inside = pos - start[idx] + 1; // how many taken from block idx
        return blockPref[idx] + partialBlock(idx, (int)inside);
    };

    int q;
    cin >> q;
    while (q--) {
        int64 l, r;
        cin >> l >> r;
        cout << prefB(r) - prefB(l - 1) << '\n';
    }

    return 0;
}