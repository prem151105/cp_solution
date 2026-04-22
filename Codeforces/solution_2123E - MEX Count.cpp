#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> freq(n + 1, 0);
        for (int x : a) {
            if (x <= n) freq[x]++;
        }

        vector<int> ans(n + 2, 0);

        for (int m = 0; m <= n; m++) {
            int min_k = freq[m];
            int max_k = n - m;

            if (min_k <= max_k) {
                ans[min_k]++;
                ans[max_k + 1]--;
            }

           
            if (freq[m] == 0) break;
        }

        
        for (int i = 1; i <= n; i++) {
            ans[i] += ans[i - 1];
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}