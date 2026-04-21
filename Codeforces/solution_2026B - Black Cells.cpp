#include <bits/stdc++.h>
using namespace std;

bool can(long long x, vector<long long>& a){
    int n = a.size();

    // even case
    if(n % 2 == 0){
        for(int i = 0; i < n; i += 2){
            if(a[i+1] - a[i] > x) return false;
        }
        return true;
    }

    // odd case: skip one element
    for(int skip = 0; skip < n; skip++){
        bool ok = true;
        vector<long long> b;

        for(int i = 0; i < n; i++){
            if(i != skip) b.push_back(a[i]);
        }

        for(int i = 0; i < (int)b.size(); i += 2){
            if(b[i+1] - b[i] > x){
                ok = false;
                break;
            }
        }

        if(ok) return true;
    }

    return false;
}

int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        long long l = 0, r = 1e18, ans = r;

        while(l <= r){
            long long mid = (l + r) / 2;

            if(can(mid, a)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}