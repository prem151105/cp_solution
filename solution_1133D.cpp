#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    map<pair<long long,long long>, int> cnt;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 0 && b[i] == 0){
            ans++;   // special case
            continue;
        }
        if(a[i] == 0) continue;

        long long x = -b[i];
        long long y = a[i];

        long long g = __gcd(abs(x), abs(y));
        x /= g;
        y /= g;

        // normalize sign
        if(y < 0){
            x = -x;
            y = -y;
        }

        cnt[{x, y}]++;
    }

    int mx = 0;
    for(auto &it : cnt){
        mx = max(mx, it.second);
    }

    cout << mx + ans << endl;
}