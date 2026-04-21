#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,m;
    cin>>n>>m;

    unordered_map<int, vector<pair<int,int>>> mp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int s;
            cin>>s;
            mp[s].push_back({i+1,j+1});
        }
    }

    for(auto it : mp){

        int key = it.first;
        auto vec = it.second;

        int S = 0;

        for(int i=1;i<vec.size();i++){

            int r1 = vec[i-1].first;
            int c1 = vec[i-1].second;

            int r2 = vec[i].first;
            int c2 = vec[i].second;

            int d = abs(r1-r2) + abs(c1-c2);

            S += S+i*d;
        }

        cout<<S<<"\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}