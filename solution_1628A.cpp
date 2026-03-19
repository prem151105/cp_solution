#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Step 1: Compute suffix MEX
        vector<int> suf_mex(n);
        vector<int> freq(n + 5, 0);

        int mex = 0;
        for (int i = n - 1; i >= 0; i--) {
            freq[a[i]]++;
            while (freq[mex] > 0) mex++;
            suf_mex[i] = mex;
        }

        // Step 2: Greedy splitting
        vector<int> result;
        int i = 0;

        while (i < n) {
            int target_mex = suf_mex[i];

            vector<int> seen(target_mex + 5, 0);
            int cur_mex = 0;

            int j = i;
            while (j < n) {
                if (a[j] <= target_mex)
                    seen[a[j]]++;

                while (seen[cur_mex] > 0) cur_mex++;

                if (cur_mex == target_mex) break;
                j++;
            }

            result.push_back(target_mex);
            i = j + 1;
        }

        // Output
        cout << result.size() << "\n";
        for (int x : result) cout << x << " ";
        cout << "\n";
    }

    return 0;
}