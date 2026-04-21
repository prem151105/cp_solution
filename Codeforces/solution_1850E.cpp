#include <bits/stdc++.h>
using namespace std;

bool check(long long w, vector<long long> &p, long long c){
    long long s = 0;

    for(int i = 0; i < p.size(); i++){
        long long x = p[i] + 2*w;
        s += x * x;

        if(s > c) return false;
    }

    return s == c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        long long n, c;
        cin >> n >> c;

        vector<long long> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        long long l = 0, r = 1e9;
        long long ans = 0;

        while(l <= r){
            long long mid = (l + r) / 2;

            if(check(mid, p, c)){
                ans = mid;
                break;
            }

            long long s = 0;
            for(int i = 0; i < n; i++){
                long long x = p[i] + 2*mid;
                s += x*x;
                if(s > c) break;
            }

            if(s > c) r = mid - 1;
            else l = mid + 1;
        }

        cout << ans << "\n";
    }
}