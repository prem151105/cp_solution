#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 40000;

bool ispalindrome(int x){
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> pal;
    for(int i = 1; i <= MAXN; i++){
        if(ispalindrome(i)) pal.push_back(i);
    }

    vector<int> dp(MAXN + 1, 0);
    dp[0] = 1;

    for(int p : pal){
        for(int j = p; j <= MAXN; j++){
            dp[j] = (dp[j] + dp[j - p]) % MOD;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}