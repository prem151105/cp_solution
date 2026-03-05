/*Intution min(
   dist(a,b),
   dist(a,nearest_major) + dist(b,nearest_major)
)*/
// TC :- O(k)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n,k,a,b;
        cin >> n >> k >> a >> b;

        vector<pair<long long,long long>> vp(n);

        for(int i = 0; i < n; i++){
            cin >> vp[i].first >> vp[i].second;
        }

        long long direct = abs(vp[a-1].first - vp[b-1].first) 
                         + abs(vp[a-1].second - vp[b-1].second);

        long long lenA = 1e18, lenB = 1e18;

        for(int i = 0; i < k; i++){
            lenA = min(lenA, abs(vp[a-1].first - vp[i].first) 
                             + abs(vp[a-1].second - vp[i].second));
        }

        for(int i = 0; i < k; i++){
            lenB = min(lenB, abs(vp[b-1].first - vp[i].first) 
                             + abs(vp[b-1].second - vp[i].second));
        }

        long long ans;

        if(k == 0) ans = direct;
        else ans = min(direct, lenA + lenB);

        cout << ans << endl;
    }
}