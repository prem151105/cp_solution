#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pair<long long,long long>, int>> vp(n);

    for(int i = 0; i < n; i++){
        cin >> vp[i].first.first >> vp[i].first.second;
        vp[i].second = i + 1; // store original index (1-based)
    }

    // sort: l ascending, r descending
    sort(vp.begin(), vp.end(), [](auto &a, auto &b){
        if(a.first.first != b.first.first)
            return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    });

    long long max_r = vp[0].first.second;
    int idx = vp[0].second;

    for(int i = 1; i < n; i++){
        if(vp[i].first.second <= max_r){
            // found nested
            cout << vp[i].second << " " << idx << '\n';
            return 0;
        }
        else{
            max_r = vp[i].first.second;
            idx = vp[i].second;
        }
    }

    cout << "-1 -1\n";
}