#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }

    vector<int> dp(s + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){           // pick coin
        for(int j = s; j >= a[i]; j--){   // go backwards
            if(dp[j - a[i]]) {
                dp[j] = 1;
            }
        }
    }

    vector<int> ans;
    for(int i = 1; i <= s; i++){
        if(dp[i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
}