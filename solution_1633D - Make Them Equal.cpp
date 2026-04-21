#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXB = 1000;
    // precompuation for each number how many operations required to make it 1
    vector<int> op(MAXB + 1, 1e9);
    op[1] = 0;

    for (int i = 1; i <= MAXB; i++) {
        for (int x = 1; x <= i; x++) {
            int nxt = i + i / x;
            if (nxt <= MAXB) {
                op[nxt] = min(op[nxt], op[i] + 1);
            }
        }
    }
    // here i define dp[j] is the maximum number of coins i can get from first choosing some elmenets and using at most j cost
    // Transition Eqn :- dp[j]=max(dp[j],dp[j-cost[i]]+c[i]);
    // Base Case :- dp[j]=c[0] if j>=cost[0] else 0
    // Final Answer :- max(dp[k])
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n), c(n), cost(n);

        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        for (int i = 0; i < n; i++) {
            cost[i] = op[b[i]];
        }

        // ✅ 1D DP
        vector<int> dp(k + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = k; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + c[i]);
            }
        }

        cout << dp[k] << endl;
    }

    return 0;
}