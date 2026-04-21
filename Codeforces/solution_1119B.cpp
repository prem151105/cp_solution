#include <bits/stdc++.h>
using namespace std;

bool func(vector<int>& a, int k, int h) {
    vector<int> d(a.begin(), a.begin() + k);
    sort(d.begin(), d.end());

    long long total = 0;

    for(int i = k - 1; i >= 0; i -= 2) {
        total += d[i];
    }

    return total <= h;
}

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = n, ans = 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(func(a, mid, h)) {
            ans = mid;
            l = mid + 1;   
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}