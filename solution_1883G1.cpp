#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool canMatchK(const vector<ll>& a, const vector<ll>& b, int k) {
    int i = 0, j = 0, cnt = 0;
    int n = a.size();
 
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            cnt++;
            i++;
            j++;
            if (cnt == k) return true;
        } else {
            j++;  // try a larger b
        }
    }
    return cnt >= k;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;  // m = 1 in easy version
 
        vector<ll> a(n);
        a[0] = 1;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
 
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        int low = 0, high = n, best = 0;
 
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canMatchK(a, b, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
 
        cout << n - best << '\n';
    }
    return 0;
}