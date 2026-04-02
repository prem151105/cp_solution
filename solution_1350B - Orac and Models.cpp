#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> s(n+1);
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }

        vector<int> dp(n+1, 1); // base: single element

        for(int i = 1; i <= n; i++){
            for(int j = 2*i; j <= n; j += i){
                if(s[i] < s[j]){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int ans = 1;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}