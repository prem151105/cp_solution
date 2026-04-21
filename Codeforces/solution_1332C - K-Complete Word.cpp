#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int ans = 0;

    for(int i = 0; i < (k+1)/2; i++){
        map<char,int> mp;
        int total = 0;

        for(int j = i; j < n; j += k){
            mp[s[j]]++;
            total++;
        }

        if(i != k - i - 1){
            for(int j = k - i - 1; j < n; j += k){
                mp[s[j]]++;
                total++;
            }
        }

        int mx = 0;
        for(auto it : mp){
            mx = max(mx, it.second);
        }

        ans += total - mx;
    }

    cout << ans << endl;
    }
}