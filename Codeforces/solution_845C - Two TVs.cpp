#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> events;

    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;

        events.push_back({l, 1});  // start
        events.push_back({r+1, -1});  // end also +1 (important!)
    }

    sort(events.begin(), events.end());

    int cur = 0;

    for(auto e : events){
        cur += e.second;
        if(cur > 2){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}