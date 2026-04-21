#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    // count number of 1s
    int ones = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 1) ones++;
    }

    // if already has 1s
    if(ones > 0){
        cout << n - ones << endl;
        return 0;
    }

    int ans = INT_MAX;

    unordered_map<int,int> prev, cur;

    for(int i=0;i<n;i++){
        cur.clear();

        cur[a[i]] = 1;

        for(auto it : prev){
            int g = __gcd(it.first, a[i]);
            if(cur.count(g))
                cur[g] = min(cur[g], it.second + 1);
            else
                cur[g] = it.second + 1;
        }

        if(cur.count(1)){
            ans = min(ans, cur[1]);
        }

        prev = cur;
    }

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans + n - 2 << endl;
}